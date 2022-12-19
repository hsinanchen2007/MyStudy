### 解题思路
此处撰写解题思路
如果只有一个人的话安全位置一定为0
两个人->(0 + m) % 2;
三个人->((0 + m) % 2 + m) % 3;
n个人->循环res = (res + m) % i；
i 从 2 -> n
### 代码

```cpp
class Solution {
public:
    int lastRemaining(int n, int m) {
        int res = 0;
        for(int i = 2; i <= n ;i++){
            res = (res + m) % i;
        }
        return res;
    }
};
```