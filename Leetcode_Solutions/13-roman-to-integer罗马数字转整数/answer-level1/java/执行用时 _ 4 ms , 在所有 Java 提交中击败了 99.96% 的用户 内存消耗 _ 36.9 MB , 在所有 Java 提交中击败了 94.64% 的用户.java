### 解题思路
1.利用Java自带的toCharArray()函数，将字符串转为字符数组
2.分别找到匹配的字符，并加上对应的数字
3.因为存在4，9，40，90，400，900这些特别的字符形式，所以逐一讨论
4.由于存在'I'，'X'，'C'是字符串的最后一个字符，但在本代码中存在需要与数组后一个字符进行判断(判断是不是3步骤的形式)，
但是这样就会存在数组越界异常，因此在一开始便加上字符串"00"(加两个0是因为 i+=2; 这行代码)，用于保证下标不会越界
5.只要读取到字符串"00"中任意一个字符'00'，即可结束


### 代码

```java
class Solution {
    public int romanToInt(String s) {
        s = s + "00";
        char[] arr = s.toCharArray();
        int i = 0 ; 
        int sum = 0;
        while(arr[i] != '0'){
             char ch = arr[i];
             switch(ch){
                   case 'I' :
                         if(arr[i + 1] == 'V' ){
                            sum += 4;
                            i += 2;
                         }else if(arr[i + 1] == 'X' ){
                            sum += 9;
                            i += 2;
                         }else{
                             sum += 1;
                             ++i;
                         }
                         break;
                   case 'V' :
                         sum += 5;
                         ++i;
                         break;
                   case 'X' :
                         if(arr[i + 1] == 'L' ){
                            sum += 40;
                            i += 2;
                         }else if(arr[i + 1] == 'C' ){
                            sum += 90;
                            i += 2;
                         }else{
                             sum += 10;
                             ++i;
                         }
                         break;
                   case 'L' :
                         sum += 50;
                         ++i;
                         break;
                   case 'C' :
                         if(arr[i + 1] == 'D' ){
                            sum += 400;
                            i += 2;
                         }else if(arr[i + 1] == 'M' ){
                            sum += 900;
                            i += 2;
                         }else{
                             sum += 100;
                             ++i;
                         }
                         break;
                   case 'D' :
                         sum += 500;
                         ++i;
                         break;
                   case 'M' :
                         sum += 1000;
                         ++i;
                         break;
             }
        }
        return sum;
    }
}
```