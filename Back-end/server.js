const express = require("express");
const cors = require("cors");

const app = express();
app.use(cors()); // Izinkan request dari ESP32
app.use(express.json()); // Parsing JSON body

let ledStatus = "OFF"; // Status awal LED

// Endpoint untuk mendapatkan status LED
app.get("/led-status", (req, res) => {
    res.json({ status: ledStatus });
});

// Endpoint untuk mengubah status LED
app.post("/led-status", (req, res) => {
    const { status } = req.body;
    if (status === "ON" || status === "OFF") {
        ledStatus = status;
        res.json({ message: `LED ${status}` });
    } else {
        res.status(400).json({ error: "Status harus 'ON' atau 'OFF'" });
    }
});

const PORT = process.env.PORT || 3000;
app.listen(PORT, () => console.log(`Server berjalan di port ${PORT}`));
