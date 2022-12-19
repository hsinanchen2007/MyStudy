如果前面的数大就继续往前，如果整个数列如此，就反转数组返回。

i是使得nums[i-1]<nums[i]的最大i,也就是说nums[i]开始是个递减数列。
nums[i-1]之前的数不变。
把后面数组大于nums[i-1]的最小数跟nums[i-1]调换。

然后把nums[i]到结尾的一段反转。

```
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i=nums.size()-1,temp;
        while(i>0){
            if(nums[i-1]<nums[i])break;
            i--;
        }
        int j=nums.size()-1;
        if(i>0){
            while((j>i)&&(nums[i-1]>=nums[j])){j--;}
            temp=nums[i-1];
            nums[i-1]=nums[j];
            nums[j]=temp;
            j=nums.size()-1;
        }
        while(j>i){
            temp=nums[j];
            nums[j]=nums[i];
            nums[i]=temp;
            i++;
            j--;
        }
        return;
    }
};
```
