首先对数组进行排序之后，然后利用双指针法进行求解。

排序之后利用双指针，对后面的两个元素进行查找即可。
```
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        int ans=nums[0]+nums[1]+nums[2];
        for(int i=0;i<n;i++){
            int start=i+1,end=n-1;
            while(start<end){
                int sum=nums[i]+nums[start]+nums[end];
                if(abs(target-sum)<abs(target-ans)){
                    ans=sum;
                }
                if(sum>target) end--;
                else if(sum<target) start++;
                else return ans;
            }
        }
        return ans;
    }
};
```