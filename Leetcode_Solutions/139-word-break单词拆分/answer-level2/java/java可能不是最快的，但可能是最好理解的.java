```
public boolean wordBreak(String s, List<String> wordDict) {
        int[] h = new int[s.length() + 1];
        Set<String> set = new HashSet<>(wordDict);//集合存储成set更快
        for (int i = 1; i < h.length; i++) {
            for (int j = 0; j < i; j++) {
                String s1 = s.substring(j, i);//每次都把已经拼成的字符切开
                if (set.contains(s1)) {//切开的后半段在字典中
                    if (h[j] + s1.length() == i) {//如果前半段能组成的长度加上后半段的长度等于当前长度
                        h[i] = i;//说明当前可以组成这么长的字符串
                        break;//只要能组成了，后面不用算了
                    }
                }
            }
        }
        return h[h.length - 1] == h.length - 1;//看最后能组成的长度是否等于单词s（由于保存的都是下标，所以减1）
    }
```
