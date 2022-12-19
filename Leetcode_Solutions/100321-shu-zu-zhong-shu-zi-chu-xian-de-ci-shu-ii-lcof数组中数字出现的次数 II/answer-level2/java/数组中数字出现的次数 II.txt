### 解题思路
将num的（元素——及其出现的次数）存入hashmap中，对应key——value
遍历hashmap，找到value=1的键即是答案
### 代码

```java
class Solution {
    public int singleNumber(int[] nums) {
        Map<Integer,Integer> map=new HashMap<Integer,Integer>();
		for(int num:nums) {
			map.put(num, map.getOrDefault(num, 0)+1);
		}
		for(Object key:map.keySet()) {
			if(map.get(key).equals(1))  return (int) key;
		}
		return 0;
    }
}
```