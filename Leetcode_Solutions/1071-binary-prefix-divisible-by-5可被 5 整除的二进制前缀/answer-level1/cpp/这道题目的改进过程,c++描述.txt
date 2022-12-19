刚开始想的很简单，不就是从头开始算出十进制，判断是否能被五整除吗？后来才发现 naive，早就超过位数了。

那么自然的想到如果上一个数就能被5整除，再乘以2，当然也能被5整除，所以直接把它当做0不是很好？

同样的如果上一个数被5除余数是1，就可以把它当做1来看，自然地想到 `pre=pre%5`

这就有了第一个代码

```cpp
class Solution {
public:
	vector<bool> prefixesDivBy5(vector<int>& A) {
		vector<bool> res(A.size());
		int pre(0);
		for (int i = 0; i < A.size(); i++)
		{
			pre = pre << 1;
			pre += A[i];
			if (pre % 5 == 0)
			{
				res[i] = true;
			}
			else {
				res[i] = false;
			}
			pre = pre % 5;
		}
		return res;
	}
};
```


但是一运行，发现只超过了46%，这不科学啊，感觉已经改进的很不错了

最后发现了几个可以改进的地方，第一是没必要既赋 true，又赋 false，直接在初始化的时候赋 false，有需要的时候在赋 true 不是更好？

第二个是，计算机算除法是很浪费时间的，%5 那一段花费了大量的时间，不如做个表，直接查表余数，岂不是更好？

这就有了第二段，超过了 96%

```cpp
class Solution {
public:
	vector<bool> prefixesDivBy5(vector<int>& A) {
		vector<bool> res(A.size(),false);
		int pre(0);
		vector<int> what_five_divided = { 0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4 };
		for (int i = 0; i < A.size(); i++)
		{
			pre = pre << 1;
			pre += A[i];
			if (what_five_divided[pre] == 0)
			{
				res[i] = true;
			}
			pre = what_five_divided[pre];
		}
		return res;
	}
};
```
