### 解题思路
**友情提示**：遇到有提示字符串仅包含小写（或者大写）英文字母的题，
都可以试着考虑能不能构造长度为26的每个元素分别代表一个字母的数组，来简化计算

对于这道题，用数组`c`来保存字母表里每个字母出现的次数
如法炮制，再对词汇表中的每个词汇都做一数组`w`，比较数组`w`与数组`c`的对应位置
- 如果`w`中的都不大于`c`，就说明该词可以被拼写出，长度计入结果
- 如果`w`其中有一个超过了`c`，则说明不可以被拼写，直接跳至下一个（这里用到了带label的continue语法）

### 代码

```java
class Solution {
    public int countCharacters(String[] words, String chars) {
        int[] c = new int[26];
        for(char cc : chars.toCharArray()) {
            c[(int)(cc - 'a')] += 1;
        }
        int res = 0;
        a: for(String word : words) {
            int[] w = new int[26];
            for(char ww : word.toCharArray()) {
                w[(int)(ww - 'a')] += 1;
            }
            for(int i=0; i<26; i++) {
                if(w[i] > c[i]) {
                    continue a;
                }
            }
            res += word.length();
        }
        return res;
    }
}
```