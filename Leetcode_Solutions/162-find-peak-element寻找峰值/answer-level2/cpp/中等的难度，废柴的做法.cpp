### 解题思路
这题目最友好的地方就是说明nums[-1]和nums.end()都是负无穷，所以-1到第一个元素就是上坡，最后一个元素的时候肯定是下坡。而且只要找一个峰就可以了，那随便挑一个呗。。。从一开始，第一个要下降的时候就是峰了。
要注意的是数组下标条件。nums.size()-1就要结束了。

### 代码

```cpp
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
         int j = 0;
         while (j < nums.size()-1) {
             if (nums[j] > nums[j+1])
                 return j;
             j++;
         }   
        return nums.size()-1;
    }
};
```