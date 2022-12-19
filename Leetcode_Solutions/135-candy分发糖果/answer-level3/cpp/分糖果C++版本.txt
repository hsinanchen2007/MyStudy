时间复杂度： O(n), 遍历一次left2right数组和一次right2left数组
空间复杂度： O(n), left2right和right2left各n维的数组
合并时取两个数组中元素最大的
详情参考java版本的官方题解
```
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left2right(n, 1);
        vector<int> right2left(n, 1);
        int ans = 0;
        for(int i=0; i<n-1; i++)
        {
            if(ratings[i+1] > ratings[i])
                left2right[i+1] = left2right[i] + 1;
        }
        for(int i=n-1; i>0; i--)
        {
            if(ratings[i-1] > ratings[i])
            {
                right2left[i-1] = right2left[i] + 1;
            }
            ans += max(right2left[i], left2right[i]);
        }
        ans += max(right2left[0], left2right[0]);
        return ans;
    }
};
```
