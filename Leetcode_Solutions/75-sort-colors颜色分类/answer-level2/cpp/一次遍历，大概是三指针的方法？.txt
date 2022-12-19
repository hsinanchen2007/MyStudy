### 解题思路
定义两个常量，一个计算红色的个数，另一个计算白色的个数。
具体看代码把...我组织能力不是很强

### 代码

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
         int red=0,white=0;
         for(int i=0;i<nums.size();i++){
             if(nums[i]==0){
                 if(nums[red]==1){
                     swap(nums[red],nums[i]);
                     swap(nums[red+white],nums[i]);
                     red++;
                 }else{
                     swap(nums[red],nums[i]);
                     red++; //red的个数
                    } 
             }else if (nums[i]==1){
                 swap(nums[red+white],nums[i]); //如果为白，就插到红色后面
                 white++; // white 的个数
             }
         }
    }
};
```