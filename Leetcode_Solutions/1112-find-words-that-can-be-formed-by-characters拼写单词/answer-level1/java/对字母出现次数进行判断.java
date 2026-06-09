### 解题思路
对字母出现次数进行判断，如果字母表中字母出现次数小于单词中字母出现次数，则说明该单词有字母不在字母表中

### 代码

```java
class Solution {
    public int countCharacters(String[] words, String chars) {
		// 统计字母表中的字母出现次数
		int[] charsCount = count(chars);
		// 结果
		int res = 0;
		// 对词汇表中的每一个单词进行判断
		for (String word : words) {
			// 统计当前单词中的字母出现次数
			int[] wordCount = count(word);
			// 如果chars包含当前单词，则更新res
			if (contains(charsCount, wordCount)) {
				res += word.length();
			}
		}

		return res;
	}

	/**
	 * 比较字母表中字母出现次数和单词中字母出现次数
	 * 如果单词中字母出现次数大于字母表中字母出现次数，则立刻返回false
	 *
	 * @param charsCount 字母表中字母出现次数
	 * @param wordCount  单词中字母出现次数
	 * @return 返回是否包括
	 */
	private boolean contains(int[] charsCount, int[] wordCount) {
		for (int i = 0; i < 26; i++) {
			if (charsCount[i] < wordCount[i]) {
				return false;
			}
		}
		return true;
	}


	/**
	 * 统计单词中26个字母出现的次数
	 *
	 * @param word 单词
	 * @return 出现的次数
	 */
	private int[] count(String word) {
		int[] counter = new int[26];
		char c;
		for (int i = 0; i < word.length(); i++) {
			c = word.charAt(i);
			counter[c - 'a']++;
		}
		return counter;
	}
}
```