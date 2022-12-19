![image.png](https://pic.leetcode-cn.com/14f6d29dce7d64e1540e011d4420c97bcbcc097e9f138808cdfbe3530fcfab33-image.png)

### 解题思路
首先判断复杂度肯定＞O(nlogn)了，直接sort就好。

然后是两个要点：
+ 使用两层循环，第一层遍历，第二层用2sum的双指针思想，总的时间复杂度为O(n²)
+ 去重的对象想清楚是关键：外层中，只要前面出现过了，一定不能再出现了；内层中，同理


### 代码

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        size_t len = nums.size();
        if(len < 3) return vector<vector<int>>();
        //排序
        sort(nums.begin(), nums.end());
        vector<vector<int> > rslt;
        for(size_t idx = 0; idx < len - 2; ++idx)
        { 
            //去重           
            while(idx > 0 && idx < len - 2 && nums[idx] == nums[idx-1])
                ++idx;
            size_t pos1 = idx + 1, pos2 = len - 1;
            while(pos2 > pos1)
            {
                if(nums[idx] + nums[pos1] + nums[pos2] == 0)
                {
                    rslt.push_back(vector{nums[idx], nums[pos1], nums[pos2]});
                    //调整pos和去重
                    while(pos2 > pos1 && nums[pos1] == nums[pos1+1])
                        ++pos1;
                    ++pos1;
                    while(pos2 > pos1 && nums[pos2] == nums[pos2-1])
                        --pos2;
                    --pos2;
                }
                else if(nums[idx] + nums[pos1] + nums[pos2] > 0)
                        --pos2;
                     else
                        ++pos1;
            }
        }
        
        return rslt;
    }
};
```

最后再说说处理重复问题的想法：

+ 一开始为了解决重复问题，直接使用set<vector<int>>来存储，最后再转成vector<vector<int>>，也就是RB树，O(nlogn)罢了。
但显示超时了，且通过了所有测试用例（？？？）:
![image.png](https://pic.leetcode-cn.com/83ac0d84b44cc23717cdb48ca6559c19855a4bfb84ec02bcdaab71ec8db357a1-image.png)

+ 然后是想用unordered_map<vector<int>>，hash存取O(1)应该ok？
但无法使用，原因如下：
> unordered_set和unordered_map本质上都是使用hash方法对元素进行存储和查找，而C++没有为vector定义的默认hash方法，故无法通过编译。

参考：
[解决默认unordered_set无法哈希vector的问题](https://blog.csdn.net/dreamiond/article/details/88553332)
[C++ unordered_set of vectors](https://stackoverflow.com/questions/29855908/c-unordered-set-of-vectors)