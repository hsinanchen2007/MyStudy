### 解题思路
本题根据题意不难求解，这里仅给出思路，首先‘A’的数量一旦超过1，则必然返回false，然后遍历字符串，只要‘L’出现，立刻开始寻找后面连续的两个字符是否为‘L’，如果是，则立刻给出false,否则给出true。

### 代码

```java
class Solution {
    public boolean checkRecord(String s) {
        int count = 0;
        
        for(int i = 0;i<s.length();i++) {
            if(s.charAt(i)=='A') {
                count++;
            }
        }
        if(count>1) {
            return false;
        }
        for(int i = 0;i<s.length()-2;i++) {
            if(s.charAt(i)=='L' && s.charAt(i+1)=='L' && s.charAt(i+2)=='L') {
                return false;
            }
        }
        return true;
    }
}
```