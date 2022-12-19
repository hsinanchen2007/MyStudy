- 思路是建立一个标记数组，用来记录该位置的元素是否被访问过
- 采用了染色和记忆性的思想，每次出发寻找最大的环形，用不同颜色标记不同的出发次数，每次出发路径上访问过的元素之后都不需要再次遍历
- 每次出发中，遇到之前遍历过的节点就终止并进行判断，如果是终止节点是之前出发路径上的节点，那么不是有效循环，如果终止节点是本次路径上的节点而且终止节点的下一个循环节点不是自己，那就是有效循环。

1. 首先对标记数组初始化，大小与nums相同，初始值置0，之后定义一个color，用于记录不同遍历的次数
2. 对nums数组循环，每次通过当前元素寻找新元素的位置，通过nums[j]*nums[i]判断是否异号，通过visit判断是否访问过该元素
3. 当while循环截止时，用j+nums[j]+nums.size())%nums.size() != j判断循环长度是否大于1，用visit[j] == color判断是否终止于本次循环
```
bool circularArrayLoop(vector<int>& nums) 
    {
        vector<int> visit(nums.size(),0);
        int color = 1;
        for(int i=0;i<nums.size();i++)
        {
            if(visit[i] == 0)
            {
                int j = i;
                while(visit[j] == 0 && nums[j]*nums[i]>0)
                {
                    visit[j] = color;
                    j = j + nums[j] + nums.size();
                    j = j%nums.size();
                }
                if(visit[j] == color && (j+nums[j]+nums.size())%nums.size() != j)
                    return true;
            }
            color++;
        }
        return false;
    }
```