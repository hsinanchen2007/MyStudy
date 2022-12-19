### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    	for(size_t i=0;i<nums.size();++i){
        	auto ind = std::find(nums.begin(),nums.end(),0);
        	if(ind != nums.end()){
            	nums.erase(ind);
            	nums.push_back(0);
        	}
    	}
    }
};
```