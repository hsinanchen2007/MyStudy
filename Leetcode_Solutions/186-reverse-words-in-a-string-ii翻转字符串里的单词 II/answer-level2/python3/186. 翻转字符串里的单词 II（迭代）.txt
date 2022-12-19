- 题意要求空间复杂度O(1)，因此必须要在原数组上直接修改；
- 设倒序操作为`T`，`str = a b c`，则有：
  - `c b a = ( aT bT cT )T`
- 因此，我们只需要将`a`,`b`,`c`分别倒置，再将整个str倒置，即可得到`c b a`。

```python []
class Solution:
    def reverseWords(self, s: [str]) -> None:
        """
        Do not return anything, modify str in-place instead.
        """
        i = 0
        for j in range(len(s)): # aT bT c
            if s[j] != ' ': continue
            self.reverse(s, i, j)
            i = j + 1
        self.reverse(s, i, len(s)) # aT bT cT
        self.reverse(s, 0, len(s)) # c b a
    def reverse(self, s, i, j):
        for k in range(i, (i + j) // 2):
            g = j - 1 - k + i
            s[k], s[g] = s[g], s[k]
```
```java []
class Solution {
    public void reverseWords(char[] str) {
        int i = 0;
        for(int j = 0; j < str.length; j++){ // aTbTc
            if(str[j] != ' ') continue;
            reverse(str, i, j);
            i = j + 1;
        }
        reverse(str, i, str.length); // aTbTcT
        reverse(str, 0, str.length); // cba
    }
    private void reverse(char[] str, int i, int j){
        for(int k = i; k < (i + j) / 2; k++){
            char tmp = str[k];
            int g = j - 1 - k + i;
            str[k] = str[g];
            str[g] = tmp;
        }
    }
}
```