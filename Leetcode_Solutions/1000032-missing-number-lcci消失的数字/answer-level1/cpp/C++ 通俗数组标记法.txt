### 解题思路
建立一个vector，里面元素都初始化为-1。
如果某个元素出现了，则将-1变为0.
最后再遍历一次看哪个位置是-1的，就是缺了的那个数字。

![image.png](https://pic.leetcode-cn.com/3c3e73684c35d2bfe85c541ffbbdf83c0eac179b65135937da0d7cc9d4ba7928-image.png)


### 代码

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<int> memo(nums.size()+1, -1);
        for(int i = 0; i < nums.size(); i++)
            memo[nums[i]]=0;
        
        for(int i = 0; i < memo.size(); i++)
            if(memo[i]==-1) return i;
        return 0;
    }
};
```