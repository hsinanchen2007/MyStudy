### 解题思路
纯递归 ， Set 去重和保存结构
思想：
1、每次第一个位置与后面所有字符的组合，那么第一个位置所有的组合情况就已经列出
2、固定第一个位置，把第二个位置按照1的思路交换，一次类推
3、当前i后面没有元素可供交换，已经到末尾，添加结果
### 代码

```java
class Solution {
    public String[] permutation(String s) {
		if (s == null || s.length() == 0) {
			return null;
		}
		Set<String> res = new HashSet<>();

		permutationStr(s.toCharArray(), 0, res);

		return res.toArray(new String[0]);

	}

	private void permutationStr(char[] array, int i, Set<String> res) {
		if (i == array.length - 1) {
            res.add(new String(array));
			return ;
		}
		for (int j = i; j < array.length; j++) {
			swap(array, i, j);
			permutationStr(array, i + 1, res);
			swap(array, i, j);
		}
	}

	private void swap(char[] arr, int i, int j) {
		char temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}
```