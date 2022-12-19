### 解题思路

##### 1. 题目概述：单词的压缩编码

##### 2. 思路：
   - 特征：对整个字符串数组排序,如果一个字符串是另一个字符串的后缀,就一定会排在另一个字符串的前面;
   - 方案：将字符串数组逆序然后排序,遍历每个字符串,只要前一个字符串不在当前字符串中,那么就累积上一个字符串的长度+1
   - 结果：累积的结果

##### 3. 知识点：排序

##### 4. 复杂度分析: 
   - 时间复杂度：O(nlogn)
   - 空间复杂度：O(n)


### 代码

```csharp []
public class Solution {
        public int MinimumLengthEncoding(string[] words)
        {
            var orderWords = words
                .Select(i => new string(i.Reverse().ToArray()))
                .OrderBy(i => i)
                .ToArray();

            var res = 0;
            for (var i = 1; i < words.Length; i++)
                if (orderWords[i].IndexOf(orderWords[i - 1]) == -1)
                    res += orderWords[i - 1].Length + 1;

            res += orderWords.Last().Length + 1;
            return res;
        }
}
```

### 解题思路

##### 1. 题目概述：单词的压缩编码

##### 2. 思路：
   - 特征：一个单词是另一个单词的后缀,才能压缩;
   - 方案：为每个单词,逆序构建 trie 树;dfs 树的每个叶子节点,每个叶子的深度之和即为解;
   - 结果：每个叶子的深度之和

##### 3. 知识点：trie 树

##### 4. 复杂度分析: 
   - 时间复杂度：O(sum(word.length))
   - 空间复杂度：O(26*sum(word.length))


### 代码

```csharp []
public class Solution {
        public int MinimumLengthEncoding1(string[] words)
        {
            var tri = new Trie();
            foreach (var wordItem in words)
                tri.AddStr(wordItem);

            m_res = 0;
            Dfs(tri.Root, 1);

            return m_res;
        }

        private int m_res;

        private void Dfs(TrieNode node, int curLength)
        {
            var nextNodes = Trie.GetNextNode(node);
            if (!nextNodes.Any())
            {
                m_res += curLength;
                return;
            }

            foreach (var nodeItem in nextNodes)
                Dfs(nodeItem, curLength + 1);
        }

        public class TrieNode
        {
            public TrieNode[] NextCharArray = new TrieNode[26];
        }

        public class Trie
        {
            public readonly TrieNode Root = new TrieNode();

            public void AddStr(string str)
            {
                var curNode = Root;
                for (var i = str.Length - 1; i >= 0; i--)
                {
                    if (curNode.NextCharArray[str[i] - 'a'] == null)
                        curNode.NextCharArray[str[i] - 'a'] = new TrieNode();

                    curNode = curNode.NextCharArray[str[i] - 'a'];
                }
            }

            public static List<TrieNode> GetNextNode(TrieNode curNode) => curNode.NextCharArray.Where(i => i != null).ToList();
        }
}
```