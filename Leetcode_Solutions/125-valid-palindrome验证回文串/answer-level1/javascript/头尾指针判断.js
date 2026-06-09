### 解题思路
python有现成函数判断 JavaScript需要正则替换掉 或者自己写判断

### 代码

```python3
class Solution:
    def isPalindrome(self, s: str) -> bool:
        left = 0
        right = len(s) - 1

        while(left <= right):
            if not s[left].isalnum():
                left += 1
                continue
            if not s[right].isalnum():
                right -= 1
                continue
            if s[left].lower() != s[right].lower():
                return False
            left += 1
            right -= 1
        return True
```


javascript 


```javascript
/**
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function(s) {
  if (s === " " || s === "") return true;

  let left = 0,
    right = s.length - 1;
  const isSymbol = char => {
    if (char >= "a" && char <= "z") {
      return false;
    } else if (char >= "A" && char <= "Z") {
      return false;
    } else if (char >= "0" && char <= "9") {
      return false
    }
    return true;
  };

  while (left <= right) {
    if (isSymbol(s[left])) {
      left++;
      continue;
    }
    while (isSymbol(s[right])) {
      right--;
      continue;
    }
    if (s[left].toLowerCase() !== s[right].toLowerCase()) {
      return false;
    }
    left++;
    right--;
  }
  return true;
};
```