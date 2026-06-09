 ### 1. 直接暴力解法
暴力的时间并不理想，1000ms竟然也过了。但这个做法对解题很关键，有必要先弄明白，后面可以进一步优化到20ms。（如果已经知道暴力做法只想了解字典树可以直接跳到2.2优化二解法）

这里采用*动态规划*，创建一个数组`dp[]`用来记录结果。句子从前往后看，其中`dp[0]=0`表示句子是空字符串时没有未识别的字符，`dp[i]`表示句子前i个字符中最少的未识别字符数。
然后来找状态转移方程。对于前i个字符，即句子字符串的[0,i)，它可能是由最前面的[0,j)子字符串加上一个字典匹配的单词得到，也就是dp[i]=dp[j], j<i；也可能没找到字典中的单词，可以用它前i-1个字符的结果加上一个没有匹配到的第i个字符，即dp[i]=dp[i-1]+1。要注意的是，即使前面存在匹配的单词，也不能保证哪一种剩下的字符最少，所以每轮都要比较一次最小值。
代码看着更直观：

```
class Solution {
    public int respace(String[] dictionary, String sentence) {
        Set<String> dic = new HashSet<>();
        for(String str: dictionary) dic.add(str);

        int n = sentence.length();
        //dp[i]表示sentence前i个字符所得结果
        int[] dp = new int[n+1];
        for(int i=1; i<=n; i++){
            dp[i] = dp[i-1]+1;  //先假设当前字符作为单词不在字典中
            for(int j=0; j<i; j++){
                if(dic.contains(sentence.substring(j,i))){
                    dp[i] = Math.min(dp[i], dp[j]);
                }
            }
        }
        return dp[n];
    }
}
```

### 2.1 优化一：基于上面思路的优化
上述代码套了两层循环，缺点就是对于每一个`i`，它前面的子字符串都被找了个遍，这其中包括一些根本不可能在字典中出现的单词。需要找一个方法提前结束。
一种方法是记录字典中每个单词最后一个字符，如果想匹配的字符串的最后一个字母都不在字典里，就没必要再看这个字符串了；此外，即使字符串最后一个字母在词典里，也不用挨个去找`[j,i)`子字符串是否匹配，即不需要让`j`从`0`到`i`遍历一遍，只要看对应长度的子串在不在词典里即可。
```
class Solution {
    public int respace(String[] dictionary, String sentence){
        Set<String> dic = new HashSet<>();
        // <最后一个字符，这样的单词长度有哪些>
        Map<Character, Set<Integer>> map = new HashMap<>();
        for(String str: dictionary){
            dic.add(str);
            int len = str.length();
            char c = str.charAt(len-1);
            Set<Integer> set = map.getOrDefault(c, new HashSet<>());
            set.add(len);
            map.put(c, set);
        }
        
        int n = sentence.length();
        int[] dp = new int[n+1];
        for(int i=1; i<=n; i++){
            dp[i] = dp[i-1]+1;
            char c = sentence.charAt(i-1);
            if(map.containsKey(c)){
                Set<Integer> lens = map.get(c);
                // for(int l: lens){
                //     if(i>=l && dic.contains(sentence.substring(i-l,i))){
                //         dp[i] = Math.min(dp[i], dp[i-l]);
                //     }
                // }
                //使用迭代器比直接foreach要快些
                Iterator<Integer> it = lens.iterator();
                while(it.hasNext()){
                    int l = it.next();
                    if(i>=l && dic.contains(sentence.substring(i-l,i))){
                        dp[i] = Math.min(dp[i], dp[i-l]);
                    }
                }
            }
        }
        return dp[n];
    }
}
```

这种解法可能比较奇特。但是从运行结果来看，40ms已经有了很大进步，还是可以接受。

### 2.2 优化二：使用字典树
这里重点讲述[Trie字典树](https://blog.csdn.net/johnny901114/article/details/80711441)的解法。首先看一个字典树的例子：
![Trie1.png](https://pic.leetcode-cn.com/78dd794c445cfdf7a66dd7f604eb8111c5f3b484a558817cb34d185638a08713-Trie1.png)

该树包含的单词集合为{“at”, “bee”, “ben”, “bt”, “q”}。每一个节点保存一个字符，因为题目说只包含小写字母，所以一个节点最多可以有26个子节点。每次查找单词都从空白的根节点开始，比如查找单词"cat"，第一个字符'c'就不存在，直接返回false；查找单词"bee"，根节点下有b，b的子节点有e，下面还有e所以查到了。**但是如果查找单词"be"**,同样的方法'b'和'e'都存在，但是字典里没有"be"这个单词，所以在树里还需要一个boolean变量表示当前节点是不是一个单词的结尾，如图绿色表示。如果往字典中插入一个"be"单词，此时b节点下的e节点也应该标绿，此时再查找"be"，在e节点发现它是个单词，所以返回true.

使用字典树可利用字符串的公共前缀来减少查询时间，最大限度地减少无谓的字符串比较。程序执行用时20ms.
```
class Solution {
    /** 自定义一个TrieNode类型。
    * 这里不用建一个变量来存当前节点表示的字符，
    * 因为只要该节点不为null，就说明存在这个字符
    */
    class TrieNode{
        TrieNode[] childs;
        boolean isWord;
        public TrieNode(){
            childs = new TrieNode[26];
            isWord = false;
        }
    }
    TrieNode root;  //空白的根节点，设为全局变量更醒目
    public int respace(String[] dictionary, String sentence){
        root = new TrieNode();
        makeTrie(dictionary);   //创建字典树
        int n = sentence.length();
        int[] dp = new int[n+1];
        //这里从sentence最后一个字符开始
        for(int i=n-1; i>=0; i--){
            dp[i] = n-i;    //初始默认后面全不匹配
            TrieNode node = root;
            for(int j=i; j<n; j++){
                int c = sentence.charAt(j)-'a';               
                if(node.childs[c] == null){
                    //例如"abcde",i=1,j=2 可找出长度关系
                    dp[i] = Math.min(dp[i], j-i+1+dp[j+1]);
                    break;
                }
                if(node.childs[c].isWord){
                    dp[i] = Math.min(dp[i], dp[j+1]);
                } else{
                    dp[i] = Math.min(dp[i], j-i+1+dp[j+1]);
                }
                node = node.childs[c];
            }
        }
        return dp[0];
    }

    public void makeTrie(String[] dictionary){
        for(String str: dictionary){
            TrieNode node = root;
            for(int k=0; k<str.length(); k++){
                int i = str.charAt(k)-'a';
                if(node.childs[i] == null){
                    node.childs[i] = new TrieNode();
                }
                node = node.childs[i];
            }
            node.isWord = true; //单词的结尾
        }
    }
}
```


