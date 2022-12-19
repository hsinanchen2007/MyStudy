简单题，照做就好了

### 代码

```cpp
class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
    	vector<int> ans;
    	for(int i = 0; i < nums.size(); ++i)
    	{
    		ans.insert(ans.begin()+index[i], nums[i]);
    	}
    	return ans;
    }
};
```