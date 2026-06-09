### 解题思路
![image.png](https://pic.leetcode-cn.com/def589acf5d8aa9e6605d2cdac4e55d6d0fdd7f761e20e0ab13984e1b41bb631-image.png)
先令结果re=0，对于一个n位数的N，数位分别为AnAn-1An-2....A1，如果最大位在字符串数组中，则re+=dp[An-1An-2...A1];接着通过查找在字符串数组中有多少个不大于（An）-1的数，将这个个数乘以字符数组大小的n-1次方（乘法原理），求出这个dp值后，再加上倒数后1位为0，倒数后2位为0，...直到第二位为0的所有情形，也就是一个等比数列求和式，就可以得到答案。
部分代码的含义：
re表示结果，
dp表示求值函数，
pre[i]表示在字符串数组中小于等于i的数的出现次数再加一
posOfBit当前状态的位数-1；
exist[i]数字i是否出现在字符串数组中。
exOfN：N的位数-1；


### 代码

```cpp
class Solution {
public:
int dp(int n, int*pre, bool*exist, int posOfBit)
{
	if (n < 10)
		return pre[n] - 1;
	int re = 0;
	int firstBit = n / static_cast<int>(pow(10, posOfBit));
	if (firstBit == 0)return 0;
	if (firstBit > 0)
		re +=((pre[firstBit - 1] - 1)>0? (pre[firstBit - 1] - 1):0)*static_cast<int>(pow(pre[9] - 1, posOfBit));
	if (exist[firstBit])
		re += dp(n % (static_cast<int>(pow(10, posOfBit))), pre, exist, posOfBit - 1);
	return re;
}
    int atMostNGivenDigitSet(vector<string>& D, int N) {
        int exOfN = 0;
	for (; pow(10, exOfN) <= N; exOfN++);
	exOfN--;
	int size = D.size();
	int re = 0;
	if(size>1)
	re+=size * (pow(size, exOfN) - 1) / (size - 1);//等比数列求和
	bool*exist = new bool[10];
	for (int i = 0; i < 10; i++)exist[i] = false;
	for (int i = 0; i < D.size(); i++)
		exist[D[i].at(0) - '0'] = true;
	int*pre = new int[10];
	pre[0] = 1;
	for (int i = 1; i < 10; i++)
		if (exist[i])
			pre[i] = pre[i - 1] + 1;
		else pre[i] = pre[i - 1];
	re+= dp(N, pre, exist, exOfN);//加上dp值。
    if(size==1)//特判
    {
        int a=D[0].at(0)-'0';
        if(N/(static_cast<int>(pow(10,exOfN)))<a)
        return exOfN;
        else{
            int maxm=0;
            for(int i=0;i<exOfN;i++)
            {
                maxm*=10;
                maxm+=a;
            }
            if(maxm<=N)
            return exOfN+1;
            else return exOfN;
        }
    }
	return re;
    }
};
```