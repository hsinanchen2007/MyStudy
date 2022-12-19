### 解题思路
1. 定义一个集合`set`(集合中元素不重复)，同时定义一个最终返回值`result`；
2. 遍历数组元素，将其加入到集合`set`中；
3. 对加入的元素进行判断，若集合中已存在，则将这个数赋给`result`，同时结束循环；
4. 返回`result`；

### 代码

```java
class Solution {
    public int findRepeatNumber(int[] nums) {
        Set<Integer> set = new HashSet<Integer>();
		int result = 0;
		for (int num : nums
		) {
			if (set.add(num) == false) {
				result = num;
				break;
			}
		}
		return result;
    }
}
```