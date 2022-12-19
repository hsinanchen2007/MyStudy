### 思路
1 win （拿1）
2 win （拿2）
3 win （拿3）
4
5 win （拿1）
6 win （拿2）
7 win （拿3）
8
9 win （拿1）
10 win （拿2）
11 win （拿3）
12 

### 代码

```cpp
class Solution {
public:
    bool canWinNim(int n) {
        return n <= 3 || n % 4 != 0;
    }
};
```