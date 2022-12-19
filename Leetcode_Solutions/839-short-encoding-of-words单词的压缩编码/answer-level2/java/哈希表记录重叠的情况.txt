### 解题思路
思路并不复杂，只是会较繁琐。
思路：标记好字符串之间的交叠的情况，被包含的不计入最终编码即可。详解如下：
1. 先去除空字符串，若字符串数组为空，那么返回0即可；
2. 按照字符串的长度，将数组内的所有字符串由大到小排列；
3. 二重循环，这样可以确定所有字符串之间的包含情况，用哈希表记录下标即可。注意，找到一个最大的包含关系即可；举个例子，"abcd","bcd","cd"，只需要记录"abcd"包含"bcd"即可，因为尽管也包含了后面的"cd"，但是"bcd"包含"cd"也会被记录下来，如果全都标记的话，显然HashMap此前的值会被覆盖的；
4. 遍历整个字符串数组，如果下标出现在valueSet中，说明这是一个被包含的字符串，不需要将其加入最终编码中；
5. 具体代码如下，已注释。
### 代码

```java
class Solution {
    public int minimumLengthEncoding(String[] words) {
		// 去除空字符串
		words = this.deleteBlank(words);
		int num = words.length;
		if (num == 0) return 0;
		// 将字符串按长度从大到小排序
		words = this.sort(words);
		// 定义一个HashMap，记录字符串之间的包含情况
		HashMap<Integer, Integer> map = new HashMap<>();
		for (int i=0; i<num-1; ++i) {
			for (int j=i+1; j<num; ++j) {
				// 如果words[i]包含words[j]，将i,j置入map中，且只保留最大包含的
				if (this.isContain(words[i], words[j])) {
				map.put(i, j);
				break;
				}
			}
		}
		String ans = words[0] + "#";
		int[] flag = new int[num];
		for (int i=1; i<num; i++) {
			if (map.containsValue(i)) {
				// 意味着words[i]包含于此前的某个字符串
				flag[i] = 1;
			} else {
				// 未被包含，那么需要将这个字符串加入ans
				ans += words[i] + "#";
			}
		}
		return ans.length();
	}
	// 将字符串数组按照其长度由大到小排序
	private String[] sort(String[] words) {
		int num = words.length;
		for (int i=0; i<num; ++i) {
			int curLen = words[i].length();
			int flag = i;
			for (int j=i; j<num; ++j) {
				if (words[j].length() > curLen) {
					curLen = words[j].length();
					flag = j;
				}
			}
			String tem = words[i];
			words[i] = words[flag];
			words[flag] = tem;
		}
		return words;
	}
	
	// 默认a的长度大于b的长度，且都不为0
	private boolean isContain(String a, String b) {
		int len1 = a.length();
		int len2 = b.length();
		for (int i=len2-1; i>=0; --i) {
			if (b.charAt(i) != a.charAt(i+len1-len2)) return false;
		}
		return true;
	}
	
	// 去除空的字符串
	private String[] deleteBlank(String[] words) {
		int num = words.length;
		if (num == 0) return new String[0];
		List<String> list = new LinkedList<>();
		for (int i=0; i<num; ++i) {
			if (words[i] != "") list.add(words[i]);
		}
		String[] ans = (String[]) (list.toArray(new String[list.size()]));
		return ans;
	}
}
```