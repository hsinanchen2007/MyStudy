```
class Solution{
	public:
		int minCostClimbingStairs(vector<int>& cost) {
			int num=cost.size();
			for(int i=2;i<num;++i)cost[i]+=min(cost[i-1],cost[i-2]);
			return min(cost[num-1],cost[num-2]);
	    }
}; 
```
