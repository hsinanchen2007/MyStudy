### 解题思路
堆排序：
（1）对无序数组构建最大堆通过下沉父节点，实现downAdjust；
（2）删除堆顶元素，将堆顶元素移到堆尾，（忽略掉已转移的堆尾）再构建最大堆；循环操作2.

### 代码

```cpp
class Solution {
public:
    void downAdjust(vector<int>& nums, int parentIndex, int length)
    {
         int temp = nums.at(parentIndex);
         int childIndex = 2*parentIndex+1;
         while (childIndex < length){
             if (childIndex+1<length && nums.at(childIndex+1)>nums.at(childIndex))
            {
             childIndex++;
            }
            if (nums.at(parentIndex) >= nums.at(childIndex))
            {
                break;
            }
            nums.at(parentIndex) = nums.at(childIndex);
            parentIndex = childIndex;
             //nums.at() = temp;
             childIndex = 2*parentIndex+1;
             nums.at(parentIndex) = temp;
        }
        

    }

    vector<int> sortArray(vector<int>& nums) {
        for (int i=(nums.size()-2)/2;i>=0;i--){
            downAdjust(nums, i, nums.size());
        }
        for (int i = nums.size()-1; i>0; i--){
            int temp = nums.at(0);
            nums.at(0) = nums.at(i);
            nums.at(i) = temp;
            downAdjust(nums, 0, i);
        }
        return nums;
    }
    
};
```