每一段的可接雨水值取决于左边柱子最高的高度(left)和右边柱子最高的高度(right)和其本省的高度(height)。
即：
```
ans += min(left,right) - height > 0 ? min(left,right) - height : 0;
```
所以我们只需要知道当前段的左右最大柱子的高度就可以得到当前段的可接雨水值是多少。


```
class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> s(height.size(),0);
        int max_right = 0;
        //首先用一个辅助数组s来存储右边柱子的最大值，从右往左遍历。
        for(int i=height.size() - 1;i>=0;i--)
        {
            s[i] = max_right;
            max_right = max_right > height[i] ? max_right : height[i];
        }
        int max_left = 0;
        int ans = 0;
        for(int i=0;i<height.size();i++)
        {
            int temp = min(max_left,s[i]);
            if(temp - height[i] > 0)
                ans += temp - height[i];
            
            max_left = max_left > height[i] ? max_left : height[i];
        }
        return ans;
    }
};
```

