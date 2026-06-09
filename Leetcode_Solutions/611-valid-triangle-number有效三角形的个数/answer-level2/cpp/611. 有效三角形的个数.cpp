![QQ图片20191104161323.png](https://pic.leetcode-cn.com/20d95735e5f3268211b69e86e8ef7d58721ead63b4d39643e667772f25274215-QQ%E5%9B%BE%E7%89%8720191104161323.png)

```
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n=nums.size();
        stable_sort(nums.begin(),nums.end());
        
        int st=0;
        while(st<n && nums[st]==0)
        {
            ++st;
        }

        int res=0;
        
        int n1=n-1;
        int n2=n-2;
        int ni,sum;
        for(int i=st;i<n2;++i)
        {
            ni=nums[i];
            int k=i+2;
            for(int j=i+1;j<n1;++j)
            {
                sum=ni+nums[j];
                while(k<n && sum>nums[k])
                {
                    ++k;
                }
                res+=(k-j-1);
            }
        }

        return res;
    }
};
```
