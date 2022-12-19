### 解题思路
两个人分别猜三次。将每次的结果分别保存到各自的数组中。每次比较同位置的元素。是否相等。相等计数加一。不想等数组下标加一。
终止条件为数组下标step小于数组长度3。即小于等于2。遍历结束后返回计数值。

### 代码

```java
class Solution {
    public int game(int[] guess, int[] answer) {
        int step=0;
		int count=0;
		while(step<=2) {
			if(answer[step]==guess[step]) {
				count++;
				step++;
			}
			else {
				step++;
			}
		}
		return count;
    }
}
```