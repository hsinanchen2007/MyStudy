暴力法，性能比较低，但是能通过，代码简单
为了比较，先排序word，然后遍历s，取总长度的字符串，切割为相同大小，也排序，对比，如果相同就找到了。

```
public List<Integer> findSubstring(String s, String[] words) {
		List<Integer> result = new ArrayList<>();
    	if(words == null || words.length == 0 || words[0].length() == 0){
    		return result;
		}
    	Arrays.sort(words);
		int eachLen = words[0].length();
		int wholeLen = eachLen * words.length;
		for (int i = 0; i <= s.length()-wholeLen; i++) {
			String substring = s.substring(i, i+wholeLen);
			String[] split = split(substring,eachLen);
			Arrays.sort(split);
			if(Arrays.equals(words, split)){
				result.add(i);
			}
		}
		return result;
    }

private String[] split(String s,int n){
    int len = s.length() / n;
    String[] result = new String[len];
    for (int i = 0; i < len; i++) {
        result[i] = s.substring(i*n,(i+1)*n);
    }
    return result;
}
```
