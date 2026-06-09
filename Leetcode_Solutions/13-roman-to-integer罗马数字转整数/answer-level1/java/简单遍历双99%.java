执行用时 :5 ms, 在所有 Java 提交中击败了99.29%的用户
内存消耗 :36.1 MB, 在所有 Java 提交中击败了98.73%的用户
![image.png](https://pic.leetcode-cn.com/24abab7539affa7d84c5189ab376b430578d76326f78ad5d882ccc5d5fc8a801-image.png)
先罗马字符转对应数字放入数组，然后遍历数组，相邻两项相减，大于0则加减数，小于0则减掉两数之差，对这n-1项sum求和。
但是这样没有考虑最后一项，如果最后两项还存在小的在前面的情况则不必操作，不然还要要加上最后一项。
遍历数组还得加一个条件，当只有一个罗马字符时，直接返回这个字符对应的数就行，否则遍历会数组越界。
```
class Solution {
    public int romanToInt(String s) {
        char [] chararr = s.toCharArray();
        int [] numarr = new int [chararr.length];
        for (int i =0; i < chararr.length;i++){
            if (chararr[i] == 'I'){
                numarr[i] = 1;
            }else if (chararr[i] == 'V'){
                numarr[i] = 5;
            }else if (chararr[i] == 'X'){
                numarr[i] = 10;
            }else if (chararr[i] == 'L'){
                numarr[i] = 50;
            }else if (chararr[i] == 'C'){
                numarr[i] = 100;
            }else if (chararr[i] == 'D'){
                numarr[i] = 500;
            }else{
                numarr[i] = 1000;
            }
        }
        if (numarr.length == 1)return numarr[0];
        int sum = 0;
        for (int i = 0; i < numarr.length-1; i++){
            if (numarr[i] - numarr[i+1] >= 0){
                sum += numarr[i];
            }else{
                sum -= (numarr[i] - numarr[i+1]);
                i++;
            }
        }
        
        if (numarr[numarr.length-2] - numarr[numarr.length - 1] >= 0) sum += numarr[numarr.length - 1];
        
        return sum;
    }
}
```
