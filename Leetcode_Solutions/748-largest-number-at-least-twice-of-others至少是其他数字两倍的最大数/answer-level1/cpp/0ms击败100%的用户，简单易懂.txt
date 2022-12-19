### 解题思路
先遍历一遍数组找到最大值m，然后再遍历一遍数组，用最大值除以当前元素，如果结果小于2说明不满足。（需要注意不可以除以最大值元素本身），如果遇到最大值本身，就记录下最大值的下标，留着最后返回。

### 代码

```cpp
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int len = nums.size();
        int m =0;
        int flag=0;
        for(int i =0;i<len;i++){
            m=max(nums[i],m);
        }
        for(int i =0;i<len;i++){
            if(nums[i]!=0){
                if(double(m/nums[i])<2.0&&m!=nums[i]) return -1;
            }
            if(m == nums[i]) flag = i;
        }
        return flag;
    }
};
```