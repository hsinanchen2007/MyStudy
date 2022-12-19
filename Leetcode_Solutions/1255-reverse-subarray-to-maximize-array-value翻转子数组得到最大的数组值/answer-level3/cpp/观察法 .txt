观察到两点：
- 反转(i,j)之后，i和j之间的值没有影响
- 反转(i,j)之后，(i-1, i) ,(j, j+1)(假设是这个大小关系) 
    - 这两个区间如果在数轴上没有重叠部分的话， 那么会导致原来的值增大2*(j-i)
    - 如果有重叠部分，怎么交换最后都不会导致值增大

所以， 枚举（i-1,i)， 维护j的最大值即可，O(n)
注意：
- 要正反两遍，因为可能i大也可能j大
- 反转区间可能有一头是0或者n-1 特殊判断一下

我在特殊判断上着急了，wa了好几次，分享下最近做题的心得：
1. 难题难在一些观察，向着正确的方向简化问题，而不是在于模板的一些算法
2. 如果有完整的思路再动手写会好一点，因为队友想出来做法我实现的时候觉得挺顺利
3. 看起来难题写出来其实逻辑上不难，甚至会看起来很整洁，不要犯怵
4. 题目本身只是一个载体，一个字符串的题可以是dp，后缀数组，也可以是二分图匹配，整体二分甚至是数论，不断地获得观察和转化才是正解


```
class Solution {
    int n;
    int cal(vector<int>& nums)
    {
        int m = -0x3f3f3f3f;
        int best = 0;
        for(int i = n-3; i>=1; i--)
        {
            m = max(m, min(nums[i+1], nums[i+2]));
            int cur = max(nums[i], nums[i-1]);
            if(cur<m) best = max(best, (m-cur)*2);
        }
        for(int i = n-1; i>=1;i--)
            best = max(best, max(0, abs(nums[i]-nums[0])-abs(nums[i]-nums[i-1])));
        return best;
    }
public:
    int maxValueAfterReverse(vector<int>& nums) {
        int ans = 0;
        n = nums.size();
        if(n==1)return ans;
        for(int i = 1; i<n;i++) ans+=abs(nums[i]-nums[i-1]);
        int best1 = cal(nums);
        reverse(nums.begin(), nums.end());
        int best2 = cal(nums);
        return ans+max(best1, best2);
    }
};
```
![image.png](https://pic.leetcode-cn.com/ada7bd8a7ebb617de016d5223f2d90e721519f775dd6335c39aa866ec09bb07b-image.png)