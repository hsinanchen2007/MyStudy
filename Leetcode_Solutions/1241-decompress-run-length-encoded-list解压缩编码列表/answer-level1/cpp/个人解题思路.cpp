### 解题思路
此处撰写解题思路
最简单的思路：
获取列表长度后，使用两个for循环
第一个用来控制 遍历到哪一对
第二个用来控制 向结果中添加元素

### 代码

```cpp
class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        int lens = nums.size()/2;
        vector<int> result;
        for(int i=0; i < lens; i++)
        {
            for(int j=0;j<nums[2*i];j++)
            {
                result.push_back(nums[2*i+1]);
            }
        }
        return result;
    }
};


```