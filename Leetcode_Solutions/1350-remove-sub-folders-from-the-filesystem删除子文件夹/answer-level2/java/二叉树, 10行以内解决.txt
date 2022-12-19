![无标题.png](https://pic.leetcode-cn.com/0ee1b6d9def98a9d60cda4c99ce152289aff1d7a821eb186f00075b03ccdd390-%E6%97%A0%E6%A0%87%E9%A2%98.png)

### 解题思路
用compartor 定义重复方式为 "包含".
一开始暴力写法一百行还超时, 恶心坏了...

### 代码

```java
class Solution {	
    public List<String> removeSubfolders(String[] folder) {
        Arrays.sort(folder,(s1,s2)->s1.length()-s2.length());
		Set<String> set= new TreeSet<>((s1,s2)->{
			if(s1.contains(s2+"/"))
				return 0;
			return s1.compareTo(s2);
		});
		Collections.addAll(set,folder);
		return new ArrayList<>(set);
    }
}
```