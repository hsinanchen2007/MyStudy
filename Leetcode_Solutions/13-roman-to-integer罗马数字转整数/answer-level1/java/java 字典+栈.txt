```java []
class Solution {
    public int romanToInt(String s) {
        int result = 0;
		HashMap<String, Integer> map = new HashMap<String, Integer>();
		map.put("I", 1);
		map.put("V", 5);
		map.put("X", 10);
		map.put("L", 50);
		map.put("C", 100);
		map.put("D", 500);
		map.put("M", 1000);
		
		char [] array = s.toCharArray();
		Stack<Character> stack = new Stack<Character>();
		for (char a: array) {
			stack.push(a);
		}
		
		char head = stack.pop();
		int top = map.get(head + "");
		result += top;
		while(!stack.isEmpty()) {
			char prev = stack.pop();
			int next = map.get(prev + "");
            // 如果左边的比右边的小，减掉左边的值，反之加左边的值
            // 三目运算符改为if分支，速度会更快些
            result = top > next ? result - next : result + next;
			top = next;
		}
        return result;
    }
}
```

