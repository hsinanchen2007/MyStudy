### 解题思路
此处撰写解题思路
// 思路：
（1）先定义空数组nonZeroElements用于存放nums数组中的非0元素
（2）扫描nums数组，将非0元素存入nonZeroElements数组
（3）将nonZeroElements数组中元素挨个存回nums数组，nums数组后面部分元素全赋值为0；
    // 时间复杂度O(n)
    // 空间复杂度O(n)
### 代码

```cpp
class Solution {
    // 思路：（1）先定义空数组nonZeroElements用于存放nums数组中的非0元素
    // （2）扫描nums数组，将非0元素存入nonZeroElements数组
    // （3）将nonZeroElements数组中元素挨个存回nums数组，nums数组后面部分元素全赋值为0；
    // 时间复杂度O(n)
    // 空间复杂度O(n)
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> nonZeroElements;
    
    for(int i=0;i<nums.size();i++)
        if(nums[i])
           nonZeroElements.push_back(nums[i]);

    for(int i=0;i<nonZeroElements.size();i++)
        nums[i]=nonZeroElements[i];
    
    for(int i=nonZeroElements.size();i<nums.size();i++)
        nums[i]=0;
    }
};
```