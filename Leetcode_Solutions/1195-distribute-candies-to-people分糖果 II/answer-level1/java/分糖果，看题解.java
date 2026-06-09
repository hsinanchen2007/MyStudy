欢迎在个人主页查看：[Leetcode 1103. 分糖果 II](https://www.yuque.com/tiantianshuo/coding/distribute-candies-to-people)

首先明确`index` 位置的小朋友获得的糖果数量是 `index+1` (假设糖果无限多的情况)。

由于糖果是有限的，所以本次小朋友获得的糖果数量应该是`curObtain = min(index+1, candies)` 。

本次分发完之后，有如下公式：

小朋友总糖果数量为:`ans[inedx] += curObtain`  

剩余糖果数量:`candies -= curObtain`

代码：

```java
public int[] distributeCandies(int candies, int num_people) {
        int[] ans = new int[num_people];
		int index = 0;
		while (candies > 0) {
			// index位置的小朋友应该得到和index+1数量相等的糖果。但是可能糖果不足index+1，需要取最小值
			int curObtain = Math.min(index + 1, candies);
			ans[index++ % num_people] += curObtain;
			candies -= curObtain;
		}

		return ans;
}
```
