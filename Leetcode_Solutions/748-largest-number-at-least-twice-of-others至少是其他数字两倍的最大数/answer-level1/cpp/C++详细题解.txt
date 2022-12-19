将数组从大到小排列，若位置【0】大于等于位置【1】，就符合条件，然后返回原始的索引（通过备份数组）
没啥好说的，都在注释里

```
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int ans = -1; //若不存在符合要求的元素，返回-1
        if(nums.size() == 1) return 0; //若只有一个元素，一定最大，直接返回它的索引
        vector <int> copy(nums.begin(),nums.end()); //复制一份数组，用来找到索引
        sort(nums.begin(),nums.end(),greater<int>()); //将数组从大到小排序
        if(nums[0] >= 2 * nums[1]) //若符合要求
        {
            for(int i = 0; i < copy.size(); ++i) //查找该元素原本的索引
            {
                if(copy[i] == nums[0])
                {
                    return ans = i; //返回索引
                }
            }
        }
        return ans;
    }
};
```