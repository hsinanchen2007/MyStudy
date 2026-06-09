□ 假设有一个数组: 1,2,...,n; 此时只有 1 种间隔;
□ 
![1.jpg](https://pic.leetcode-cn.com/5c1258de5a46299eb49f4ba3d3c71b255b2421763f4df16b6380e71f97746993-1.jpg)
□ 可以发现每次反转会多出一种间隔，k 种间隔就反转 k 即可；
□ 进一步观察发现;如果需要 k 个不同的间隔；
    ® 前 k 个数需要间隔从两端取；
    ® 剩下的数字则按照降序或者升序排列；

```java []
class Solution {
    public int[] constructArray(int n, int k) {
		int[] arr = new int[n];
		int l = 1, r = n;

		// 前 k 个数需要间隔从两端取；
		int i = 0;
		while (true) {
			if(i < k) { arr[i] = l; i++; l++; } else break;
			if(i < k) { arr[i] = r; i++; r--; } else break;
		}
		
		// 剩下的数字则按照降序或者升序排列；
		if(k % 2 == 1) {
			for (int j = k; j < arr.length; j++) {
				arr[j] = l;
				l++;
			}
		} else {
			for (int j = k; j < arr.length; j++) {
				arr[j] = r;
				r--;
			}
		}
		return arr;
	}
}
```
```
