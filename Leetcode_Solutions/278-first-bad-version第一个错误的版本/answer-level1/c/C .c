### 解题思路
此处撰写解题思路
执行用时 :0 ms, 在所有 C 提交中击败100.00%的用户
内存消耗 :6.7 MB, 在所有 C 提交中击败了86.39%的用户
对我而言我觉得这题最难的地方就是题意了，开始就一直不明白正确的为啥用false，然后第一个错的是ture。逻辑绕了半天。最后看了官方图解才明白理解错了。服气这另类的起名方式
### 代码

```c
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int firstBadVersion(int n) {
	int left = 1, mid, right = n;
	mid = left + (right - left) / 2;
	for (;left!=right;)
	{
		if (isBadVersion(mid))
			right = mid;
		else 
			left = mid + 1;
		mid = left + (right - left) / 2;
	}
	return mid;
}
```