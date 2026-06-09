时间 0ms 100%, 内存 36MB 100%

**思路**
观察可发现每相邻的10x10的正方形区域，区域之间的格子相差的数值都是1(其实就是坐标多了10)，而且数值排列规律一模一样，所以每个区域都可以先减去对应坐标的数值，然后用相同的方法处理。其中计算面积是最快的，剩下的不足10x10的边角也可以计算面积。

![ba7f1bc8fa5604a99e67978cf9c4739a861eba382579776ac35acc8bc42ca042-image.png](https://pic.leetcode-cn.com/069daa0fabce6d5f110d4e46a66c05397325b0a2c3849376724b2dd825419ac9-ba7f1bc8fa5604a99e67978cf9c4739a861eba382579776ac35acc8bc42ca042-image.png)


具体面积计算分有四种：全部面积，三角形，三角形加长方形，全部减去三角形

![image.png](https://pic.leetcode-cn.com/0f415dd1cd72dfd16db759b4e094d1eadf891a34bdba39dd8cbe7d8c203f21a3-image.png)


阻挡问题：
可观察到一个区域往另一个区域的条件就是k >= 9
![image.png](https://pic.leetcode-cn.com/ff5b6f62bb7f6e5a4bcdd58a77fe9b2965b8bdea3c31b3f3c15349a5de0c63c5-image.png)

对边区域也一样
![image.png](https://pic.leetcode-cn.com/59515d56592c292c3befc142254dc80590812e73c852799e5213963ee40b57b0-image.png)



**代码**
```
public int movingCount(int m, int n, int k) {
	int row = m/10, col = n/10;
	// lock 当发现有阻挡时，限制要计算的区域
	int count = 0, lock = m*n; 
	for (int i = 0; i <= row; i++) {
		for (int j = 0; j <= col; j++) {
			if (i + j > lock) break;
			// border 用来代替k，越往外一个区域，该区域的格子数值+1，变相的就是k-1
			int border = k-i-j;
			if (border < 9) { // 小于9时，外面其他区域被挡
				lock = i + j;
			}
			// 还没到达边角
			if (row != i && col != j) {
				count += countArea(10, 10, border);
			}
			// 角区域
			else if (row == i && col == j) {
				count += countArea(m%10, n%10, border);
			}
			// 边区域
			else if (row == i) {
				count += countArea(m%10, 10, border);
			}
			// 边区域
			else if (col == j) {
				count += countArea(10, n%10, border);
			}
		}
	}
	return count;
}

// 具体区域的面积计算
private int countArea(int m, int n, int k) {
	if (k < 0) return 0;
	// 全部
	if (k >= m+n-2) return m*n;
	// 三角形
	else if (k < m && k < n) {
		return (k+1)*(k+2)/2;
	}
	// 分成长方形和三角形
	else if (k < m && k >= n){
		return (k-n+1)*n + n*(n+1)/2;
	}
	else if (k < n && k >= m){
		return (k-m+1)*m + m*(m+1)/2;
	}
	// 全部减去不要的
	else{
		int len = n + m - 2 - k;
		return m*n - len*(len+1)/2;
	}
}
```
