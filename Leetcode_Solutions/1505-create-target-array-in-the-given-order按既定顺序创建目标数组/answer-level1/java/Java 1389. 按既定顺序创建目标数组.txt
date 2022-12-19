### 解题思路
1. 因为数组在不断变化，所以新建一个列表`list`，作为存储不断变化的“数组”；
2. 对`nums`和`index`从左到右依次读取，利用列表的`add()`方法，将下标 `index[i]` 处插入值 `nums[i]`；
3. 因为最终返回值是`int`数组，所以新建一个`int`数组`target`；
4. 将`list`转换为`target`；
5. 返回`target`;

### 代码

```java
class Solution {
    public int[] createTargetArray(int[] nums, int[] index) {
        ArrayList<Integer> list = new ArrayList<>();
		for (int i = 0; i < nums.length;i++){
			list.add(index[i],nums[i]);
		}

		int[] target = new int[nums.length];
		for (int i = 0; i < list.size(); i++) {
			target[i] = list.get(i);
		}
        
		return target;
    }
}
```