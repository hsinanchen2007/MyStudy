### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    long GetProductForMaxRotateFun(vector<int>& A){
    	long f_A = 0;
    	for(size_t i=0;i<A.size();++i){
    		f_A += i * A[i];
    	}
    	return f_A;
    }
    int maxRotateFunction(vector<int>& A) {
    	if(!A.size()) return 0;
    	long f_A = GetProductForMaxRotateFun(A);
    	for(size_t i=1; i < A.size(); ++i){
    		int tail = A.back();
    		A.pop_back();
    		A.insert(A.begin(), tail);
    		f_A = std::max(GetProductForMaxRotateFun(A), f_A);
    	}
    	return f_A;
    }
};
```