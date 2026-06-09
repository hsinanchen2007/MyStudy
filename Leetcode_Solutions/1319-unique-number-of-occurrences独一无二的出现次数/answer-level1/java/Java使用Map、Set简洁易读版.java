1. HashMap统计每个数字出现了几次
2. HashSet统计value是否重复出现,第一次出现重复直接false

<br>
```java
class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        
		Map<Integer, Integer> countMap = new HashMap<Integer, Integer>();
		//统计每个数字出现了几次
		for (int a : arr) {
			//getOrDefault:不存在该key会返回0，否则返回对应value
			countMap.put(a, countMap.getOrDefault(a, 0) + 1);
		}

		Set<Integer> set = new HashSet<>();
		//set统计value是否重复出现
		for (Integer val : countMap.values()) {
			if (!set.add(val)) {//若已存在该value，add返回false
				return false;
			}
		}
		return true;
    }
}
```
