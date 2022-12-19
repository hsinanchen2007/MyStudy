### 解题思路
牛顿迭代法，注意cur需要设成long。（欢迎指正）

### 代码

```cpp
class Solution {
public:
int mySqrt(int n) {
	if(n==0)return 0;
	long cur = 1;
	//int pre = cur;
	while (true)
	{   //cout<<"-"<<endl; 
		//pre = cur;
		cur = (cur + (long)n / cur) / 2;
		//if (abs(cur-pre)<1e-6)return cur;
		if(cur*cur<=n)return cur;
	}
}
};
```