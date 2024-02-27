### **Prosthetic hand using electromyography**



All of project logic is divided by 4 steps.

![1142](https://github.com/Spied1/prosthetics/assets/117092326/a13b10e3-7183-44ba-9884-e373c514a83c)


## 1) Receiving a signal through emg/ecg sensor AD8232.
   AD8232 receivs signal with 3 electrods․ 1 negative. 1 muscle group and 1 support. After receiving, it's amplifys a signal.
## 2) Clear signal from noises.
   Using algorithm of noise removing to get clear signal.
## 3) Check signal for fulfilment of conditions.
   When a muscle is tense, it gives more amplification than in a calm state, after we use a thresholder to compare the signal, passing a bool function for true or false from the fulfillment of the condition. 

## 4.1) If true activate servo.
   
## 4.2) If false deactivate servo.
