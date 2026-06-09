首先观察4位的格雷码，找到规律：
0	0	0	0
0	0	0	1
0	0	1	1
0	0	1	0
0	1	1	0
0	1	1	1
0	1	0	1
0	1	0	0
1	1	0	0
1	1	0	1
1	1	1	1
1	1	1	0
1	0	1	0
1	0	1	1
1	0	0	1
1	0	0	0

先定义一个大小为2^n的vector，然后从最高位第n位递归开始赋值，在递归中，每次将需要填充的元素分为两部分，第前半部分的最高位填0，后半部分的第n填1，然后填0的部分记为m1,填1的部分记为m2。进入下次递归的话，m1的前半部分的第n-1位填0，后半部分的第n-1位填1，而m2的前半部分的第n-1位填1，后半部分的第n-1位填0，；
所以定义了两个函数，trackback表示前半部分填0，后半部分填1，trackback_reverse表示前半部分填1，后半部分填0；
代码如下所示：
	vector<int> grayCode(int n) {
		int total = 1;
		for (int i = 0; i<n; i++)
			total *= 2;
		vector<int> ans(total, 0);
		trackback(ans, n - 1, 0, total - 1);
		return ans;
	}
	void trackback(vector<int>& ans, int n, int left, int right)
	{
		if (n<0)
			return;
		int m1 = (1 << n);
		int mid = (left + right) / 2;
		for (int i = mid + 1; i <= right; i++)
			ans[i] = (ans[i] | m1);
		trackback(ans, n - 1, left, mid);//对前一半进行迭代，因为前一半的第n-1位应该是先0后1;
		trackback_reverse(ans, n - 1, mid + 1, right);//对后一半进行迭代，第n-1位是先1后0；
	}
	void trackback_reverse(vector<int>& ans, int n, int left, int right)
	{
		if (n<0)
			return;
		int m1 = (1 << n);
		int mid = (left + right) / 2;
		for (int i = left; i <= mid; i++)
			ans[i] = (ans[i] | m1);
		trackback(ans, n - 1, left, mid);//对前一半进行迭代，因为前一半的第n-1位应该是先0后1;
		trackback_reverse(ans, n - 1, mid + 1, right);//对后一半进行迭代，第n-1位是先1后0；
	}