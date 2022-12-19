### 1、思路：
    通过比较s和t中不同字母的个数，如果s中该字母个数与t中该字母个数不相等。
### 2、代码：
```
public char findTheDifference(String s, String t) {
        int[] count = new int[26];
        for (char c: s.toCharArray()){
            count[c - 'a']++;
        }

        int[] countt = new int[26];
        for (char c: t.toCharArray()){
            countt[c - 'a']++;
        }

        for (char c: t.toCharArray()){
            if (countt[c - 'a'] != count[c - 'a']){
                return c;
            }
        }
        return t.charAt(t.length() - 1);
}
```
