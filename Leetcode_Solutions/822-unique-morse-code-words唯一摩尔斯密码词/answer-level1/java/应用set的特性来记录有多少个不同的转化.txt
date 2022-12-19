### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int uniqueMorseRepresentations(String[] words) {
       String[] Morse ={".-","-...","-.-.","-..",".","..-.","--.","....",
				 "..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.",
				 "...","-","..-","...-",".--","-..-","-.--","--.."};
		int count  = 0;
		String[] MorseWords = new String[words.length];
		//System.out.println(words[0].charAt(1));
		for(int i = 0; i < words.length; i++) {
			for(int j = 0; j < words[i].length(); j++) {
				MorseWords[i] += Morse[words[i].charAt(j) - 97];
			}
		}
		HashSet<String> set = new HashSet<>();
		while(count < MorseWords.length) {
			set.add(MorseWords[count++]);//set不允许有相同的元素，因此借用set来统计不同元素的个数
		}
		return set.size();
    }
}
```