### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int begin=0;
        int end=nums.size()-1;
        for(int i=0; i<=end&&begin<=end; i++){
            while((begin<end)&&(nums[begin]==0)) begin++;
            i=i<begin?begin:i;
            while((i<end)&&(nums[end]==2)) end--;
            if(nums[i]==1)continue;
            else if(nums[i]==0){
                nums[i]=nums[begin];
                nums[begin]=0;
                begin++;
                if(nums[i]==2)i--;
            }
            else if(nums[i]==2){
                nums[i]=nums[end];
                nums[end]=2;
                end--;
                if(nums[i]==0)i--;
            }

         }
    }
};
```