### 解题思路
解决这一题主要是要仔细读题，理解题目，可以通过题目得知隐含要求：当前一位数与下一位相比，若大于下一位则为加，若小于下一位则为减，最后一位数必为正数。

### 代码

```java
class Solution {
    public int romanToInt(String s) {
        int sum=0;
        int firnum = getValue(s.charAt(0));
        for (int i =1; i < s.length(); i++) {
            int num = getValue(s.charAt(i));
            int a=0;
            if (num > firnum) {
              sum=sum-firnum;
            }
            if (num <= firnum) {
               sum=sum+firnum;
            }
            firnum=num;
        }
        sum=sum+firnum;
        return sum;
    }

    private  int getValue(char ch) {
        switch (ch) {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            default:
                return 0;
        }
    }
}
