解题思路：同列不同行两数比较，若前者大于后者，即为升序，计数跳出循环。
其实个人觉得本题的非降序排序还是有歧义，之前一直是计算降序序列，再用数组长度减去该数反而错了，就这么写了。。。

![image.png](https://pic.leetcode-cn.com/42c00cffdeb61547b9a4940dcddb1da268c50676716531952e2a8cbd76260cad-image.png)

int minDeletionSize(vector<string>& A) {
          int res = 0;
	for (int j = 0; j<A[0].size(); ++j) {
		for (int i = 0; i<A.size() - 1; ++i){
			if (A[i][j]>A[i + 1][j]) {
				++res;break;
			}
		}
	//	if (flag == 1) { ++count; flag = 0; }
	}
	return res;
}