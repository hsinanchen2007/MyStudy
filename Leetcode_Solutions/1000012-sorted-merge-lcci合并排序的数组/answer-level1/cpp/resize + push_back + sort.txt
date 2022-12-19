### 解题思路
执行用时 :4 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗 :8.9 MB, 在所有 C++ 提交中击败了100.00%的用户

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