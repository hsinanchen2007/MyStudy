```c++
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j=0,temp=0, i = 0, n = nums.size(),k=0;
        while(i<n){
            j = i, temp = nums[i];
            while(j<n && nums[j]==nums[i])j++;
            nums[k++]=temp;
            if(j-i>1)nums[k++]=temp;
            i=j;
        }
        return k;
    }
};
```