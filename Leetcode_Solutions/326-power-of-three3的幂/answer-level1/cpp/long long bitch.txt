### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isPowerOfThree(int n) {
    	long long tmp = 1;
    	while(1){
    		if(tmp == n) return true;
    		if(tmp > n) return false;
    		tmp *= 3;
    	}
    }
};
```