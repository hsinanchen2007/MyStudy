### 解题思路
此题其实就是一个加法。。。。。。
举例：8*7/6+5-4*3/2+1
原式=8*7/6 +5 +(-4*3/2)+1 即是四个数相加。
对于任意的K=4N N=N+  来说，N*(N-1)/(N-2)+(N-3)可视为两数相加
把这两个数依次存入vector容器里，最终相加就可以了。
但要注意的地方是，此过程的第二个阶段开始前面有负号，设置一个条件就好了。
对于N除4的余数会有四种情况 0，1，2，3
	a)0:4*3/2+1 尾数tail=0
	b)1:5*4/3+2-1 把-1视为尾数tail,tail=-1
	c)2:6*5/4+3-2*1 把-2*1视为尾数tail,tail=-2
	d)3:7*6/5+4-3*2/1,把-3*2/1视为尾数tail,tail=-6
最后加上tail即是所求。
注意，当N<4时，tail部分没有负号，记得乘上一个-1.
### 代码

```cpp
class Solution {
public:
	int clumsy(int N) {
		int sum = 0; //结果
		int apN = N; //apN是循环变量
		vector<int> values;
		while (apN >= 4) {
			int temp = apN * (apN-1) / (apN-2);  //计算第一个加数的值
			if (apN != N) temp = temp * (-1);  //第二次循环开始第一个加数为负
			values.push_back(temp);
			values.push_back(apN - 3);  //第一个加数第二个加数放入容器
			apN = apN - 4;
		}
		int tail = 0;
		switch (N % 4) {
		case 1: {tail = -1; break; }
		case 2: {tail = -2; break; }
		case 3: {tail = -6; break; }  //计算尾数的值
		default:break;
		}
		if (N < 4) tail = -1 * (tail);  //N<4,尾数为正
		for (vector<int>::iterator it = values.begin(); it != values.end(); it++)
			sum += *it;
		sum += tail;  //累加
		return sum;
	}
};
```