### 解题思路
主要是处理题目留下的坑，因为数组中的数字可能很大，求和的时候容易溢出

### 代码

```java
class Solution {
    public String shiftingLetters(String S, int[] shifts) {
        for(int i = 0; i < shifts.length; i++){
            shifts[i] %= 26;
        }
        for(int i = shifts.length - 2; i >= 0; i--){
            shifts[i] += shifts[i + 1];
        }
        for(int i = 0; i < shifts.length; i++){
            shifts[i] %= 26;
        }
        int t;
        char[] chars = S.toCharArray();
        for(int i = 0; i < chars.length; i++){
            t = chars[i] + shifts[i];
            t = t > 'z' ? t - 26 : t;
            chars[i] = (char)t;
        }
        return String.valueOf(chars);
    }
    
}
```