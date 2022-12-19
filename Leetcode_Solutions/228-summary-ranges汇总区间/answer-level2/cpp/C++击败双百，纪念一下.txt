### 解题思路
第一次击败了双百，高兴，要炫耀一下，哈哈

我的主要解题思路也没啥特别，就是遍历一遍找分段
begin标记段开头数字，end标记段尾数字，pos标记段开头位置

我觉得有两点小技巧可能是帮助我内存消耗击败了100%：
1、用临时右值加到ans数组中，我猜测应该是触发了STL中的移动语义，减少了内存拷贝的空间；
2、判断某值是否可以在段中的语句是begin - pos != nums[i] - i，可以让begin用int初始化，不用long，就能过那个有INT_MAX的case。

### 代码

```cpp
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if(nums.empty()) return ans;
        int begin,end,pos, n = nums.size();
        for(int i=0;i<=n;i++){
            if(i == 0){
                begin = nums[i];
                end = nums[i];
                pos = 0;        
            }else if(i == n || begin - pos != nums[i] - i){
                if(begin == end) ans.push_back(to_string(begin));
                else{
                    ans.push_back(to_string(begin)+"->"+to_string(end));
                }
                if(i != n){
                    begin = nums[i];
                    end = nums[i];
                    pos = i;
                }
            }else end = nums[i];
        }
        return ans;
    }
};
```