```
func addDigits(_ num: Int) -> Int {
        if (num < 10) {
            return num;
        }
        let result = num % 9;
        if (result == 0) {
            return 9;
        }
        return result;
    }
```