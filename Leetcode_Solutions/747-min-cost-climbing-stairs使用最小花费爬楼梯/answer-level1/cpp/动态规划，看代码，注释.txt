class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
     
        int i = 0;
       
        int last = 0 , llast = 0;  //last登上前一阶花费，llast再前一阶花费
        while( i < cost.size() )
        {
            int current = 0;
            current += (last < llast ? last : llast) + cost[i];  
            llast = last;
            last = current;
            ++i;
        }
        
        return  last < llast ? last : llast; 
    }
};