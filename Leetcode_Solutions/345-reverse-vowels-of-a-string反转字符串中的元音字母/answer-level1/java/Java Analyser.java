### 解题思路

和反转字符串是一个类型，只是加了一点条件，不过本质都是一样的

这里使用 集合 Set 存储了元音字母的小写，判断时加上 tolowercase 就可以了

关键是元音的下标 i j 如何找，这里使用了循环，不符合条件就一直找，每次还需要判断 i<j ，因为修改了 i j 的值

### 代码

```java
class Solution {
    public String reverseVowels(String s) {
        Set<Character> set = new HashSet<Character>();
		set.add('a');
		set.add('e');
		set.add('i');
		set.add('o');
		set.add('u');
		char[] chars = s.toCharArray();
		int i = 0;
		int j = s.length()-1;
		while(i<=j) {			
			while(i<j && !set.contains(Character.toLowerCase(chars[i])))
				i++;
			while(i<j && !set.contains(Character.toLowerCase(chars[j])))
				j--;
			char temp = chars[i];
			chars[i] = chars[j];
			chars[j] = temp;
			i++;
			j--;
		}
		return new String(chars);
    }
}
```