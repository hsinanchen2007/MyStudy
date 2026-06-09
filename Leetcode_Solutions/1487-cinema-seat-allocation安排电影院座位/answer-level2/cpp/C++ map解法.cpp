### 解题思路
这题报了无数的超时，终于AC了，记录一下思路
1、map存储reservedSeats中所在同一排座位，并把它转换为二进制，0代表该位置无人，1代表有人
2、map中元素的个数代表有多少排座位有人，这样可以排除无人座位有多少排，先计算无人的(n-m.size())*2;
3、遍历整个map，求出单排中有多少个家庭座位。

### 代码

```cpp
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int x1 = 0b0001111000;
        int x2 = 0b0111100000;
        int x3 = 0b0000011110;
        map<int, int> m;
        for (auto re: reservedSeats)
        {
            int tm = (1 << (re[1] - 1));
            m[re[0]] += tm;

        }
        int ans = (n - m.size())*2;
        for (auto t: m)
        {
            int x = t.second;
            if ((x&x2) == 0){
                    ans++;
                    x = x | x2;
                }
                if ((x & x3) == 0) 
                {
                    ans++;
                    x = x | x3;
                }
                if ((x & x1) == 0)
                {
                    ans++;
                }
        }
        return ans;
    }
};
```