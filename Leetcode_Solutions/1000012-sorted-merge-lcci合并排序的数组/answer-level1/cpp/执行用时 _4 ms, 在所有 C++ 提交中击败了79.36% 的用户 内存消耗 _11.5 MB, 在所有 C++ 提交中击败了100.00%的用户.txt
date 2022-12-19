### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        A.resize(m);
    	for(auto& iter:B){
    		A.push_back(iter);
    	}
    	std::sort(A.begin(), A.end());
    }
};
```