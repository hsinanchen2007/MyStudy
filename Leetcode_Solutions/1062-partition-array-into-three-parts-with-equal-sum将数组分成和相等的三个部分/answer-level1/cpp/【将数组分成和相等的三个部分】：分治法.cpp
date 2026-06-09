![image.png](https://pic.leetcode-cn.com/4326b526f9befeb37eecec1de2f42b14f6ec39685b138661b5cebab740c979bb-image.png)

**思路**
    题目要求将数组分成和相等的三个部分，我们可以先将判断数组是否存在前面一段的和的两倍等于后面一段的情况，如果有，则判断后一段是否存在两段和相等的情况。
    因为前后两次判断只有一个倍数的区别，所以设置一个变量flag即可使用递归方法解答。空间方面有待优化~
```
class Solution {
public:

	// 递归解法
	bool canThreePartsEqualSum(vector<int>& A) {
		int sum = accumulate(A.begin(), A.end(), 0);
		if (sum % 3 != 0) 
			return false;

		return check(A, 2, sum);
	}

	bool check(vector<int>& A, int flag, int sum) {
		int add = 0;  
 
		for (int i = 0; i < A.size() - 1; i++) {
			add += A[i];
			sum -= A[i]; 
			if (add * flag == sum) {
				if (flag == 2) { 
					vector<int> B(A.begin() + i + 1, A.end()); 
					return check(B, 1, sum);
				}
				else {
					return true;
				}
			}
		} 
		return false;
	}
};
```
