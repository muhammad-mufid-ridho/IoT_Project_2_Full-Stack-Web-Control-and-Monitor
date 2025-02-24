const serverUrl = "https://backend-iot-project-2.onrender.com/led-status";

function controlLED(state) {
    fetch(serverUrl, {
        method: "POST",
        headers: { "Content-Type": "application/json" },
        body: JSON.stringify({ status: state })
    })
    .then(response => response.json())
    .then(data => {
        console.log(data);
        updateLEDStatus(data.status);
    })
    .catch(error => console.error("Error:", error));
}

function checkLEDStatus() {
    fetch(serverUrl)
    .then(response => response.json())
    .then(data => {
        updateLEDStatus(data.status);
    })
    .catch(error => console.error("Error:", error));
}

function updateLEDStatus(status) {
  const statusElement = document.getElementById("status");
  if(status == 'ON') {
    statusElement.innerHTML = '<i class="bi bi-lightbulb-fill lamp" style="color: yellow;"></i>';
  }
  else if(status == 'OFF') {
    statusElement.innerHTML = '<i class="bi bi-lightbulb-fill lamp" style="color: white;"></i>';
  }
}

setInterval(checkLEDStatus, 1000); // Perbarui status LED setiap 1 detik