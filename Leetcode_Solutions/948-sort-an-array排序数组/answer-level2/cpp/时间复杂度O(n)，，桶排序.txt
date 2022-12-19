```
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int a[100001]={0};
        int min_v=nums[0];
        int max_v=nums[0];
        for(int i=0;i<nums.size();i++){
            if(nums[i]>max_v)
                max_v=nums[i];
            if(nums[i]<min_v)
                min_v=nums[i];
        }
        for(int i=0;i<nums.size();i++)
            a[nums[i]+50000]++;
        int cnt=0;
        for(int i=min_v+50000;i<=max_v+50000;i++){
            while(a[i]){
                nums[cnt++]=(i-50000);
                a[i]--;
            }
        }
        return nums;
    }
};
```
