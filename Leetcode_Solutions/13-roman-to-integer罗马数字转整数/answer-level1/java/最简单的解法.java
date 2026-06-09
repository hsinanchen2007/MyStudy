### 解题思路
 * 1.我们取出第一个进行判断
 * 2.如果小于则减去
 * 3.如果大于则加上
 * 4.重点：我们要每次都把当前的值赋值，则进行下一次判断
 * 5.要在加上当前的值
 * 时间复杂度o(n)
 * 空间复杂度o(1)

### 代码

```java
class Solution {
    public int romanToInt(String s) {
        int sum = 0;
        int value = getValue(s.charAt(0));
        for(int i = 1; i < s.length() ;i++){
           int temp = getValue(s.charAt(i));
            if (value < temp){
                sum -= value;
            }else {
                sum += value;
            }
            //把temp赋值给value，这样下一次判断就判断当前字符和下一个字符
            value = temp;
        }
        sum += value;
        return sum;
    }

    public int getValue(char cr){
        switch(cr){
            case 'I' :return 1;
            case 'V' :return 5;
            case 'X' :return 10;
            case 'L' :return 50;
            case 'C' :return 100;
            case 'D' :return 500;
           default:
            return 1000;
        }
    }
}
```