### 解题思路

1. 因为事先不知道最终数组有多少个元素，所以先定义一个列表`list`；
2. 然后遍历给定数组的数组对，因为是成对出现，所以遍历次数只需要给定数组长度的一半；
3. 向列表`list`中加入解码的元素（上一步中数组对中的第一个元素作为频次，第二个元素作为数组中出现的数）；
4. 定义一个`int`类型数组`resultArr`作为最终结果；
5. 将`list`转换为`int`数组，即将`list`中数据存入`resultArr`；
6. 返回结果数组`resultArr`；

### 代码

```java
class Solution {
    public int[] decompressRLElist(int[] nums) {
        ArrayList<Integer> list = new ArrayList<>();
		for (int i = 0; i < (nums.length / 2); i++) {
			for (int j = 0; j < nums[i * 2]; j++) {
				list.add(nums[i * 2 + 1]);
			}
		}
		int[] resultArr = new int[list.size()];
		for (int m = 0; m < list.size(); m++) {
			resultArr[m] = list.get(m);
		}
		return resultArr;
    }
}
```