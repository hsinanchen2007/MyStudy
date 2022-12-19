### 解题思路
首先此解法只能用在astr里面都是小写字母的情况下，这样c-'a'就可以限制在int的32位中，用一个int代替字母表，将每个出现的字母的位置标注为1，也是左移x位1（x是该字母在字母表中的次序）的原因。如果该字母出现过，则按位与运算会出现不为零的结果， 如果没有出现用按位或运算将该字母的位置记录到letterLoc里面

### 代码

```java
class Solution {
    public boolean isUnique(String astr) {
        int letterLoc = 0;
        for(char c : astr.toCharArray()) {
            int bits = 1 << (c - 'a');
            if((letterLoc & bits) != 0) {
                return false;
            } else {
                letterLoc |= bits;
            }
        }
        return true;
    }
}
```