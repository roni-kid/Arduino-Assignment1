# Arduino Assignment 1 — Report Answers

**Course:** Programming C++ for Engineers Using Arduino  
**Institution:** Ghana Communication Technology University (GCTU)  
**Student:** Aaron Andoh Dadson Baidoo — 2526401387

---

## Task 1 — Hello, Serial!

**Q1. What is the difference between `int` and `float`? Give one example of when you would use each.**

`int` holds whole numbers with no decimal point. `float` holds numbers with decimal places. I would use `int` for a pin number like `int ledPin = 13` since pin numbers are always whole. I would use `float` for a voltage reading like `float voltage = 3.3` since voltage can have decimal values.

**Q2. What happens if you forget to write `Serial.begin(9600)` in setup()? Try it and explain what you observe.**

Nothing appears in the Serial Monitor. The communication channel between the Arduino and the computer is never opened, so any `Serial.print()` or `Serial.println()` calls are ignored.

**Q3. Why does the output appear only once and not over and over?**

Because all the code is inside `setup()`, which the Arduino runs only once when it powers on. `loop()` is empty, so there is nothing to repeat.

---

## Task 2 — LED Blink with Variables

**Q1. Why do we put `pinMode(ledPin, OUTPUT)` inside `setup()` and not inside `loop()`?**

`pinMode()` only needs to run once — it configures the pin direction, not the signal on it. Placing it in `loop()` would re-configure the pin thousands of times per second with no benefit.

**Q2. What would happen if we removed both `delay()` calls? Predict first, then try it and describe what you actually see.**

Prediction: the LED would blink so fast it would appear to be constantly on. Observation: the LED appeared dimly lit and did not visibly blink at all, because it was switching faster than the human eye can detect.

**Q3. If you wanted the LED to be ON for 3 seconds and OFF for half a second, which values would you change and to what?**

Change `onTime = 3000` and `offTime = 500`.

---

## Task 3 — Make It a Function

**Q1. In your own words, explain what a parameter is.**

A parameter is an input variable that a function expects to receive when it is called. For example, `waitTime` in `blinkOnce(int waitTime)` receives whatever number is passed in at the call site — like `blinkOnce(100)` sets `waitTime` to `100` inside the function.

**Q2. Why is it useful to put repeating code into a function instead of writing it three times in `loop()`?**

If the logic needs to change, you fix it in one place and every call updates automatically. Writing it three times means three places to find and fix — more work and more room for mistakes.

**Q3. Could you write `blinkOnce` without taking any parameter at all? If yes, how would you make it blink at different speeds without parameters?**

Yes. You would hardcode the delay value directly inside the function, for example `delay(500)`. However, every call would blink at the same fixed speed. To blink at different speeds you would have to write a separate function for each speed, which defeats the purpose of using a function.

---

## Task 4 — Count Down with a while Loop

**Q1. What is the role of the line `counter = counter - 1`? What would happen without it?**

It decreases the counter by 1 on every iteration so the condition `counter > 0` eventually becomes false and the loop exits. Without it, `counter` stays at 5 forever, the condition is always true, and the Arduino is stuck in an infinite loop.

**Q2. Rewrite the countdown to start from 7 instead of 5.**

Change one line:
```cpp
int counter = 7;
```

**Q3. In your own words, what is the difference between `setup()` and a while loop?**

`setup()` is a special function the Arduino runs automatically once at power-on — you do not control when it starts or stops. A `while` loop is a structure you write inside your code that repeats a block as long as a condition you define is true. You control what the condition is and when it becomes false.

---

## Task 5 — Smart Countdown

**Q1. Final working code:**

```cpp
const int startValue = 5;
const int ledPin = 13;

void flashLED(int times) {
  int i = times;
  while (i > 0) {
    digitalWrite(ledPin, HIGH);
    delay(200);
    digitalWrite(ledPin, LOW);
    delay(200);
    i = i - 1;
  }
}

void setup() {
  int count = startValue;

  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);

  Serial.println("\n=== Smart Countdown Starting ===");

  while (count > 0) {
    Serial.print("Count: ");
    Serial.println(count);
    flashLED(count);
    delay(1000);
    count = count - 1;
  }

  Serial.println("=== Countdown Complete ===");
}

void loop() {
  // empty
}
```

**Q2. Describe one bug or mistake you ran into while writing this program and how you fixed it.**

I used `startValue` directly as the loop condition — `while(startValue < 5)` — instead of a separate changing variable. Since `startValue` is a constant equal to 5, the condition `5 < 5` was always false and the loop never ran. I fixed it by declaring a separate variable `int count = startValue` and using `count` in the condition and decrement instead.

**Q3. If you wanted the program to count DOWN by 2 each step (5, 3, 1) instead of by 1, what would you change?**

Change one line inside the while loop:
```cpp
count = count - 2;
```

**Q4. If you wanted the LED to also stay ON for a final 5 seconds after the countdown completes, where in the code would you add this and what would the code look like?**

Add it after the while loop closes, before the completion message:
```cpp
while (count > 0) {
    // ... existing countdown
}

digitalWrite(ledPin, HIGH);
delay(5000);
digitalWrite(ledPin, LOW);

Serial.println("=== Countdown Complete ===");
```

It goes there because the countdown has finished at that point. The LED stays on for 5 seconds as a final signal before the completion message prints.
