### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int hammingWeight(uint32_t n) {
    	map<int, int> record;
    	vector<int> bits;
    	while(n){
    		bits.push_back(n%2);
    		n >>= 1;
    	}
    	for(auto& iter:bits){
    		record[iter]++;
    	}
    	return record[1];
    }
};
```