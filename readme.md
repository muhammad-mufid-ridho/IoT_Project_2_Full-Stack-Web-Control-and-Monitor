# 🔌 Wemos D1 R1 LED Control via Web (Render & Wokwi) 💡

## 📝 Deskripsi Proyek
Proyek ini memungkinkan pengontrolan LED pada Wemos D1 R1 secara jarak jauh melalui web tanpa harus berada dalam jaringan WiFi yang sama. Backend di-deploy menggunakan Render, dan Wemos D1 R1 dikonfigurasi dengan Wokwi untuk simulasi.

## 🔄 Alur Kerja (Fullstack)
### 1. **Frontend (Web Interface) 🌐**
   - Dibuat menggunakan HTML, CSS, dan JavaScript.
   - Menyediakan tombol untuk menyalakan dan mematikan LED.
   - Mengirim permintaan HTTP ke backend untuk mengontrol LED.

### 2. **Backend (Server) 🖥️**
   - Dibuat menggunakan Node.js dan Express.
   - Menyediakan endpoint API untuk mengatur status LED.
   - Menyimpan status LED dan mengirimkan respons ke frontend dan perangkat Wemos D1 R1.
   - Dideploy di Render agar dapat diakses dari internet.

### 3. **Hardware (Wemos D1 R1) ⚡**
   - Terhubung ke WiFi dan melakukan request ke backend.
   - Membaca status LED dari server dan menyesuaikan output LED.

### 4. **Pengujian & Debugging 🛠️**
   - Menggunakan Wokwi untuk mensimulasikan Wemos D1 R1.
   - Memastikan server dapat menerima dan merespons request dengan benar.

## 📌 Langkah-Langkah Implementasi
### 1. Setup Backend di Render 🏗️
- Upload kode backend ke GitHub.
- Buat layanan web di Render dengan pengaturan:
  - Root Directory: `Back-end` (jika menggunakan struktur folder ini).
  - Build Command: `npm install`
  - Start Command: `node server.js`
- Deploy dan catat URL backend.

### 2. Konfigurasi Wemos D1 R1 di Wokwi 🔧
- Gunakan jaringan WiFi `Wokwi-GUEST`.
- Pastikan Wemos D1 R1 dapat mengambil status LED dari server.

### 3. Uji Coba ✅
- Cek backend melalui browser (`https://backend-url.onrender.com`).
- Jalankan simulasi di Wokwi dan pastikan LED merespons perubahan status.
- Gunakan console log dan Serial Monitor untuk debugging.

## ℹ️ Catatan Tambahan
- Pastikan backend berjalan di port 3000 atau sesuaikan dengan kebutuhan.
- Gunakan `Serial Monitor` untuk debugging Wemos D1 R1.

## 📚 Sumber Daya Tambahan
- [Render Deployment Docs](https://render.com/docs)
- [Wokwi Simulator](https://wokwi.com/)

