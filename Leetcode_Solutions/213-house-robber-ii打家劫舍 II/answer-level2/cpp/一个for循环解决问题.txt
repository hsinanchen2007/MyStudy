对去掉第一个元素和去掉最后一个元素的数组分别进行dp：
```
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        int n=nums.size();
        vector<int>a(n+1),b(n+1);
        for(int i=2;i<n+1;i++){
            a[i]=max(a[i-1],a[i-2]+nums[i-2]);
            b[i]=max(b[i-1],b[i-2]+nums[i-1]);
        }
        return max(a[n],b[n]);
    }
};
};
```
