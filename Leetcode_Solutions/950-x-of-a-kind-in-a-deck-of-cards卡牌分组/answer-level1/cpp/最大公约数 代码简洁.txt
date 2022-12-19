### 解题思路
N个数字 每组X个  （X >= 2）
所以 N % X = 0
每组数字相同  假设有5个数字1 每组2个  5个1 没法分组
所以 每个数字的个数（Times） % X = 0
所以 X 是 所有Times 的约数  所以X是所有Times 的最大公约数
gcd(x, y)  C++自带的   求x,y的最大公约数
### 代码
```cpp
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        int counts[10000] = {0};
        int rs = 0;
        for (int d : deck) {
            counts[d]++;
        }
        for (int b : counts){
            //有0个数字，跳过
            if(b == 0) continue;
            rs = gcd(b, rs);
            //比如 4  和 5 最大公约数是1 ，但是题目要求X >= 2  直接返回
            if(rs == 1) return false;
        }
        return rs >= 2;
    }
};
```