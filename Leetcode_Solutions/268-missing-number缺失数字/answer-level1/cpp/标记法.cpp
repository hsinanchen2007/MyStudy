题意分析：题中n个元素取值为[0, n]，且n个元素都不会重复，问题是让我们找到非负的元素。我们可以利用元素本身都是非负性，我们可以将存在的元素num，其下标对应的元素变成负的（0的负数仍为其本身，需特特殊处理），即nums[abs[num]] = -nums[abs[num]]

代码如下：
```cpp
/*
用value的正负来做标记，nums[idx]为负表示idx出现在序列中
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        int res = -1, tmp = 0;
        bool flag = false;
        nums.push_back(1);//添加一个元素，避免标记时越界
        for(int i = 0; i < len; ++i){
            nums[abs(nums[i])] = - nums[abs(nums[i])];
        }
        for(int i = 0; i < len + 1; ++i){
            if(nums[i] > 0){
                res = i;
                flag = true;
                break;
            }
            if(nums[i] == 0){//对值为0的下标进行标记，用于处理特殊情况
                tmp = i;
            }
        }
        if(!flag){//当所有元素都非正时，表明缺失的下标的元素值为0
            res = tmp;
        }
        return res;
    }
};
```