const express = require("express");
const cors = require("cors");

const app = express();
app.use(cors());
app.use(express.json());

let ledStatus = "OFF"; // Status awal LED

// API untuk mengubah status LED
app.post("/api/led", (req, res) => {
    ledStatus = req.body.status;
    console.log("LED Status:", ledStatus);
    res.json({ message: "Status LED diperbarui", status: ledStatus });
});

// API untuk mendapatkan status LED
app.get("/api/led", (req, res) => {
    res.json({ status: ledStatus });
});

// Menjalankan server di port 3000
const PORT = 3000;
app.listen(PORT, () => console.log(`Server berjalan di port ${PORT}`));
