### 思路
观察规律可以看出每9个一次循环：
1    1
2    2
3    3
4    4
5    5
6    6
7    7
8    8    
9    9    
10    1
11    2
12    3    
13    4
14    5
15    6
16    7
17    8
18    9
19    1
20    2

### 代码

```cpp
class Solution {
public:
    int addDigits(int num) {
        return num == 0 ? 0 : (num - 1) % 9 + 1;
    }
};
```