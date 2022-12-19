```
class Solution {
public:
    int massage(vector<int>& nums) {
        int n= nums.size();
        if(!n) return 0;
        if(n==1) return nums[0];
        int *a = new int[n];
        for(int i=0;i<n;i++) *(a+i) = 0;
      
        *a = nums[0];
        *(a+1) = max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            a[i] = max(a[i-2]+nums[i],a[i-1] );
        }
        return a[n-1];


    }
};
```
