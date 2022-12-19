### 解题思路
Just iterate through these two lists, and compare them one by one
### 代码

```javascript
/**
 * @param {number[]} guess
 * @param {number[]} answer
 * @return {number}
 */
var game = function(guess, answer) {
    let correct_count = 0;
    for (i = 0; i < guess.length; i++) {
        if (guess[i] === answer[i]) {
            correct_count++;
        }
    }
    return correct_count;
};
```

```python3
def game(self, guess: List[int], answer: List[int]) -> int:
    correct_count = 0

    for i in range(len(guess)):
        if guess[i] == answer[i]:
            correct_count += 1

    return correct_count
```