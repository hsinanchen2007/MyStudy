### 解题思路
每一位与后一位进行比较，如果大于或等于后一位，最终结果就加上这一位，else结果就减去这一位。
还回留最后一位，无论如何都是被加上的。

### 代码

```java
class Solution {
    public int romanToInt(String s) {
        		int result = 0;
		Map<Character,Integer> map = new HashMap<>();
		map.put('I',1);
		map.put('V',5);
		map.put('X',10);
		map.put('L',50);
		map.put('C',100);
		map.put('D',500);
		map.put('M',1000);
		
		for(int i=1;i<s.length();i++) {
			if((map.get(s.charAt(i-1))>map.get(s.charAt(i)))||(map.get(s.charAt(i-1))==map.get(s.charAt(i)))){
				result = result +map.get(s.charAt(i-1));
			}else {
				result = result - map.get(s.charAt(i-1));
			 }
		}
		result = result + map.get(s.charAt(s.length()-1));
		return result;
    }
}
```