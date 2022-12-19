### 解题思路
一次遍历，每次截取10位，判断HashSet中是否存在，不存在则加入到HashSet中

### 代码

```java
class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
        if (s.length() < 10) {
			return new ArrayList<>();
		}
        Set<String> res = new HashSet<String>();
        Set<String> set = new HashSet<String>();
		for (int i = 0; i <= s.length() - 10; i++) {
			String start = s.substring(i, i + 10);
			if (set.contains(start)) {
				res.add(start);
			}else {
				set.add(start);
			}
		}
		
		return new ArrayList<>(res);
    }
}
```