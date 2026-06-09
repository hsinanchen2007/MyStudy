### 解题思路
一次遍历整个字符串：
  1.一般情况下，罗马数字一般是正常递减的，大数在前小数在后，直接将字母转化为数字加起来。
    举例：CXI，100 + 10 + 1 = 111.
  2.特殊情况下，罗马数字出现部分逆序，小数在前边，说明该数需要减。
    举例：CIX，100 - 1 + 10 = 109. (I比X小在前边)
由此可见，对每个字符都进行加减后，结果就出来了。

### 代码

```cpp
class Solution {
public:
    int romanNum(char ss) {  //罗马字母转数字
        int num;
        switch(ss){
                case 'I'  :
                  num = 1;
                  break; 
                case 'V'  :
                  num = 5;
                  break;
                case 'X'  :
                  num = 10;
                  break;
                case 'L'  :
                  num = 50;
                  break;
                case 'C'  :
                  num = 100;
                  break;
                case 'D'  :
                  num = 500;
                  break;
                case 'M'  :
                  num = 1000;
                  break;
                default  :
                  num = 0;
                  break;
            }
        return num;
    }

    int romanToInt(string s) {
        int front, later, total, length;
        total = 0; length = s.size();
        for (int i = 1; i<= length; i++) {
            front = romanNum(s[i-1]);
            if (i == length) {
                later = 0;
            }else {
                later = romanNum(s[i]);
            }
            if (front < later) {    //与后一位对比，正常顺序可以直接加
                front = front * (-1); //小数在前则为减
            }
            total += front ;
        }
        return total;
    }
};
```