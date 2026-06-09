### 解题思路
1. 解法1：直接对字符串进行操作
2. 解法2：自动机的思想

解法1：
1. 从前扫描字符串，若遇上空格，跳过；
2. 遇上数字，ans = 10 * ans + digit，其中digit = str.charAt(i) - '0'；
3. 判断是否越界：判断条件为ans > ( Integer.MAX_VALUE - digit ) / 10；
4. 若中途遇上其它字符，结束。

解法2：
1. 构建自动机，有START、SIGNED、IN_NUM、END四个状态，跳转关系可由题意得到；
2. 将跳转关系存入HashMap<String, String[]>中；
3. 跳转函数核心，state = map.get(state)[jump(c)]；
4. 从关开始遍历字符串，观察自动机进入哪个状态；
5. 同样，需要注意越界的情况。

### 代码

```java
class Solution {
    public int myAtoi(String str) {
		HashMap<String, String[]> map = new HashMap<>();
		map.put("START", new String[] {"START","SIGNED","IN_NUM","END"});
		map.put("SIGNED", new String[] {"END","END","IN_NUM","END"});
		map.put("IN_NUM", new String[] {"END","END","IN_NUM","END"});
		map.put("END", new String[] {"END","END","END","END"});
		String state = "START";
		
		int index = 0;
		int flag = 1;
		int ans = 0;
		while (index < str.length()) {
			char c = str.charAt(index);
			state = map.get(state)[jump(c)];
			index ++;
			if (state == "END") break;
			else if (state == "SIGNED" && c == '-') flag = -1;
			else if (state == "IN_NUM") {
				int digit = c - '0';
				if (ans > (Integer.MAX_VALUE - digit) / 10) 
					return flag == -1 ? Integer.MIN_VALUE : Integer.MAX_VALUE;
				ans = ans * 10 + digit;
			}
			else continue;
		}
		return flag * ans;
	}
	
	private int jump(char c) {
		if (c == ' ') return 0;
		else if (c == '+' || c == '-') return 1;
		else if (c >= '0' && c <= '9') return 2;
		else return 3;
	}
    
}
```