时间O(n),空间O(1).
执行用时  内存消耗
4 ms	 8.9 MB
递增三元子序列自然是需要找到三个递增的数，只需要存储前两个即可，找到第三个数时及时返回。所以此处定义1st，2nd来存储。
其实核心条件是
（1）2nd存储最小的第二元
（2）1st存储最小的第一元，是为了保证前一个条件。
只要保证条件（1），向后扫描整个数组,若有大于2nd的数，即可得到题目所求。条件（2）是为了保证条件（1）的正确性。
代码如下，其中flag为true表示1st已经填充数值：
bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        if(n<3)
            return false;

        int add_1st=0;
        int add_2nd=nums[0];
        bool flag=false;
        for(int i=1;i!=n;++i)       //assert: the smallest 2nd is add_2nd and the smallest 1st is add_1st
        {
            if(add_2nd<nums[i])
            {
                if(!flag)
                {
                    add_1st=add_2nd;
                    add_2nd=nums[i];
                    flag=true;
                }
                else
                    return true;
                
            }
            else if(add_2nd>nums[i])
            {
                if(!flag)
                    add_2nd=nums[i];
                else
                {
                    if(add_1st<nums[i])
                        add_2nd=nums[i];
                    else
                        add_1st=nums[i];
                } 
            }
        }
        return false;
    }

