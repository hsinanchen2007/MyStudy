字符串s1（长度为k1），字符串s2（长度为k2）组合在一起判断是否是一个回文串有哪几种情况？
1. k1 = k2
2. k1 < k2
    s2剩下的部分必须要满足回文
3. k1 > k2
    s1剩下的部分必须要满足回文

![示例1.png](https://pic.leetcode-cn.com/ea61708d59de9063fab83a48663ea8706d173dc73e2fd61aae443c2f71cd4df3-%E7%A4%BA%E4%BE%8B1.png)

思考两个问题：

- 假设s1的首字符是a，怎么快速找到以a结尾的字符串？
    构建Trie，只不过要反着构建
- 第2，3种情况，如何快速的知道剩下的部分是否是回文？
    - 第2种情况，已知s1，查找s2，s1先遍历完，因此在遍历到s2的节点b时，为了能快速判断剩下的部分是回文，只要记录从该节点向后所有剩余能构成回文的字符串的下标即可。
    - 第3种情况，已知s1，查找s2，s2先遍历完，只需要判断s1剩下的部分是回文即可。

因此，需要构建的前缀树的结构如下：

```java
class TrieNode {
    public TrieNode[] children;
    public int index;  //题目要求返回下标，因为这里记录下标
    public List<Integer> suffixs;  //记录节点向后所有的剩余能构成回文的字符串下标
    
    public TrieNode(){
        this.children = new TrieNode[26];
        this.index = -1;
        this.suffixs = new ArrayList<>();
    }
}
```


一个简单示例：
- 构建图示

![示例2.png](https://pic.leetcode-cn.com/d7511df06e6f881f219b1d967f1f185a9e73320abe5fc7d28b3a100438e4af30-%E7%A4%BA%E4%BE%8B2.png)

- 查找图示（以字符串"a"为例）

![示例3.png](https://pic.leetcode-cn.com/c33cbfa6bebf3c7a115fe16c106666b24d8079fb3c1a2639cb7db2f79e1a4865-%E7%A4%BA%E4%BE%8B3.png)

完整代码如下：
- 构建
	- 字符串取反；
	- 遍历word，创建节点；
	- `word.substring(j+1)`为回文，则添加到该节点的suffixs列表中；这里要注意word本身为回文则添加到root节点的suffixs列表中；
- 查找
	- 遍历word；
	- 如果`word.substring(j)`为回文，则要看当前节点是否为一个单词，如果是，添加到结果中；（对应第三种情况，k1 > k2）
	- word遍历结束且有以word结尾的单词，则要看当前节点的suffixs列表；（对应第二种情况，k1 < k2）

```java
class Solution {
    private TrieNode root;
    public boolean isPalindrome(String s){
        int i=0, j=s.length()-1;
        while (i < j){
            if (s.charAt(i) != s.charAt(j)){
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
    public List<List<Integer>> palindromePairs(String[] words) {
        this.root = new TrieNode();
        int n = words.length;

        //build TrieNode Tree
        for (int i=0; i<n; i++){
            String word = new StringBuilder(words[i]).reverse().toString();
            TrieNode cur = root;

            if (isPalindrome(word.substring(0)))
                cur.suffixs.add(i);
            for (int j=0; j<word.length(); j++){
                int index = word.charAt(j) - 'a';
                if (cur.children[index] == null)
                    cur.children[index] = new TrieNode();
                cur = cur.children[index];
                if (isPalindrome(word.substring(j+1)))
                    cur.suffixs.add(i);
            }
            cur.index = i;
        }

        //search 
        List<List<Integer>> res = new ArrayList<>();
        for (int i=0; i<n; i++){
            String word = words[i];
            TrieNode cur = root;

            int j=0;
            for (; j<word.length(); j++){
                if (isPalindrome(word.substring(j)) && cur.index!=-1){
                    res.add(Arrays.asList(i, cur.index));
                }

                int index = word.charAt(j) - 'a';
                if (cur.children[index] == null)
                    break;
                cur = cur.children[index];
            }

            if (j == word.length()){
                for (int k : cur.suffixs){
                    if (k != i)
                        res.add(Arrays.asList(i, k));
                }
            }
        }

        return res;
    }
}

class TrieNode {
    public TrieNode[] children;
    public int index;
    public List<Integer> suffixs;
    
    public TrieNode(){
        this.children = new TrieNode[26];
        this.index = -1;
        this.suffixs = new ArrayList<>();
    }
}
```
时间复杂度：O(n×k×k)，因为k在一定范围内，所以这个问题优化为一个线性问题。

![时间复杂度.png](https://pic.leetcode-cn.com/6ba80c255d837f7a5f9c7f74afeb86a6b478bf6f31a148f1abf9a9304c4a3255-%E6%97%B6%E9%97%B4%E5%A4%8D%E6%9D%82%E5%BA%A6.png)

同步在我的博客：[leetcode No336. Palindrome Pairs](https://blog.csdn.net/u011391629/article/details/105327187)

同步在我的微信公众号《Coder101》，前缀树典型例题分析(一)
![QR_258.jpg](https://pic.leetcode-cn.com/86ab763fde4628cc67023f6779d01c9a11bc33694a38cfa6b5ea39592ffd87b0-QR_258.jpg)
