

```csharp
    public class MapSum
    {
        // 前缀树节点定义
        public class TrieNode
        {
            public Dictionary<char, TrieNode> dic = new Dictionary<char, TrieNode>();

            public bool isEnd;

            public int val;

            public TrieNode()
            {
            }

            public bool ContainsKey(char ch)
            {
                return dic.ContainsKey(ch);
            }

            public TrieNode Get(char ch)
            {
                return dic[ch];
            }

            public void Put(char ch, TrieNode node)
            {
                dic[ch] = node;
            }

            public void SetEnd()
            {
                isEnd = true;
            }

            public bool IsEnd()
            {
                return isEnd;
            }
        }

        private TrieNode root;

        /** Initialize your data structure here. */
        public MapSum()
        {
            root = new TrieNode();
        }

        public void Insert(string key, int val)
        {
            TrieNode node = root;
            for (int i = 0; i < key.Length; i++)
            {
                char currentChar = key[i];
                // 判断节点维护的字典是否存在对应的字符映射
                // 不存在就创建一个节点, 做好映射关系
                if (!node.ContainsKey(currentChar))
                {
                    node.Put(currentChar, new TrieNode());
                }

                // 获取子节点
                node = node.Get(currentChar);
            }

            node.val = val;
            // 遍历完此单词设置标志位flag
            node.SetEnd();
        }
        
        public int Sum(string prefix)
        {
            var node = SearchPrefix(prefix);

            return Dfs(node);
        }

        public int Dfs(TrieNode node)
        {
            int sum = 0;
            if (node == null)
            {
                return 0;
            }

            // 递归遍历N叉树, 直到遍历到叶子节点
            foreach (var temp in node.dic)
            {
                sum += Dfs(temp.Value);
            }
            
            // 叶子节点的dic为空, val是对应字符串的值
            return sum + node.val;
        }

        // 搜索前缀或整个键在树中, 并且返回在哪结束的节点
        private TrieNode SearchPrefix(String word)
        {
            TrieNode node = root;
            for (int i = 0; i < word.Length; i++)
            {
                char currentChar = word[i];
                if (node.ContainsKey(currentChar))
                {
                    node = node.Get(currentChar);
                }
                else
                {
                    return null;
                }
            }

            return node;
        }

        /** Returns if the word is in the trie. */
        public bool Search(string word)
        {
            var node = SearchPrefix(word);
            // 需要判断是否设置了单词结束的标志位
            return node != null && node.IsEnd();
        }
    }
```
