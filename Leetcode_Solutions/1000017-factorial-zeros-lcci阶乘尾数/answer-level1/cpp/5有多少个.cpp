看有多少个5*2，2肯定比5多

### 代码

```cpp
class Solution {
public:
    int trailingZeroes(int n) {
    	int count = 0;
    	while(n)
    	{
    		// if(n%5 == 0)
    		// 	count++;
    		count += n/5;
    		n /= 5;
    	}
    	return count;
    }
};
```