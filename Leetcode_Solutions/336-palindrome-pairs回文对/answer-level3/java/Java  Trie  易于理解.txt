### 方法一：简单的暴力[超时]
#### 分析：
- 简单的暴力枚举出所有的字符串对，然后判断它们组成的字符串是否是回文对
- 时间复杂度为：$O(N*N*K)$  其中，$N$ 为` words`列表的长度，$K$为每个单词的平均长度
- 当数据量较大时，超时

#### 实现：
```java []
class Solution {
    public List<List<Integer>> palindromePairs(String[] words) {
        List<List<Integer>> ans = new ArrayList<>();
        int n = words.length;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (!check(words[i]+words[j])) continue;
                List<Integer> temp = new ArrayList<>();
                temp.add(i); temp.add(j);
                ans.add(temp);
            }
        }
        return ans;
    }
    private boolean check(String s) {
        int i = 0, j = s.length()-1;
        while (i < j) {
            if (s.charAt(i) != s.charAt(j)) return false;
            i++; j--;
        }
        return true;
    }
}
```
### 方法二：字典树（Trie树）[通过]
#### 分析：
- 根据回文字符串的性质，我们可以不用暴力枚举出所有字符串对
- 对于一个字符串对$(x, y)$, 若想要字符串$x+y$是一个回文字符串，则必须满足以下条件之一
- 1. 当$x.length() \geq y.length()$时, 字符串$x$的$y.length()$长度的前缀与$y$的**逆序**相等，且字符串$x$去除长度为$y.length()$的前缀后，余下的部分也是一个回文字符串。
- 2. 当$x.length() < y.length()$时,与情况一正相反。
- 
![1574085374927.jpg](https://pic.leetcode-cn.com/2a581d7ba88d8aa46c514b2d9911498a1ea9b821197767b5a345a35a6edb927c-1574085374927.jpg){:width=300}
- 对于字符串$x$时，我们依次遍历其每一个字母，假设当前遍历到的位置为$i$,若$[i,x.length()]$是一个回文对，且$[0,i]$的逆序存在于$word$列表中（设其下标为$y$），则$(x, y)$可以构成回文对，加入结果数组中。
- 当我们遍历完字符串$x$的每一个字符，我们还**需要考虑分析中第2种情况，即$x.length() < y.length()$**
- 为了加快查找速率，我们利用字典树辅助查找，其中重要的是字典树每一个`Node`里所保存的信息。
-   1.`List<Integer> words` 存储以当前节点为终止节点的所有单词（逆序之后的),来获取所有第1种情况下的匹配成功的字符串$y$
- 2.`List<Integer> suffixs` 保存所有到当前节点为止，其之后剩余字符可以构成回文对的单词。用来获取所有长度大于$x.length()$，且可以和其构成回文对的单词$y$（即针对第二种情况）。

#### 代码实现：
- 用每个单词的逆序构建字典树
- 在每个节点上维护以该节点为终止节点的单词
- 在若在该节点之和的部分能构成回文对，则加入suffixs列表中。
- 详情见注释
- 
```java []
class Solution {
    private Node root;
    public List<List<Integer>> palindromePairs(String[] words) {
        this.root = new Node();
        int n = words.length;
        // 字典树的插入，注意维护每个节点上的两个列表
        for (int i = 0; i < n; i++) {
            String rev = new StringBuilder(words[i]).reverse().toString();
            Node cur = root;
            if (isPalindrome(rev.substring(0))) cur.suffixs.add(i);
            for (int j = 0; j < rev.length(); j++) {
                char ch = rev.charAt(j);
                if (cur.children[ch-'a']==null) cur.children[ch-'a'] = new Node();
                cur = cur.children[ch-'a'];
                if (isPalindrome(rev.substring(j+1))) cur.suffixs.add(i);
            }
            cur.words.add(i);
        }
        // 用以存放答案的列表
        List<List<Integer>> ans = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            String word = words[i];
            Node cur = root;
            int j = 0;
            for ( ;j < word.length(); j++) {
                // 到j位置，后续字符串若是回文对，则在该节点位置上所有单词都可以与words[i]构成回文对
                // 因为我们插入的时候是用每个单词的逆序插入的:)
                if(isPalindrome(word.substring(j))) 
                    for (int k : cur.words) 
                        if (k != i) ans.add(Arrays.asList(i,k));
                
                char ch = word.charAt(j);
                if (cur.children[ch-'a'] == null) break;
                cur = cur.children[ch-'a'];

            }
            // words[i]遍历完了，现在找所有大于words[i]长度且符合要求的单词，suffixs列表就派上用场了:)
            if (j == word.length()) 
                for (int k : cur.suffixs) 
                    if (k != i) ans.add(Arrays.asList(i,k));
            
        }
        return ans;
        
    }
    //  判断一个字符串是否是回文字符串
    private boolean isPalindrome(String w) {
        int i = 0, j = w.length()-1;
        while (i < j) {
            if (w.charAt(i) != w.charAt(j)) return false;
            i++; j--;
        }
        return true;
    }
}
class Node {
    public Node[] children;
    public List<Integer> words;
    public List<Integer> suffixs;
    public Node() {
        this.children = new Node[26];
        this.words = new ArrayList<>();
        this.suffixs = new ArrayList<>();
    }
}
```

#### 复杂度分析

时间复杂度 ：$O(N*K^2)$ 其中$N$为列表长度，$K$为每个单词平均长度。