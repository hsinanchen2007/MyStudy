![image.png](https://pic.leetcode-cn.com/52207826b74ed271ad2f0386d6c87048dc4f96a31e8fdef93c0446158e21ba5c-image.png)
执行0ms, 内存7M, 击败100% +100%
### 解题思路
就很简单的遍历一遍...中间判断数字是否连续
PS: 没有get到这道题的难点在哪 0 0

### 代码

```cpp
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        for(int i = 0; i < nums.size(); i++){
            string str = to_string(nums[i]);
            int pos = i;
            while(i < nums.size() - 1 && nums[i] + 1 == nums[i+1]) i++; //数字连续
            if(pos != i) //若有增加
                str += "->" + to_string(nums[i]);
            ans.push_back(str);
        }
        return ans;
    }
};
```