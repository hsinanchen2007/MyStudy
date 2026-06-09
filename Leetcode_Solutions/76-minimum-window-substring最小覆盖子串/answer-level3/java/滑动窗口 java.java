### 1. 题目
给你一个字符串 `S`、一个字符串 `T`，请在字符串 `S `里面找出：包含 `T `所有字母的最小子串。

示例：

输入: `S = "ADOBECODEBANC"`, `T = "ABC"`
输出: `"BANC"`
说明：

如果 `S` 中不存这样的子串，则返回空字符串 `""`。
如果 `S` 中存在这样的子串，我们保证它是唯一的答案。

链接：https://leetcode-cn.com/problems/minimum-window-substring

### 2. 思路
(1) 对于这类求子串问题，首先想到的方法就是`滑动窗口`，即通过双指针先后遍历字符串，在遍历过程中对当前`窗口`进行判断，当满足条件时更新记录，直至遍历完成。

![滑动窗口.jpg](https://pic.leetcode-cn.com/6ebb10a87ed61334db4c294f56f842d1b83c7373a118a6f011980e9af098ebf8-%E6%BB%91%E5%8A%A8%E7%AA%97%E5%8F%A3.jpg)

(2) 那么如何在搜索过程中确定当前窗口是否满足条件呢？众所周知，hash表的查找速度是最快的，我们尝试使用hash表将目标字符和需求出现次数做一个映射，例如`T=“AAABBC”`，那么建立映射<br/> `MAP:{A:3, B:2, C:1}`，在头指针前进过程中，若头指针所指向元素存在于`MAP`中，则使对应元素映射值-1，当所有映射值小于零的时候（在满足条件之前可能有的映射值会变为负数，为缩短条件判断时间，采用一个变量记录归零值的数量，当该变量等于`MAP`的长度时，条件被满足），认为当前窗口符合条件，开始窗口收缩(尾指针开始追赶)，尾指针指向元素存在于`MAP`中时，使映射值+1，当任意映射值大于零时，就获得了一个最小窗口。继续移动头指针，开始下一轮的搜索。

### 3. 代码
```java
class Solution {
	public String minWindow(String s, String t) {

		if (s.length() == 0 || t.length() == 0) {
			return "";
		}

		// 建立映射计数
		Map<Character, Integer> temp = new HashMap<>();

		for (char c : t.toCharArray()) {
			temp.put(c, temp.getOrDefault(c, 0) + 1);
		}

		// 字符串转换为数组
		char[] ss = s.toCharArray();

		// 建立双指针
		int head = 0, tail = 0;

		// 记录最小宽度 以及当时尾指针位置
		int min = s.length();
		int mt = -1;

		// 开始搜索
		for (int size = temp.size(); head < s.length(); head++) {
			// 计数搜寻（头指针向后移动）
			if (temp.keySet().contains(ss[head])) {
				Integer num = temp.get(ss[head]);
				temp.put(ss[head], num - 1);
				if (num == 1)
					size--;
			}

			// 缩小范围（当窗口满足条件，尾指针开始追赶;不满足条件时停止追赶）
			if (size == 0) {
				do {
					if (temp.keySet().contains(ss[tail])) {
						Integer num = temp.get(ss[tail]) + 1;
						temp.put(ss[tail], num);
						if (num == 1)
							size++;
					}
					tail++;
				} while (size == 0);

				// 记录最小值
				if (head - tail + 1 < min) {
					mt = tail - 1;
					min = head - mt;
				}
			}
		}

		return mt == -1 ? "" : s.substring(mt, mt + min + 1);
	}
}

```
### 4. 复杂度
设 `m` 为 `T` 的长度，`n` 为 `S` 的长度

时间复杂度：`O(m+n)`
空间复杂度：`O(n)`