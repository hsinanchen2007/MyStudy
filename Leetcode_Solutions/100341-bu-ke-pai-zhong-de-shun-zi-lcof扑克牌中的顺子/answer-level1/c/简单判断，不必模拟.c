

![image.png](https://pic.leetcode-cn.com/d7a65f612606e53aa5c1bc0c02ca3708ed0d233dfaf55b64ad9e818569c5816a-image.png)

五张扑克牌可以形成顺子实际就需要：
1.除去0之后，最大与最小相差不可超过4，否则中间空缺太多怎么都补不了（例如 1 2 3 4 6，或者0 0 1 2 6）
2.不可以有重复的牌

所以做法很简单，就是首先排序，找到第一个不为零的数，和最大相差如果超过4，则不可以形成顺子
其次若有重复牌，则同样不可生成顺子
剩下的就是可以生成顺子的牌了


class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int zero_num = 0;
        while(nums[zero_num] == 0)
            zero_num++;
        if((nums[4] - nums[zero_num] ) > 4 )
            return false;
         int index = zero_num;
         while(index < 4)
            if(nums[index] == nums[index + 1])
                return false;
            else index++;
        return true;
    }
};

