### 解题思路
执行用时 :
0 ms
, 在所有 C++ 提交中击败了
100.00%
的用户
内存消耗 :
7.2 MB
, 在所有 C++ 提交中击败了
100.00%
的用户


### 代码

```cpp
class Solution {
public:
    int reverse(int x) {
        long tmp = 0;
        while(x != 0){
            int a = x % 10;
            tmp = tmp * 10 + a;
            if(tmp > INT_MAX || tmp < INT_MIN) return 0;
            x = x / 10;
        }
        return int(tmp);
    }
};
```