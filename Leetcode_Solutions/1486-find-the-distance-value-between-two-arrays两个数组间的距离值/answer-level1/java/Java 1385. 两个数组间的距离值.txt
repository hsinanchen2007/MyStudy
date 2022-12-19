### 解题思路
1. 定义一个`count`变量用于计数；
2. 遍历数组`arr1`，同时定义并初始化标志位`flag`为`false`；
3. 遍历数组`arr2`，同时进行判断对于`arr1`，`arr2`中是否存在元素使得`|arr1[i]-arr2[j]|<=d`。如果存在则将标志位置为`true`，同时跳出`arr2`的遍历，继续`arr1`的遍历；
4. 判断标志位`flag`是否为`false`，若是则将`count`加一；
5. 返回`count`值，即为**距离值**；

### 代码

```java
class Solution {
    public int findTheDistanceValue(int[] arr1, int[] arr2, int d) {
        //		用于计数
		int count = 0;
		
//		暴力遍历
		for (int i = 0; i < arr1.length; i++) {
//			设置标志位
			boolean flag = false;
			for (int j = 0; j < arr2.length; j++) {
				if (Math.abs(arr1[i] - arr2[j]) <= d) {
					flag = true;
					break;
				}
			}
			if (flag == false) {
				count +=1;
			}
		}
		return count;
    }
}
```