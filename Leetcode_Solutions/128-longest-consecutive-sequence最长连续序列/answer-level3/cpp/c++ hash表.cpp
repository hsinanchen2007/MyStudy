重点在于每次查看上下是否有数字，**只改变最上和最下的长度值**就可以了
``
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> ma;
        int m=0;
        for(int i=0;i<nums.size();i++)
        {
            if(!ma.count(nums[i]))
            {
                int z = ma.count(nums[i] - 1) ? ma[nums[i] - 1] : 0;//下面是否有数字
                int y = ma.count(nums[i] + 1) ? ma[nums[i] + 1] : 0;//上面是否有数字
                int x = y + z + 1;//连续序列长度
                ma[nums[i]] = x;//改变本节点的长度
                ma[nums[i]-z]=x;//将下边界改变
                ma[nums[i]+y]=x;//将上边界改变
                if(x>m)m=x;
            }
        }
        return m;
    }
};
```
