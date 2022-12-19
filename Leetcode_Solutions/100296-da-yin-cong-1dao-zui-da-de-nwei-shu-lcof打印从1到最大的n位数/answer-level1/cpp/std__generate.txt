### 解题思路
执行用时 :8 ms, 在所有 C++ 提交中击败了77.50% 的用户
内存消耗 :13 MB, 在所有 C++ 提交中击败了100.00%的用户

### 代码

```cpp
class Solution {
public:
    vector<int> printNumbers(int n) {
    	int max_num = pow(10, n) - 1;
    	vector<int> v(max_num);
    	std::generate(v.begin(), v.end(), [n=1]()mutable{
    		return n++;
    	});
    	return v;
    }
};
```