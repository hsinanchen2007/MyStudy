用两个HashMap<Character,Integer>比较是否一样
map1存储的是p，map2存储是s的一部分


第一次写的时候，在验证很长的字符串的时候错了
```java
public static boolean vs(HashMap<Character,Integer>  map1,HashMap<Character,Integer>  map2)
	{
		for(Character c:map1.keySet())
			if(map2.getOrDefault(c, 0)!=(map1.get(c)))
				return false;
		return true;
	}
```
第二次写的时候，成了
```java
public static boolean vs(HashMap<Character,Integer>  map1,HashMap<Character,Integer>  map2)
	{
		for(Character c:map1.keySet())
			if(!map2.getOrDefault(c, 0).equals(map1.get(c)))
				return false;
		return true;
	}
```
注意，Integer不要直接用==，而是用.equals，这样才能对
因为java有常量池在IntegerCache.java，它缓存了从-128到127之间的所有的整数对象。
这个时候用==是可以的，但是超过这个范围==返回的是false

