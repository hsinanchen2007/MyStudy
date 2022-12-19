### 解题思路
1.双指针求解：i，left，right三个索引。对i进行遍历，然后left和right分别从左向右和从右向左移动
2.关键点：优化效率
1）必须要排序，不然没有办法用双指针
2）重复数可以略过，对i，left，right都适用
3）最接近说明等于0时是最接近的，因此等于0可以直接返回
4）当nums[i]>0&&nums[i]>target时，left和right必然大于target，因此不必继续遍历，直接break；


### 代码

```cpp
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        if(nums.size()<3){
            return 0;
        }


        sort(nums.begin(),nums.end(),less<int>());

        int minvalue = INT32_MAX;
        int sum = 0;

        for(int i = 0;i<nums.size();i++){

            int left = i+1;
            int right = nums.size()-1;

            while(left<right){
                int tmp =nums[i]+nums[left]+nums[right];
                int diff =tmp -target;

                if(abs(diff)<minvalue){
                    minvalue = min(abs(diff),minvalue);
                    sum = tmp;
                }

                
                if(diff<0){
                    left++;
                }else {
                    right--;
                }
            }
        }

        return sum;
        
    }
};
```