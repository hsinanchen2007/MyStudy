### 解题思路
比赛时根据题目数据中n的范围，暴力循环O(n^3)的复杂度就可以满足要求了，但赛后思考发现，可以用O(n^2)解决，思路如下：
- 假设以某个士兵j为中间的士兵，分别统计其 左/右 侧评分 大于/小于 rating[j]的士兵数，则以士兵j为中间的士兵可以组成的作战单位数量为`smaller_cnt_l*bigger_cnt_r + bigger_cnt_l*smaller_cnt_r;`
- 遍历所有的士兵，以该士兵为中间，统计并加和其可以组成的作战单位数量，整体遍历一遍后，所有的组合结果肯定无重复，因此这就是答案

### 代码

```cpp
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        if(n < 3) return 0;
        int ans = 0;
        for(int j = 1; j < n-1; j++){
            int smaller_cnt_l = 0;
            int bigger_cnt_l = 0;
            int smaller_cnt_r = 0;
            int bigger_cnt_r = 0;
            for(int i = 0; i < j; i++){
                if(rating[i] < rating[j])
                    smaller_cnt_l++;
                else
                    bigger_cnt_l++;
            }
            for(int k = j+1; k < n; k++){
                if(rating[k] < rating[j])
                    smaller_cnt_r++;
                else
                    bigger_cnt_r++;
            }
            ans += smaller_cnt_l*bigger_cnt_r + bigger_cnt_l*smaller_cnt_r;
        }
        return ans;
    }
};
```