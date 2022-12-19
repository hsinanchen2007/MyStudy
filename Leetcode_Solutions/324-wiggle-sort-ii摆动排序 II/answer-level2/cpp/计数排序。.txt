### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if(nums.size()<=1){
            return;
        }

        int maxnum=nums[0];
        int minnum=nums[0];

        for(int i=0;i<nums.size();i++){
            maxnum=max(maxnum,nums[i]);
            minnum=min(minnum,nums[i]);
        }

        int range=maxnum-minnum+1;
        vector<int> arr(range,0);
        for(int i=0;i<nums.size();i++){
            arr[nums[i]-minnum]+=1;
        }

        int j=0;
        for(int i=0;i<range;i++){
            while(arr[i]!=0){
                nums[j]=i+minnum;
                j++;
                arr[i]--;
            }
        }

        int len=nums.size();
        int k=1;
        int high=(len%2)?len-1:len-2;
        int mid=nums[len/2];
        vector<int> ans(len,mid);
        for(int i=len-1;i>=0 && nums[i]>mid;i--){
            ans[k]=nums[i];
            k+=2;
        }

        for(int i=0;i<len && nums[i]<mid;i++){
            ans[high]=nums[i];
            high-=2;

        }

        nums=ans;
        
    }
};
```