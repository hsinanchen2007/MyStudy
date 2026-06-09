而这道数学题最难的点就是求一元二次方程的解了。
第一步：
设k为完整分发糖果的轮数。
从第1轮分发糖果开始计算，第(k)轮第i个人（这里i从1开始算）分到的糖果为`(k-1)*n+i`,那么整个第k轮n个人分到的糖果数为`n*(n+1)/2+(k-1)*n*n`,那么前k轮所有人分到的糖果数为`k*n*(n+1)/2+(k-1)*k/2*n*n`，即`(k*k*n*n+k*n)/2`，这个数不比candies大，但若把k替换成k+1，则得到的数又比candies大，所以我们令candies等于这个数，然后算出k向下取整，就是我们要求的k了，即解一元二次方程`k*k*n*n+k*n-2*c=0`，解得`k=(sqrt(1 + 8 * candies) - 1) / (2 * num_people))`，写成这样提交发现有个c为1000000000的样例过不了，然后只好把candies类型转成long long后才成功。
第二步：
然后就好办了，先将糖果发k轮，第i个人拿到`k * (k - 1) * n / 2 + k * i`个糖果。
第三步：
然后从第一个人开始按顺序分发糖果，第i个人发到`k * n + i`个糖果，最后一个人拿剩下的糖果。

PS：当然了，第三步也可以去计算前i个人拿到完整糖果数，第i+1个人没拿到完整糖果数的那个i然后直接计算。但这样还要计算，不如直接模拟分发过程。

```C++ []
class Solution {
public:
	vector<int> distributeCandies(int candies, int num_people) {
		vector<int> v;
		int k = (sqrt(1 + ((long long)candies << 3)) - 1) / (num_people << 1);	//计算所有人发到糖果的轮数
		//计算0~k-1轮每个人获得的糖果
		for (int i = 0; i < num_people; i++) {
			int tmp = k * (k - 1) * num_people / 2 + k * (i + 1);
			v.push_back(tmp);
			candies -= tmp;
		}
		//计算第k轮要发的糖果
		int pos = 0;
		while (candies >= 0) {
			candies -= k * num_people + pos + 1;
			v[pos] += k * num_people + pos + 1;
			pos++;
		}
		v[pos-1] += candies;	//多给了最后那个人-candies个糖果
		return v;
	}
};
```
