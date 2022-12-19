### 解题思路
这里注意到reservedSeats相对于n来说，其实并不大
```
1 <= reservedSeats.length <= min(10*n, 10^4)
```
我们可以先算出没有reservedSeats所对应的家庭数，也就是
```
2 * n
```
然后再把考虑reservedSeats后，那一行所能容纳的家庭数：
```
原总家庭数 - (2 - 现在的单行家庭数)
```
遍历所有的reservedSeats就可以得到答案了。
实现方面，可以遍历reservedSeats，用一个map将对应的col都存起来;

#### 现在的单行家庭

终于写完跑出来后，看到100%,100%，还是有点激动(可能是用C++做的人不多=_=)
截图纪念一下，其实还可以更省空间
![image.png](https://pic.leetcode-cn.com/900ba7f0dfb3b536e5e99281e9ae3e1a9646d661e2cb892913d7c06fb4c7b3ae-image.png)


### 代码

```cpp
class Solution {
public:
    int max_families(vector<int>& reserved_cols) {
        int ans = 0;
        int ans_iter = 0;

        if ((reserved_cols[1] == 0) && (reserved_cols[2] == 0)) {
            ans_iter = 2;
        }

        if ((reserved_cols[3] == 0) && (reserved_cols[4] == 0)) {
            if (ans_iter == 2) {
                ans_iter += 2;
                ans += ans_iter / 4;
                ans_iter = 0;
            }
            else {
                ans_iter = 2;
            }
        }
        else {
            ans_iter = 0;
        }

        if ((reserved_cols[5] == 0) && (reserved_cols[6] == 0)) {
            if (ans_iter == 2) {
                ans_iter += 2;
                ans += ans_iter / 4;
                ans_iter = 0;
            }
            else {
                ans_iter = 2;
            }
        }
        else {
            ans_iter = 0;
        }

        if ((reserved_cols[7] == 0) && (reserved_cols[8] == 0)) {
            if (ans_iter == 2) {
                ans_iter += 2;
                ans += ans_iter / 4;
                ans_iter = 0;
            }
        }

        return ans;
    }

    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int ans = 2 * n;
        map<int, vector<int>> seat_map;

        int row;
        int col;

        for (int i = 0; i < reservedSeats.size(); i++) {
            row = reservedSeats[i][0];
            col = reservedSeats[i][1] - 1;

            if (seat_map.count(row) == 0) {
                for (int j = 0; j < 10; j++)
                    seat_map[row].push_back(0);
                seat_map[row][col] = 1;
            }
            else {
                seat_map[row][col] = 1;
            }
        }

        for (auto iter = seat_map.begin(); iter != seat_map.end(); iter++) {
            int occupy_families = max_families(iter->second);
            if (occupy_families < 2) {
                ans = ans - (2 - occupy_families);
            }
        }
                        
        return ans;
    }
};
```