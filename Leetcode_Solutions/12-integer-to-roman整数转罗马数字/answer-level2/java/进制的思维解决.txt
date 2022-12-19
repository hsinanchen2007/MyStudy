### 解题思路
1、按照进制的思维，每一个罗马标识是进制中的一环，对每一环除法计数，组合；
2、每一次完成后计算剩余的数，循环。

### 代码

```java
class Solution {
    public String intToRoman(int num) {
        if (num <= 0) {
            return "";
        }
        int[] romanNum = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        String[] romanStr = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        String result = "";
        int tmp = num;
        for (int i = 0; i < romanNum.length; i++) {
            for (int j = 1; j <= tmp / romanNum[i]; j++) {
                result += romanStr[i];
            }
            tmp = tmp - tmp / romanNum[i] * romanNum[i];
        }
        return result;
    }
}
```