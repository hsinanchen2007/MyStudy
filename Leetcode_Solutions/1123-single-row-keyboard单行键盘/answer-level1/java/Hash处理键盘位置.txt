- 使用哈希存放键盘字母与字母索引
- 输入词拆分，比较当前位置；需要记忆上一个字母所在的位置
- 两个字母比较位置距离时，需要判断字母所在索引位置


```
class Solution {
    public int calculateTime(String keyboard, String word) {
      int result = 0;
		int lstPosition = 0;
		Map<Character, Integer> storeMap = new HashMap<>();
		for (int idx = 0; idx < keyboard.length(); idx++) {
			storeMap.put(keyboard.charAt(idx), idx);
		}
		for (char w : word.toCharArray()) {
			result += Math.max(lstPosition, storeMap.get(w)) - Math.min(lstPosition, storeMap.get(w));
			lstPosition = storeMap.get(w);
		}
		return result;
    }
}
```
