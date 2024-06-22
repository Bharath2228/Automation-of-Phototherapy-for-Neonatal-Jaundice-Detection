# Jaundice Detection and Notification System

This project utilizes computer vision techniques to detect jaundice in captured images or video feed from a webcam. It then sends notifications via SMS using Twilio and controls an external device (via serial communication) based on the detection results.

## Introduction

Jaundice is a common condition characterized by yellowing of the skin and eyes due to elevated bilirubin levels in the blood. Early detection is crucial for timely medical intervention. This system aims to automate the detection process and provide prompt notifications.

## Features

- **Skin Detection:** Utilizes the YCrCb color space for skin detection.
- **Contour Analysis:** Identifies potential jaundice symptoms based on contour analysis.
- **Real-time Analysis:** Monitors live webcam feed for immediate detection.
- **SMS Notifications:** Sends notifications to specified recipients via Twilio.
- **External Device Control:** Controls an external device (e.g., LED) based on detection results using serial communication.

## Prerequisites

- Python 3.x
- OpenCV (`pip install opencv-python`)
- NumPy (`pip install numpy`)
- cvzone (`pip install cvzone`)
- Twilio (`pip install twilio`)

Ensure you have a webcam connected and properly configured. You'll also need valid Twilio API credentials for SMS notifications and a compatible serial device for external control.

## Installation

1. **Clone the repository:**
   ```bash
   git clone https://github.com/Bharath2228/Automation-of-Phototherapy-for-Neonatal-Jaundice-Detection.git
   cd Automation-of-Phototherapy-for-Neonatal-Jaundice-Detection
   ```

2. **Configure Twilio API credentials:**
   - Sign up for Twilio and obtain your Account SID, Auth Token, and Twilio phone number.
   - Replace placeholders (`# twilio Account ID`, `# Authorization Token`, `from_='----------'`, `to='----------'`) with your actual Twilio credentials in `jaundice_detection.py`.

3. **Configure serial communication:**
   - Modify the `port` in `e.port = "COM9"` to match your serial port.
   - Adjust baudrate (`e.baudrate = 115200`) if required.

## Usage

1. **Run the script:**
   ```bash
   python main.py
   ```

2. **Operating Instructions:**
   - Position the webcam to capture the subject's face adequately.
   - Ensure sufficient lighting for accurate skin detection.
   - Monitor console for detection results and status updates.
   - Respond to SMS notifications sent by the script.

## Troubleshooting

- **Webcam not detected:** Check webcam connections and drivers.
- **Twilio credentials incorrect:** Verify Twilio Account SID, Auth Token, and phone numbers.
- **Serial communication issues:** Ensure correct port and baudrate settings.

## Additional Notes

- Adjust threshold values (`np.average(B) < 110` and `np.average(Cb) < 110`) for optimal jaundice detection in varying lighting conditions.
- Ensure proper setup and functionality of external devices for controlled actions.
