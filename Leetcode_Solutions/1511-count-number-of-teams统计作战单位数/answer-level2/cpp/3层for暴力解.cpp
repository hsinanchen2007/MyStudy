```
class Solution {
public:
    int numTeams(vector<int>& rating) {
    	int i, j, k, sum = 0, n = rating.size();
    	for(i = 0; i < n-2; ++i)
    		for(j = i+1; j < n-1; ++j)
    			for(k = j+1; k < n; ++k)
    				if((rating[i] < rating[j] && rating[j] < rating[k])
    					 ||(rating[i] > rating[j] && rating[j] > rating[k]))
    					sum++;
    	return sum;
    }
};
```
