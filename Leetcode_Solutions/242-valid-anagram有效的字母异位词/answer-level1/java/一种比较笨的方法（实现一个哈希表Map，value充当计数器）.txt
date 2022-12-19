执行结果：通过	显示详情 
执行用时 :28 ms, 在所有 Java 提交中击败了15.09%的用户
内存消耗 :41.7 MB, 在所有 Java 提交中击败了5.00%的用户
### 解题思路
1、实现一个哈希表HashMap	`Map<Character, Integer>`
2、接着遍历字符串s，为字符串中每个字符进行计数
3、然后遍历字符串t，map中存在该字符则对应地减一，若不存在可直接返回false
4、为应对map的value中存在负数的问题，还应将map的value转换为数组从而进行遍历确认

### 代码

```java
class Solution {
    public boolean isAnagram(String s, String t) {
        	if(s.length() != t.length()) {
			return false;
		}
		Map<Character, Integer> map = new HashMap<>();
		for(int i = 0; i <= s.length()-1; i++) {
			if(map.containsKey(s.charAt(i))) {
				map.replace(s.charAt(i), map.get(s.charAt(i)), map.get(s.charAt(i))+1);
				continue;
			}
			map.put(s.charAt(i), 1);
		}
		for(int i = 0; i <= t.length()-1; i++) {
			Character ch = t.charAt(i);
			if(!map.containsKey(ch)) {
				return false;
			}else {
				map.replace(ch, map.get(ch), map.get(ch)-1);
			}
		}
		Object[] objs = map.values().toArray();
		Integer integer = 0;
		for(int i = 0; i <= objs.length-1; i++) {
			if(!objs[i].equals(integer)) {
				return false;
			}
		}
		return true;
    }
}
```