### 解题思路
此处撰写解题思路
无脑for循环
### 代码

```java
class Solution {
   public String intToRoman(int num) {
        StringBuilder stringBuilder = new StringBuilder();
        for (;num>=1000;){
            stringBuilder = stringBuilder.append("M");
            num = num - 1000;
        }
        for (;num>=900;){
            stringBuilder = stringBuilder.append("CM");
            num = num - 900;
        }
        for(;num>=500;){
            stringBuilder = stringBuilder.append("D");
            num = num - 500;
        }
        for (;num>=400;){
            stringBuilder = stringBuilder.append("CD");
            num = num - 400;
        }
        for (;num>=100;){
            stringBuilder = stringBuilder.append("C");
            num = num - 100;
        }
        for (;num>=90;){
            stringBuilder = stringBuilder.append("XC");
            num = num - 90;
        }
        for (;num>=50;){
            stringBuilder = stringBuilder.append("L");
            num = num - 50;
        }
        for (;num>=40;){
            stringBuilder = stringBuilder.append("XL");
            num = num - 40;
        }
        for (;num>=10;){
            stringBuilder = stringBuilder.append("X");
            num = num - 10;
        }
        for (;num>=9;){
            stringBuilder = stringBuilder.append("IX");
            num = num - 9;
        }
        for (;num>=5;){
            stringBuilder = stringBuilder.append("V");
            num = num - 5;
        }
        for (;num>=4;){
            stringBuilder = stringBuilder.append("IV");
            num = num - 4;
        }
        for (;num>=1;){
            stringBuilder = stringBuilder.append("I");
            num = num - 1;
        }

        return stringBuilder.toString();
    }
}
```