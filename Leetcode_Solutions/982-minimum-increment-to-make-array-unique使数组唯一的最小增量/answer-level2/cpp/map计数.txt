map计数

### 代码

```cpp
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
    	map<int,int> m;
    	int count = 0;
    	for(int& a : A)
    		m[a]++;
    	for(auto& mi : m)
    	{
    		if(mi.second > 1)
    		{
    			count += mi.second-1;
    			m[mi.first+1] += mi.second-1;
    		}
    	}
    	return count;
    }
};
```