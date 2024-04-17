import cv2
import numpy as np
import time
min_YCrCb = np.array([0,133,77],np.uint8)

max_YCrCb = np.array([255,173,127],np.uint8)



#--------------------------------------------Code----------------------------------------------------
#To quit from while loop
sourceImage = cv2.imread('6.jpg')
#cv2.imshow('original',sourceImage)

imageYCrCb = cv2.cvtColor(sourceImage,cv2.COLOR_BGR2YCR_CB)

#Image Converted From rgb to YCrCb

#cv2.imshow('fromRGB2YCrCb',imageYCrCb)

# Using inrange function to detect skinregion by giving max and min value of YCrCb
skinRegion = cv2.inRange(imageYCrCb,min_YCrCb,max_YCrCb)

#Morphology

# se = np.ones((1,1), dtype='uint8')
# image_close = cv2.morphologyEx(skinRegion, cv2.MORPH_CLOSE, se)
# cv2.imshow('Morphology', image_close)
#

# Do contour detection on skin region
contours, hierarchy = cv2.findContours(skinRegion, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

# Draw the contour on the image
for i, c in enumerate(contours):
    area = cv2.contourArea(c)
    if area > 1000:
        cv2.drawContours(sourceImage, contours, i, (0, 255, 0), 3)
        cv2.drawContours(skinRegion, contours, i, (0, 255, 0), 3)

#inorder to check for jaundice (but by putting thr ycrcb value and not the extracted skin value)
#its working even without skinregion but wont be efficient in real time processing
# image = cv2.cvtColor(imageYCrCb,cv2.COLOR_RGB2YCrCb)
toRGB = cv2.cvtColor(imageYCrCb,cv2.COLOR_YCrCb2RGB)
#cv2.imshow('rgb', toRGB)
reqd_image = cv2.bitwise_and(toRGB, toRGB, mask=skinRegion)
cv2.imshow('final_image', reqd_image)



R,G,B = cv2.split(toRGB)
#print (contours)


print("Blue color Intensity")
print(float(np.average(B)))
Y,Cr,Cb = cv2.split(imageYCrCb)

#for Intensity of Cb

print("for intensity of Cb")
print(float(np.average(Cb)))
#Condition to Check For Jaundice
x = 0#for jaundice not detect
y=0
if np.average(B) < 110 and np.average(Cb) < 110:
    print("jaundice detected!!!")
    x = 1


else:
    x=0
    print("Jaundice Not Detected!!!")
keyPressed = -1
while (keyPressed < 0):
        # To Display The skin detected Image
        cv2.imshow('skin',sourceImage)
        cv2.imshow('skinregion',skinRegion)
        cv2.imshow('final_image', reqd_image)

        # keyPressed += 1
        if cv2.waitKey(20) & keyPressed == ord('q'):
             break

