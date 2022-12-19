### 解题思路
先写一个函数能够实现自动找到对应字母代表的数字；
按顺序提取输入的字母，比较提取的字母a[i]与后一个字母a[i+1]代表的数字的大小，分三种情况
考虑；a[i] > a[i+1];a[i] == a[i+1]; a[i] < a[i+1]

### 代码

```cpp
class Solution {
public:
    int fact(char ss)
    {
        if (ss == 'I')
            return 1;
        else if (ss == 'V')
            return 5;
        else if (ss == 'X')
            return 10;
        else if (ss == 'L')
            return 50;
        else if (ss == 'C')
            return 100;
        else  if (ss == 'D')
            return 500;
        else if (ss == 'M')
            return 1000;
            else 
            return 0;

    }


    int romanToInt(string a) {
        int str_n = a.size();
        int num = 0; 
        int i = 0;
        while (i < str_n ){
            if (fact(a[i]) < fact(a[i+1])){
                num = num + fact(a[i+1]) - fact(a[i]);
                i = i + 2;}
            else if  (fact(a[i]) == fact(a[i+1])){
                num = num + fact(a[i]);
                i = i + 1; 
            }
            else {
                num = num + fact(a[i]);
                i += 1;
            }           
        }
        return num;
    }

};
```