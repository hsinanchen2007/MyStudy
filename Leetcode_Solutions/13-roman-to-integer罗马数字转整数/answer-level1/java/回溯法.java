### 解题思路
将罗马数字和整数的对应关系存入Map。
首先将result+第1位罗马数字对应的整数值，
然后从第二位罗马数字开始遍历：取出前一位（第i-1位）罗马数字对应的整数值，再获得当前罗马数字（第i位）对应的整数值
1.若“前一位的值”大于等于“当前位的值”，直接将result+“当前一位的值”；
2.若“前一位的值”小于“当前位的值”，先将result-“前一位的值”*2，再将result+“当前位的值”。

### 代码

```java
class Solution {
    static Map<Character, Integer> map = new HashMap<>();
	
	static{
		map.put('I', 1);
		map.put('V', 5);
		map.put('X', 10);
		map.put('L', 50);
		map.put('C', 100);
		map.put('D', 500);
		map.put('M', 1000);
	}

    public int romanToInt(String s) {
		int res = 0;
		int length = s.length();
		
		res += map.get(s.charAt(0));
		if(length==1)
			return res;
		
		for(int i=1; i<length; i++){
			int before = map.get(s.charAt(i-1));
			int current = map.get(s.charAt(i));
			if(before<current)
				res -= 2*before;
			
			res += current;
		}
		
		return res;
    }
}
```