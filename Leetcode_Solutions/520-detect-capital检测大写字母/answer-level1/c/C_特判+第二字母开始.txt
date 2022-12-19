### 解题思路
1. 当只有一位，一定是真
2. 前两位：小大:aB。小小:ab。大小:Ab。大大:AA.只有小大不满足，是假。
3. 只要比较从第二位开始，是否全部相等，否者不等就是假。

### 代码

```c []
#define isupper(ch) (ch < 97 ? 1 : 0)

bool detectCapitalUse(char * word){
    bool first = isupper(*word++), second;
    if (*word) second = isupper(*word++);
    else return true;
    if (!first && second) return false;      // 小大
    while (*word) {
        first = isupper(*word++);
        if (first != second) return false;
    }
    return true;
}
```
```python3 []
class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        return word.islower() or word.isupper() or word.istitle()
```