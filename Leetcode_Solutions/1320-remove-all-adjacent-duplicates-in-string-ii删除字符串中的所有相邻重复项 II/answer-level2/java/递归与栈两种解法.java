# 递归
竞赛的时候用的是递归不断扫描S存在重复的字符串位置，用list记录下标，然后拼接成一个新的字符串，递归，直到list为空证明无符合的重复
时间复杂度： 最好的情况 O(N) 最差 O(N* N/K ) 例如 ABCCBA这种要递归3次
空间复杂度： O(N)
```
class Solution {
    	public String removeDuplicates(String s, int k) {
		// 无限删除的问题 统计连续字母达到K的坐标
		while (true) {
			List<List<Integer>> allList = checkStr(s, k);
			if (allList.size() == 0)
				return s;
			else {
				StringBuffer sb = new StringBuffer();
				int ss = 0;
				for (List<Integer> list : allList) {
					String newS = s.substring(ss, list.get(0));
					ss = list.get(1) + 1;
					sb.append(newS);
				}

				String lastStr = s.substring(ss, s.length());
				sb.append(lastStr);
				s = sb.toString();
			}
		}
	}

	private List<List<Integer>> checkStr(String s, int k) {
		int start = 0, len = 1;
		List<List<Integer>> allList = new ArrayList<>();
		while (start < s.length() - 1) {
			if (s.charAt(start) == s.charAt(start + 1)) {
				len++;
			} else {
				len = 1;
			}

			if (len == k) {
				List<Integer> list = new ArrayList<>();
				list.add(start + 2 - k);
				list.add(start + 1);
				allList.add(list);
				start = start + 2;
				len = 1;
			} else
				start++;
		}

		return allList;
	}

}
```

# 用栈计数
时间复杂度 O(N) 空间复杂度O(N) ,不过奇怪的是这种提交用了60ms，递归反而只用了 9ms
```
class Solution {
    	public String removeDuplicates(String s, int k) {
		Stack<Integer[]> stack = new Stack<>();

		for (char c : s.toCharArray()) {
			int index = 1, ch = c - 'a';

			if (!stack.isEmpty() && stack.peek()[0] == ch) {
				index = stack.peek()[1] + 1;
			}

			stack.push(new Integer[] { ch, index });
			if (stack.peek()[1] == k) {
				for (int i = 0; i < k; i++) {
					stack.pop();
				}
			}
		}

		// 拼接
		StringBuffer sb = new StringBuffer();
		for (Integer[] integers : stack) {
			sb.append((char) (integers[0] + 'a'));
		}
		return sb.toString();
	}

}
```
