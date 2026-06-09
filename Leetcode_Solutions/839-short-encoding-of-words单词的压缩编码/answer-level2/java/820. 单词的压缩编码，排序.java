### 解题思路
按照字符串末尾排序

第一版代码卡着时间写了一个刚好通过的

### 代码1
```java
class Solution {
    public int minimumLengthEncoding(String[] words) {
        int minimumLengthEncoding = 0;
         Arrays.sort(words, new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                int i = o1.length() - 1, j = o2.length() - 1;
                while (i >= 0 && j >= 0) {
                    int c = Character.compare(o1.charAt(i--), o2.charAt(j--));
                    if (c != 0) return c;
                }
                return Integer.compare(o1.length(), o2.length());
            }
        });
        // System.out.println(Arrays.deepToString(words));
        for (int i = 0; i < words.length-1; ++i) {
            if (!words[i+1].endsWith(words[i])) {
                minimumLengthEncoding += words[i].length() + 1;
            }
        }
        minimumLengthEncoding += words[words.length-1].length() + 1;
        return minimumLengthEncoding;
    }
}
```

### 代码2
```java
class Solution {
    public int minimumLengthEncoding(String[] words) {
        int minimumLengthEncoding = 0;
         Arrays.sort(words, new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                if (o1.length() == o2.length()) {
                    return o1.charAt(o1.length() - 1) - o2.charAt(o2.length() - 1);
                }
                return o1.length() - o2.length();
            }
        });
        for (int i = 0; i < words.length; ++i) {
            minimumLengthEncoding += words[i].length() + 1;
            for (int j = i+1; j < words.length; ++j) {
                if (words[j].endsWith(words[i])) {
                    minimumLengthEncoding -= words[i].length() + 1;
                    break;
                }
            }
        }
        return minimumLengthEncoding;
    }
}
```