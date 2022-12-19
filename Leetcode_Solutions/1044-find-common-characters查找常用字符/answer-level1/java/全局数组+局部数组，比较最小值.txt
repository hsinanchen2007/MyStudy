
一个全局数组记录所有字符串中每个字母出现的最小次数，一个局部数组记录每个字符串中每个字母出现的最小次数。
针对每个字符串比较一次全局数组和局部数组，把更小值存入全局数组。（第一个字符串例外，不需要比较，直接存入数据即可。）

```
class Solution {
    public List<String> commonChars(String[] A) {
        List<String> ans = new ArrayList<String>();
        int[] gCount = new int[26];
        for (int i = 0; i < A.length; i++) {
            char[] ca = A[i].toCharArray();
            int[] cCount = new int[26];
            for(int j = 0; j < ca.length; j++) {
                cCount[ca[j]-'a']++;
            };
            for(int j = 0; j < 26; j++) {
                if(i == 0) {
                    gCount[j] = cCount[j];
                } else {
                    if(cCount[j] < gCount[j]) gCount[j] = cCount[j];
                };
            };
        };
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < gCount[i]; j++) ans.add(String.valueOf((char)(i+'a')));
        };
        return ans;
        
    };
}
```
