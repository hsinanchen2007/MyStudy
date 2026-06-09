### 解题思路
0ms，思路清晰，直接打表。 代码15行左右

### 代码

```java
class Solution {
    String[] keyboards = {"QWERTYUIOPqwertyuiop", "ASDFGHJKLasdfghjkl", "ZXCVBNMzxcvbnm"};
    
    public String[] findWords(String[] words) {
        if (words.length == 0) return new String[0];
        List<String> rs = new ArrayList<>(words.length);
		for (String keyborad : keyboards) {
			for (String word : words) {
				boolean flag = true;
				for (char c : word.toCharArray())
					if (keyborad.indexOf(c) < 0) {
						flag = false;
						break;
					}
				if (flag) rs.add(word);
			}
		}
        int sz;
        String[] res = new String[(sz = rs.size())];
        for (int i = 0; i < sz; ++i)
            res[i] = rs.get(i);
		// return rs.stream().toArray(String[]::new); 流式计算速度低于显示遍历
        return res;
    }
}
```