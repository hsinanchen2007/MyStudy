### 解题思路
遍历字符，比较该字符下一位是否是特殊例子中一种，是就统计，最后结果减去即可。

### 代码

```java
class Solution {
    public int romanToInt(String s) {
       int len = s.length();
       int num = 0;
       int indexI = 0;
       int indexX = 0;
       int indexC = 0;
       for (int i = 0; i < len; i++){
          if (s.charAt(i) == 'I'){
               num += 1;
          }
          if (s.charAt(i) == 'I' && i < len -1){
               if (s.charAt(i+1) == 'V' || s.charAt(i+1) == 'X') indexI++;
          }
          
           if (s.charAt(i) == 'V'){
              num += 5;
          }
           if (s.charAt(i) == 'X'){
              num += 10;
          }
           if (s.charAt(i) == 'X' && i < len -1){
               if (s.charAt(i+1) == 'L' || s.charAt(i+1) == 'C') indexX++;
          }
           if (s.charAt(i) == 'L'){
              num += 50;
          }
           if (s.charAt(i) == 'C'){
              num += 100;
          }
           if (s.charAt(i) == 'C' && i < len -1){
               if (s.charAt(i+1) == 'D' || s.charAt(i+1) == 'M') indexC++;
          }
           if (s.charAt(i) == 'D'){
              num += 500;
          }
           if (s.charAt(i) == 'M'){
              num += 1000;
          }
       }
       return num - (indexI * 2 + indexX * 20 + indexC * 200);
       
    }
}
```