### 解题思路
移两个代价为0，移一个代价为1。则能将数组中奇数移动到1的位置，将数组中偶数移动到0的位置。分别统计奇偶个数，最小的则为代价。
### 代码
class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        for(int i=0;i<chips.size();++i)
            chips[i]%=2;
        int num_0=0,num_1=0;
        for(int i=0;i<chips.size();++i)
        {
            if(chips[i]==0)
                ++num_0;      
            else
                ++num_1;      
        }
        return (num_0<num_1)?num_0:num_1;
    }
};
