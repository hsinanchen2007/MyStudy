字典树，后缀存储：
```
  int ans = 0;
    public int minimumLengthEncoding(String[] words) {
        for (String w : words) {
            put(w);
        }
        return ans;
    }


    TrieNode root = new TrieNode();
    class TrieNode{
        int count;
        TrieNode[] children;
        TrieNode() {
            this.count = 0;
            children = new TrieNode[26];
        }
    }

    private void put(String word) {
        TrieNode cur = root;
        // 倒序插入
        for (int i = word.length() - 1; i >= 0; i--) {
            int index = word.charAt(i) - 'a';
            if (cur.children[index] != null) {
                if (i == 0) {
                    // 说明单词已经存在，比如原来有time，现在有me，me不用再统计
                    return;
                } else {
                    if (cur.children[index].count > 0) {
                        // 比如已有me 再添加time，要减去me的次数
                        ans -= cur.children[index].count;
                        cur.children[index].count = 0;
                    }
                }
            } else {
                cur.children[index] = new TrieNode();
            }
            cur = cur.children[index];
        }
        ans += word.length() + 1;
        cur.count = word.length() + 1;
    }

```

