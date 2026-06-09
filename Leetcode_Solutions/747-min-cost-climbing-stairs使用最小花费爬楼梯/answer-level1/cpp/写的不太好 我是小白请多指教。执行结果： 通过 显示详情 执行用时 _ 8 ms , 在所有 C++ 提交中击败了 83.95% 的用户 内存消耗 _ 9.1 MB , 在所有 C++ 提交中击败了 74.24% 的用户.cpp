class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int x = cost.size();
        if(x == 1){
            return 0;
        }
        if(x == 2){
            return std::min(cost[0],cost[1]);
        }
        vector<int> costfinal;
        costfinal.push_back(0);
        costfinal.push_back(0);
        int i = 2;
        while(i <= x){
            costfinal.push_back(std::min(costfinal[i-1] + cost[i-1],costfinal[i-2] + cost[i-2]));
            i++;
        }
        return costfinal[x];
    }
};