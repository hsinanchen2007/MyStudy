### 解题思路
记录无进位加法的值`a^b`和进位值`a&b`, 当进位值为0时返回无进位加法值

### 代码

**递归**
```c++ []
class Solution {
public:
    int getSum(int a, int b) {
        // 异或运算:=不进位加法
        if(!b) return a;
        int s = a^b; // 计算无进位和
        int c = (unsigned)(a&b)<<1; // 进位到下一位
        return getSum(s, c);
    }
};
```
**迭代**
```c++ []
class Solution {
public:
    int getSum(int a, int b) {
        while(b != 0){
            int t = a^b;
            b = (unsigned int)(b&a)<<1;
            a = t;
        }
        return a;
    }
};
```