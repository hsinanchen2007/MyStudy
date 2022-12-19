### 解题思路
思路：
1.找到arr2中每个元素在arr1中出现的次数，对于未在 arr2中出现过的元素用一个集合来存储。
2.按照arr2元素的顺序依次填充数组，将集合中存储的元素排序后填充到数组的末尾。


[个人博客地址](http://47.101.136.180/)
### 代码

```java
class Solution {
	public int[] relativeSortArray(int[] arr1, int[] arr2) {
		//哈希表存储arr2中每个元素在arr1中出现的次数 （也可以采用数组来存储，用下标来作为key）
		Map<Integer, Integer> map = new HashMap<>();
		for (int key : arr2)
			map.put(key, 0);

		//存储未在 arr2中出现过的元素
		List<Integer> others = new ArrayList<>();
		
		for (int k : arr1) {
			if (map.containsKey(k)) {
				map.put(k, map.get(k) + 1);
			} else {
				others.add(k);
			}
		}
		
		//结果数组
		int[] ans = new int[arr1.length];
		int index = 0;
		
		//填充arr2中出现的元素
		for (int i = 0; i < arr2.length; i++) {
			for (int j = 0; j < map.get(arr2[i]); j++) {
				ans[index] = arr2[i];
				index++;
			}
		}

		//排序填充arr2中未出现的元素
		Collections.sort(others);
		for (int i = 0; i < others.size(); i++) {
			ans[index] = others.get(i);
			index++;
		}
		return ans;
	}
}


```