### 解题思路
- 时间复杂度：O(n)
- 空间复杂度：O(n)
- 思路：简单的等差数列求和！

### 代码

```java
class Solution {
	public int[] distributeCandies(int candies, int num_people) {
		int[] res = new int[num_people];
		if (candies == 0 || num_people == 0)
			return res;
		int n = 0, left = 0, shang, yu;
		while (((n + 1) * n >> 1) < candies)
			n++;
		if (((n + 1) * n >> 1) > candies) {
			n--;
			left = candies - ((n + 1) * n >> 1);
		}
		shang = n / num_people;
		yu = n % num_people;
		for (int i = 0; i < num_people; i++) {
			if (n < num_people) { // 直接填充
				if (candies > i + 1) {
					res[i] = i + 1;
					candies -= i + 1;
				} else {
					res[i] = candies;
					candies = 0;
				}
			} else {
				if (yu > 0) { // 等差数列求和
					res[i] = num_people * ((shang + 1) * shang >> 1) + (i + 1) * (shang + 1);
					yu--;
				} else {
					res[i] = num_people * ((shang - 1) * shang >> 1) + (i + 1) * shang;
					if (left > 0) { // 若有剩余糖果，则直接累加
						res[i] += left;
						left = 0;
					}
				}
			}
		}
		return res;
	}
}
```