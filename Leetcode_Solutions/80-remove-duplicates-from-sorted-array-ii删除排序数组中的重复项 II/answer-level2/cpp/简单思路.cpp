### 解题思路
![QQ图片20200117102129.png](https://pic.leetcode-cn.com/75dc312921b2f6ae658ab8607136da00baf6fc155cfa99c55da59c9854994529-QQ%E5%9B%BE%E7%89%8720200117102129.png)

+ 令一标记值比数组中最后一个元素要大（最大的）
+ 遍历一遍数组，碰到个数大于三个的令后面的均为标记值
+ 再遍历一边数组，去除标记值

### 代码

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
            
        long extra = nums[nums.size()-1]+1;
        int cnt = 1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[i-1])
                cnt++;
            else
                cnt = 1;
            if(cnt==3)
                nums[i-2] = extra,cnt=2; //避免与最近的一个比较出错  此处为i-1也可
        }

        cnt = 0; 
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=extra)
                 nums[cnt++] = nums[i];
        }
        return cnt;
    }
};
```