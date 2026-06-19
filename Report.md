*Task 1*


**Q1.** `int` holds whole numbers (e.g. `21`). `float` holds decimals (e.g. `1.75`). Use `int` for pin numbers or counts; use `float` for voltages or measurements.

**Q2.** Without `Serial.begin(9600)`, the Serial Monitor shows nothing — the communication channel never opens.

**Q3.** Because the code is in `setup()`, which runs only once on power-on. `loop()` is empty, so nothing repeats.

---

*Task 2*


**Q1.** `pinMode()` only needs to run once — it configures the pin, not controls it. Putting it in `loop()` would re-configure it thousands of times per second for no reason.

**Q2.** Without both `delay()` calls, the LED switches so fast it appears dimly on (or fully on depending on the board) — the human eye can't see individual blinks at that speed.

**Q3.** Set `onTime = 3000` and `offTime = 500`.

---

*Task 3*


**Q1.** A parameter is an input variable a function expects when called. `waitTime` receives whatever number you pass in — like `blinkOnce(100)` sets `waitTime` to `100` inside the function.

**Q2.** Without a function, if you need to change the blink logic you'd have to find and fix every copy in `loop()`. With a function, you fix it once and all calls update automatically.

**Q3.** Yes — hardcode the speed inside the function body itself, e.g. `delay(500)`. But then every call blinks at the same speed with no way to vary it without editing the function directly.

---

*Task 4*


**Q1.** `counter = counter - 1` decreases the counter each iteration so the condition `counter > 0` eventually becomes false and the loop exits. Without it, `counter` stays at 5 forever — infinite loop.

**Q2.** Change `int counter = 5` to `int counter = 7`. Nothing else changes.

**Q3.** `setup()` runs once automatically when the board powers on. A `while` loop runs repeatedly only as long as its condition is true — you control when it starts and when it stops.

---

*Task 5*


**Q1.** Paste your final working code — that's the last version you just submitted. Copy it exactly into your report.

**Q2.** One bug you actually ran into: you used `startValue` as the loop condition instead of a separate `count` variable, so `while(startValue < 5)` was always false and the loop never ran. You fixed it by declaring `int count = startValue` and using `count` as the changing variable.

**Q3.** Change one line in the `while` loop:

```cpp
count = count - 2;  // instead of count - 1
```

Output becomes: `5, 3, 1` then done.

---

**Q4.** Add it right after the `while` loop closes, before `"=== Countdown Complete ==="`:

```cpp
while (count > 0) {
    // ... existing countdown
}

// Add this:
digitalWrite(ledPin, HIGH);
delay(5000);
digitalWrite(ledPin, LOW);

Serial.println("=== Countdown Complete ===");
```

It goes there because the countdown is finished at that point — the LED stays on for 5 seconds as a final signal before the completion message prints.
