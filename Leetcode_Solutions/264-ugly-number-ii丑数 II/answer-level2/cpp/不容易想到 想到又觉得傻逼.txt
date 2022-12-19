### 解题思路
思路如下

### 代码

```cpp
class Solution {
public:
    int nthUglyNumber(int n) {
        long long A = 2, B = 3, C = 5;//这三个数表示的是当前倍数数字的最小值
	    int idex2 = 0, idex3 = 0, idex5 = 0;//这三个数字表示用来乘过的次数
        int num[2222] = {0};
	    num[0] = 1;//第一个数字为1，因为它乘什么就得什么
 
	    for (int i = 1; i < n; i++)
	    {//计算前MAXN个元素，这个数组一直都在乘是增长得很快的
		    long long m = min(min(A, B), C);
		    num[i] = m;//把三个数字的最小值赋予num[i]以保证它的顺序
 
		    if (A == m)//三个数的最小值是A
			    A = 2 * num[++idex2];//那就在数列的下一个值来乘二，增大了A，并且保证了其最小
		    if (B == m)
			    B = 3 * num[++idex3];
		    if (C == m)
			    C = 5 * num[++idex5];
	    }
        return num[n-1];
    }
};
```