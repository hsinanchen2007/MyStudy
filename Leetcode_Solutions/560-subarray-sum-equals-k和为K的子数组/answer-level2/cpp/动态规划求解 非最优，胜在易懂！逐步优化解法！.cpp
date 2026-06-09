1. 最暴力解法  内存超出限制
```
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans=0;
        int n = nums.size();
        vector<vector<int>>bp(n+1,vector<int>(n+1, 0));
        //如何优化 现在每层都是bp[i][j]即 数组中i~j的和
        bp[0][0]=0;
        for(int i=1; i<=n; i++){
            bp[i][i] = nums[i-1];
            if(bp[i][i]==k) ans += 1;
            for(int j=i+1; j<=n; j++){
                bp[i][j] = bp[i][j-1] + nums[j-1]; 
                //动态方程 bp[i][j]=bp[i][j-1]+nums[j-1] 即加上数组中后一位， 扩大区域
                if(bp[i][j]==k) ans += 1;
            }
        }
        return ans;
    }
};
```
2. 优化改成空间O(n)

仔细想其实上层的值可以传递给下层的值，每次记录的和也为i~j的和，直到j为n
但是可以用减小区域来做， 上层得到的和减去数组i表示的值 从前缩小区域
```
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans=0;
        int n = nums.size();
        vector<int>bp(n+1,0);
        //现在每层记录i,末尾的值；
        for(int i=1; i<=n; i++){
            bp[i] = bp[i-1]+nums[i-1];
            if(bp[i]==k) ans++;
        }
        for(int i=2; i<=n; i++){
            for(int j=i; j<=n; j++){
                bp[j] -= bp[i-1]; //缩小区域
                if(bp[j]==k) ans++;
            }
        }
        return ans;
    }
};
```

