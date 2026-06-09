### 解题思路
题目：实现一个算法，确定一个字符串 s 的所有字符是否全都不同。
分析题意：
   注意:此方法简单，用于小数据量，解决小的应用场景。
   1：找出字符串中是不是有重复的
解题：
   1：用最简单粗暴的java中的结合特性，list集合元素可重复，set结合不可重复。
   2：字符串转list后，再转set，对比list和set的长度，得正解。

### 代码

```java
class Solution {
    public boolean isUnique(String astr) {
        List<String> asList = Arrays.asList(astr.split(""));
		Set<String> set=new HashSet<>(asList);
        if (asList.size()!=set.size()) {
			return false;
		}else{
			return true;
		}
    }
}
```