### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
	int numWays(int n) {
        if(n==0) return 1;
		if (n<=3) {
			return n;
		}
		else {
			int f0 = 2;
			int f1 = 3;
			int fn;
            int mod=1e9+7;
			for (int i = 4; i <= n; i++) {
				fn = (f0 + f1)%mod;
				f0 = f1;
				f1 = fn;
			}

			return fn;
		
		}
	}
};
```