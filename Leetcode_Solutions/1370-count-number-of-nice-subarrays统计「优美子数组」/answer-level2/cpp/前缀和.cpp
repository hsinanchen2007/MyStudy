用前缀和来做。
prefix[x] 代表前x个元素中奇数的个数。
针对以y结尾的子数组， 如果其要满足nums[x], num[x+1], ... num[y]中有k个奇数， 则必须满足
prefix[y] - prefix[x - 1] = k
现在我们从前到后扫一遍， 用一个stat数组记录前缀为特定奇数个数的前缀个数（比较绕）。

详见代码：

```
class Solution {
public:
    
    int *countOddPrefix;
    
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        countOddPrefix = (int *)malloc(sizeof(int) * (n + 1));
        for(int i = 1; i <=n; i++)countOddPrefix[i] = 0;
        countOddPrefix[0] = 1;
        
        int countOdd = 0;
        int cur = 0, ans = 0;
        
        for(int i = 0; i < n; i++){
            
            if(nums[i] & 1)countOdd++;
            
            if(countOdd >= k)ans += countOddPrefix[countOdd - k];
            
            countOddPrefix[countOdd]++;
            //printf("%d: %d\n",i,countOdd);
        }
        
        return ans;
    }
};
```
