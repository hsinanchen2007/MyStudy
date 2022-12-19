求出到达每一个阶梯所需的最短路径；
举个栗子：假设能量数组为en[1,2,5,6,9,8,7];
到达第0个阶梯很明显：cost[0]=1;
到达第1个阶梯也很明显cost[1]=2;
到达第2个阶梯，可由第0个跳到第2个，花费为cost[2]=cost[0]+en[2]=6
            也可由第1个跳到第2个，花费为cost[2]=cost[1]+en[2]=7
故选择较小值，令cost[2]=6；
到达第3个阶梯，可由第2个跳到第3个，花费为cost[3]=cost[2]+en[3]=12
            也可由第1个跳到第3个，花费为cost[3]=cost[1]+en[3]=8
故选择较小值，令cost[3]=8；
以此类推。
最后只需要比较到达最后两个阶梯所需的能量值，返回较小的一个即可。代码如下：
class Solution {
public:
    
    int minCostClimbingStairs(vector<int>& cost) {
		int len = cost.size();
		for(int i=2;i<len;i++){
		cost[i] = cost[i-1]>=cost[i-2]?cost[i-2]+cost[i]:cost[i-1]+cost[i];
		
		}
        return cost[len-1]>cost[len-2]?cost[len-2]:cost[len-1];
    }
};