### 解题思路
用a, b, c, d分别表示出千位，百位，十位，个位，然后讨论每一位上的取值，用字符串s来接纳每一位的情况。
首先是千位，由于输入范围为1～3999，因此千位最大为3，直接在字符串s上接上a个"M"
其次是百位，先讨论特殊情况9和4，然后是大于4和小于等于4的情况，这两种情况不一样。
十位和个位类似百位的情况。

### 代码

```java
class Solution {
    public String intToRoman(int num) {
        int a = num / 1000;
        int b = (num / 100) % 10;
        int c = (num / 10) % 10;
        int d = num % 10;
        String s = new String();

        //千位，只可能是0～3
        for(int i = 0; i < a; i ++){
            s += "M";
        }

        //百位，分四种情况讨论：b == 9, b == 4, b > 4, b < 4
        if(b == 9){
            s += "CM";
        }
        else if(b == 4){
            s += "CD";
        }
        else if(b > 4){
            int remain = b % 5;
            s += "D";
            for(int i = 0; i < remain; i ++)
            s += "C";
        }
        else{
            for(int i = 0; i < b; i ++){
                s += "C";
            }
        }

        //十位，和百位情况一样
        if(c == 9){
            s += "XC";
        }
        else if(c == 4){
            s += "XL";
        }
        else if(c > 4){
            int remain = c % 5;
            s += "L";
            for(int i = 0; i < remain; i ++)
            s += "X";
        }
        else{
            for(int i = 0; i < c; i ++){
                s += "X";
            }
        }

        //个位，和百位情况一样
        if(d == 9){
            s += "IX";
        }
        else if(d == 4){
            s += "IV";
        }
        else if(d > 4){
            int remain = d % 5;
            s += "V";
            for(int i = 0; i < remain; i ++)
            s += "I";
        }
        else{
            for(int i = 0; i < d; i ++){
                s += "I";
            }
        }

        return s;
    }
}
```