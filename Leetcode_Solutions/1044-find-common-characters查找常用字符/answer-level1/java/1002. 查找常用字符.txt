
用一个数组count存放每个字符串中都重复的字符个数，用数组currCount计算当前字符串都出现字符的总个数，然后比较一下两个数组count和currCount中谁的次数更少（取交集）。时间复杂度O(n+m)
```
    public static List<String> commonChars(String[] A) {
        List<String> ans = new ArrayList<>();
        int[] count = new int[26]; // 每个字符串中都重复的字符个数
        for (int i = 0; i < 26; i++) {
            count[i] = 101;
        }
        for (int i = 0; i < A.length; i++) {
            String s = A[i];
            int[] currcount = new int[26]; // 当前字符串中存在的字符个数
            for (int j = 0; j < s.length(); j++) {
                char c = s.charAt(j);
                currcount[c - 97]++;
            }
            for (int j = 0; j < 26; j++) {
                if (currcount[j] < count[j]) {
                    count[j] = currcount[j];
                }
            }
        }
        for (int i = 0; i < 26; i++) {
            int amount = count[i];
            for (int j = 0; j < amount; j++) {
                char c = (char) (i + 97);
                ans.add(c+"");
            }
        }
        return ans;
    }

```
代码行数优化
```
    public static List<String> commonChars(String[] A) {
        List<String> ans = new ArrayList<>();
        int[] count = new int[26]; // 每个字符串中都重复的字符个数
        for (int i = 0; i < 26; i++) { // 初始化
            count[i] = 101;
        }
        for (int i = 0; i < A.length; i++) {
            int[] currCount = new int[26]; // 当前字符串中存在的字符个数
            for (int j = 0; j < A[i].length(); j++){
                currCount[A[i].charAt(j) - 97]++;
            }
            for (int j = 0; j < 26; j++) {
                if (currCount[j] < count[j]) count[j] = currCount[j];
            }
        }
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < count[i]; j++) {
                ans.add((char) (i + 97)+"");
            }
        }
        return ans;
    }
```
