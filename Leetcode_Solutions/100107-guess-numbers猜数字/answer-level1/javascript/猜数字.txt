

### 代码

```javascript
var game = function(guess, answer) {
    let count = 0
    for (let i = 0; i < 3; i++) {
        if (guess[i] == answer[i]) {
            count++
        }
    }
    return count
};
```