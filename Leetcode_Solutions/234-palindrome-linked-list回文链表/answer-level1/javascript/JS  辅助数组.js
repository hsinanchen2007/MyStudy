### 代码

```javascript
var isPalindrome = function(head) {
    const arr = []
    while (head) {
        arr.push(head.val)
        head = head.next
    }
    return arr.join('') === arr.reverse().join('')
};
```
时间复杂度：O(n)
空间复杂度：O(n)