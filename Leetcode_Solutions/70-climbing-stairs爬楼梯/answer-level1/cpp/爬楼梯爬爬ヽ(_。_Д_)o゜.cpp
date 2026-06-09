### 解题思路
以为这应该是最简了……但内存消耗还是只击败了百分之五十的用户，可是我只在里面定义了三个变量啊（面露迷茫）
其实就是模拟手算过程，m表示（n-2）,c本身代表(n-1),就是个f(n)=f(n-1)+f(n-2)的意思。
### 代码

```cpp
class Solution {
public:
    int climbStairs(int n) {
	if (n == 0)return 1;
	if (n == 1)return 1;
	int c = 1;
	int m = 1;
    int i;
	for (i = 1; i < n; i++) {
		c += m;
		m = c - m;
	}
	return c;
    }
};
```