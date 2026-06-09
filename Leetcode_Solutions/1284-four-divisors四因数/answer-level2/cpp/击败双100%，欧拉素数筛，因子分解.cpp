### 解题思路
使用欧拉素数筛得到素数表，可以按需动态扩展素数表
然后分析四因子只有两种可能性：
a*b=num(a≠b)     sum+=(1+a+b+num)
或者a*(a*a)=num   sum+=(1+a+a*a+num)
其中a,b均为素数
遍历素数表查找素数因子即可，每个数只需要最多查询两个最小的素因子即可判断
![dddd.png](https://pic.leetcode-cn.com/a3e781894c646b3daf0d77d8364be501ed947c56f874b790d005f2bf3c7373ff-dddd.png)

### 代码

```cpp
#include<vector>
class Solution {
public:
	vector<int> prime;
    //curprime表示当前已经计算到的素数的上界，可以根据需要随时增加上界
    //比如50表示[1,50]内的素数已经计算出并放在vector prime里面
    //这里计算素数表使用欧拉素数筛
	int vis[100001] = { 0 }, curprime = 1;

	int sumFourDivisors(vector<int>& nums) {
		int  sum = 0;
		if (nums.size() == 0)return 0;

        //默认计算1到50内的素数 [1,50]
		getPrime(50);

		for (auto num : nums)
		{
            //如果需要扩展素数上界，就扩展
			if (num > curprime)getPrime(a);

            //从小到大遍历素数prime[i]，first代表第一个因子
            //如果第一个素因子≠第二个因子，且相乘为原来的数，则是四因子
            //1*first*second=num共四个因子
            //还有一种四因子是1*first*(first*first)=num
			int i = 0, left = num, first = -1;
			while (left > 1 && prime[i] < num)
			{
				if (left%prime[i] == 0)
				{
                    //找到第一个素因子
					if (first == -1)
					{
						first = prime[i];
						left /= prime[i];
					}
					else {
                        //第一种四因子
						if (first != prime[i]&&prime[i]==left)
                        sum += (1 + first + left + num);
                        //第二种四因子
						if (left == first * first)
                        sum += (1 + first + left + num);
                        //第二个因子不符合两种四因子，说明这个数不是四因子
						break;
					}
				}
				else {
					i++;
				}
			}
		}
		return sum;
	}
	void getPrime(int x)
	{
		//计算[curprime+1,x]之间的素数，获得的素数表结在prime后面
		for (int i = curprime + 1; i <= x; i++)
		{
			if (!vis[i])prime.push_back(i);
			int psize = prime.size();
			for (int j = 0; j < psize&&i*prime[j] < 100001; j++)
			{
				vis[i*prime[j]] = 1;
				if (i%prime[j] == 0)break;
			}
		}
        //更新
		curprime = x;
	}
};
```