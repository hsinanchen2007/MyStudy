### 解题思路
求出n的各位数字即可

### 代码

```cpp
class Solution {
public:
    int subtractProductAndSum(int n) {
    	int nSum = 0, nCen = 1;    
    	int temp;
    	while (n) {
    		temp = n % 10;
    		nSum += temp, nCen *= temp;
    		n /= 10;
		}
		return nCen - nSum;
    }
};
```