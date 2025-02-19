
    // Buat koneksi WebSocket ke server
    const socket = new WebSocket('ws://localhost:8080');

    // Ketika koneksi dibuka
    socket.onopen = () => {
      console.log('Connected to WebSocket server');
    };

    // Ketika menerima data dari WebSocket
    socket.onmessage = (event) => {
      const data = JSON.parse(event.data);
      const temperature = data.temperature;
      const humidity = data.humidity;

      // Update tampilan suhu dan kelembaban
      document.getElementById('temperature').innerText = 'Temperature: ' + temperature + '°C';
      document.getElementById('humidity').innerText = 'Humidity: ' + humidity + '%';
    };

    // Ketika koneksi WebSocket ditutup
    socket.onclose = () => {
      console.log('Disconnected from WebSocket server');
    };