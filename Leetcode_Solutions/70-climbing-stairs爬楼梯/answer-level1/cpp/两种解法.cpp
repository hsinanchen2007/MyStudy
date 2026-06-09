### 解题思路
这个题放到前面比较好，有一个关键点，n层楼梯到达的方式=o(n-1) + o(n)
有两种思路：
1.递归(从n开始)
2.直接循环(从1开始)或者建立一个dptable

### 代码

```cpp
class Solution {
public:
    long climbStairs(int n) {
        if(n==1||n==2||n==3){
            return n;
        }
        long a = 1;
        long b = 2;
        int i = 0;
        while(i<(n-1)/2){
            a = a + b;
            b = a + b;
            i++;
        }
        if(n&1) return a;
        else return b;
    }
};
```