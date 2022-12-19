### 解题思路
其实并不复杂，四个数得到24，先分成两组，分法有两种情况，
第一种情况是，每组两个数，两两先算，最后统计是否能成功
第二种情况是，一组三个数一组一个数，统计
注意的是两个数的运算其实有6中情况,a+b,a-b,b-a,a*b,a/b,b/a
注意分母为零的情况即可
### 代码

```cpp
class Solution {
public:
	//判断两个数a,b能否计算得到res
	bool twoNums(int a, int b, double res) {
		double aa = a;
		double bb = b;
		if (bb != 0 && abs(aa / bb - res) <= 0.001) return true;
		if (aa != 0 && abs(bb / aa - res) <= 0.001) return true;
		if (abs(aa*bb-res)<=0.001 || abs(aa+bb - res) <= 0.001 || 
			abs(aa-bb - res) <= 0.001 || abs(bb-aa - res) <= 0.001)
			return true;
		else  return false;
	}
	//判断三个数能否得到res
	bool threeNums(int a, int b, int c, double res) {
		//减法：
		if (twoNums(b, c, (double)a - res) || twoNums(b, c, (double)a + res) ||
			twoNums(a, b, (double)c - res) || twoNums(a, b, (double)c + res) ||
			twoNums(a, c, (double)b - res) || twoNums(a, c, (double)b + res)) return true;

		//除法：
		if (res!=0&&(twoNums(b, c, (double)a / res) || twoNums(b, c, (double)a / res) ||
			twoNums(a, b, (double)c / res) || twoNums(a, b, (double)c / res) ||
			twoNums(a, c, (double)b / res) || twoNums(a, c, (double)b / res))) return true;

		//加法：
		if (twoNums(b, c, res - (double)a) || 
			twoNums(a, b, res - (double)c) || 
			twoNums(a, c, res - (double)b ) ) return true;

		//乘法
		if ((a!=0&&twoNums(b, c, res / (double)a)) ||
			(c!=0&&twoNums(a, b, res / (double)c)) ||
			(b!=0&&twoNums(a, c, res / (double)b))) return true;
		return false;
	}
	bool judgePoint24(vector<int>& nums) {
		
		//情况1：一组3个数，一组1个数
		int a[4];
		a[0]= nums[0], a[1] = nums[1], a[2] = nums[2], a[3] = nums[3];
		for (int i = 3; i >= 0; i--) {
			swap(a[3], a[i]);
			int a1 = a[0], a2 = a[1], a3 = a[2], a4 = a[3];
			if (threeNums(a1, a2, a3, a4 - 24.0) || threeNums(a1, a2, a3, 24.0 + a4) ||
				threeNums(a1, a2, a3, 24.0 - a4) || threeNums(a1, a2, a3, 24.0 / a4) ||
				threeNums(a1, a2, a3, a4 / 24.0) || threeNums(a1, a2, a3, 24.0*a4)) return true;
		}

		//情况二：每组都是两个数，这种情况比较复杂
		int index1[3] = { 0,0,0 };
		int index2[3] = { 1,2,3 };
		int index3[3] = { 2,1,1 };
		int index4[3] = { 3,3,2 };
		for (int i = 0; i < 3; i++) {
			int a1 = nums[index1[i]];
			int a2 = nums[index2[i]];
			int a3 = nums[index3[i]];
			int a4 = nums[index4[i]];
			
			double f34 = a3 + a4;
			if (twoNums(a1, a2, 24-f34) || twoNums(a1, a2, 24+f34) || twoNums(a1, a2, f34-24) ||
				twoNums(a1, a2, f34/24) || twoNums(a1, a2, f34*24) || twoNums(a1, a2,24/f34))
				return true;

			f34 = a3 - a4;
			if (a3 == a4) {
				if ((twoNums(a1, a2, 24) || twoNums(a1, a2, -24))) return true;
			}
			else if (twoNums(a1, a2, 24 - f34) || 
				twoNums(a1, a2, 24 + f34) ||
				twoNums(a1, a2, f34 - 24) ||
				twoNums(a1, a2, f34 / 24) || 
				twoNums(a1, a2, f34 * 24) ||
				twoNums(a1, a2, 24 / f34))
				return true;

			f34 = a4-a3;
			if (a3 == a4) {
				if ((twoNums(a1, a2, 24) || twoNums(a1, a2, -24))) return true;
			}
			else if (twoNums(a1, a2, 24 - f34) ||
				twoNums(a1, a2, 24 + f34) ||
				twoNums(a1, a2, f34 - 24) ||
				twoNums(a1, a2, f34 / 24) ||
				twoNums(a1, a2, f34 * 24) ||
				twoNums(a1, a2, 24 / f34))
				return true;

			f34 = (double)a3 / (double)a4;
			if (twoNums(a1, a2, 24 - f34) || twoNums(a1, a2, 24 + f34) || twoNums(a1, a2, f34 - 24) ||
				twoNums(a1, a2, f34 / 24) || twoNums(a1, a2, f34 * 24) || twoNums(a1, a2, 24 / f34))
				return true;

			f34 = (double)a4 / (double)a3;
			if (twoNums(a1, a2, 24 - f34) || twoNums(a1, a2, 24 + f34) || twoNums(a1, a2, f34 - 24) ||
				twoNums(a1, a2, f34 / 24) || twoNums(a1, a2, f34 * 24) || twoNums(a1, a2, 24 / f34))
				return true;

			f34 = a3 * a4;
			if (twoNums(a1, a2, 24 - f34) || twoNums(a1, a2, 24 + f34) || twoNums(a1, a2, f34 - 24) ||
				twoNums(a1, a2, f34 / 24) || twoNums(a1, a2, f34 * 24) || twoNums(a1, a2, 24 / f34))
				return true;
		}
		return false;
	}
};
```