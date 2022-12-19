### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    	vector<vector<int>> sums;

    	for(size_t i=0;i<nums1.size();++i){
    		for(size_t j=0;j<nums2.size();++j){
    			sums.push_back(vector<int>{nums1[i],nums2[j]});
    		}
    	}
    	std::sort(sums.begin(), sums.end(), [](vector<int>& l, vector<int>& r){
    		return ((l[0]+l[1]) < (r[0]+r[1]));
    	});

    	if(static_cast<size_t>(k) > sums.size()) return sums;
    	vector<vector<int>> sums_truc(sums.begin(), sums.begin()+k);
    	return sums_truc;
    }
};
```