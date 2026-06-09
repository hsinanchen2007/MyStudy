### 解题思路
排序，固定，双指针类似2sum模式

### 代码

```cpp
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int len = nums.size();
        int index1,index2,index3;
        int closest = nums[0] + nums[1] + nums[2];
        //能用数组中的就不要用INT_MAX,万一目标就是INT_MAX呢
        for (int i = 0 ; i < len-2 ; i++){
            index1 = i;
            index2 = i+1;
            index3 = len-1;
            while(index2<index3){
                int tempsum = nums[index1] + nums[index2] + nums[index3];
                closest = abs(closest-target) > abs(tempsum-target) ? tempsum : closest;
                if(tempsum>target)index3--;
                else if(tempsum<target)index2++;
                else break;//不要忘了相等跳出的情况，不然可能会死循环
                //写条件句组合比写多个if执行更快。
            }
        }
        return closest;
    }
};
```