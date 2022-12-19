### 解题思路
1. 定义一个`int`变量`count`用于计数数组中位数为偶数的数字个数；
2. 遍历数组元素，将其中的每个元素转换为字符串`String`类型；
3. 对转换后的字符串长度进行判断，若字符串长度为偶数，则说明该字符串对应的数字位数为偶数，`count`加一；
4. 遍历结束后，返回`count`即为数组中位数为偶数的数字个数；

### 代码

```java
class Solution {
    public int findNumbers(int[] nums) {
        int count = 0;
		for (int num : nums
		) {
			String strNum = String.valueOf(num);
			if (strNum.length() % 2 == 0) {
				count++;
			}
		}
		return count;
    }
}
```