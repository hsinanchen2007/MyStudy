### 解题思路

1 解法：

- hashmap的大小为7，从头开始读入字符，不断加值，每一次进行比较，如果后面字符对应值小于前面的，则进行调整计算 ` 4 = 1+5-2*1 ` ，直到读到最后
- hashmap的大小为13，将所有可能都加进去，每次读一个字符，然后再读一个字符进行判断，在map中找到了就加上，索引变化

2 解法纠错：

- 纠错：第一种解法，比较的是当前字符对应值和前一个字符对应值的大小，因为index一直在走

3 最优解法：

​	解法一，更具有代表性，能解决的问题更多

4 代码精读和补充：

代码对比：

```java
// weak code
String temp = i==s.length()-1? ""+s.charAt(i) : ""+s.charAt(i)+s.charAt(i+1);		
if(map.keySet().contains(temp)) {
	result += map.get(temp);
	i++;
}else {
	result += map.get(s.charAt(i)+"");
}
// STRONG CODE
if(i>0 && map.get(s.charAt(i))>map.get(s.charAt(i-1))) {
	result += map.get(s.charAt(i)) - 2*map.get(s.charAt(i-1));
}else {
	result += map.get(s.charAt(i));
}

```

- map.keySet().contains() 和 map.containsKey()
- s.charAt(i)+s.charAt(i+1) 可以用 s.substring(i,i+2) 表示，取字符串字串总是可以使用substring

### 代码

```java
class Solution {
    public int romanToInt(String s) {
        Map<Character, Integer> map = new HashMap<>();
		map.put('I', 1);
		map.put('V', 5);
		map.put('X', 10);
		map.put('L', 50);
		map.put('C', 100);
		map.put('D', 500);
		map.put('M', 1000);
		
		int result = 0;
		for(int i=0;i<s.length();i++) {
			if(i>0 && map.get(s.charAt(i))>map.get(s.charAt(i-1))) {
				result+=map.get(s.charAt(i))-2*map.get(s.charAt(i-1));
			}else {
				result+=map.get(s.charAt(i));
			}
		}
		return result;
    }
}
```