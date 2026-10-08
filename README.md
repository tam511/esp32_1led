# ESP32 OneButton - Điều khiển 1 LED bằng Nút nhấn


---

## 1. Sơ đồ kết nối phần cứng (Hardware Setup)

- **Vi điều khiển:** ESP32 Dev Module
- **Đèn LED:** Chân **GPIO2** (Built-in LED trên bo mạch ESP32)
- **Nút nhấn (Button):** Chân **GPIO4** (D4) — Kết nối cấu hình Active LOW (dùng trở kéo nội bộ `INPUT_PULLUP`).

---

## 2. Nguyên lý hoạt động (Software Logic)

Chương trình xử lý các sự kiện nút bấm từ thư viện `OneButton`:

- **Nhấn đơn (Single Click):** Bật hoặc Tắt (ON/OFF) đèn LED.
- **Nhấn kép (Double Click):** Chuyển đổi trạng thái đèn LED sang chế độ nhấp nháy (chu kỳ 200ms)

---

