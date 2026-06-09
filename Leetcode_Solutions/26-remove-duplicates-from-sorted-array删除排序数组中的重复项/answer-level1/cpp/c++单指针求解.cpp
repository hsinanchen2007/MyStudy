### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        if(nums.empty())    return 0;

        int count = 1;//计数不同元素的个数
        int k = 0;//新的指针表示新的数组

        for(int i = 0; i < nums.size(); i++){
            //将不同于nums[k]的元素前移到nums[++k]的位置
            if(nums[i] != nums[k]){
                nums[++k] = nums[i];
                count++;
            }
        }

        nums.erase(nums.begin()+count, nums.end());

        return nums.size();
    }
};
```