### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public int MinimumLengthEncoding(string[] words) {


          
            HashSet<string> set = new HashSet<string>(words);
            for (int i = 0; i < words.Length; i++)
            {
                for (int j = 1; j < words[i].Length; j++)
                {
                    if (set.Contains(words[i].Substring(j)))
                    {
                        set.Remove(words[i].Substring(j));
                    }
                }
            }
            int res = 0;
            foreach (string item in set)
            {
                res += item.Length + 1;
            }
            return res;
    }
}
```

学到的字典树

### 代码

```csharp
public class Solution {
      private class LetterTree
        {
            public LetterTree[] letters;
        }
    public int MinimumLengthEncoding(string[] words) {

          int min = 0;
            LetterTree root = new LetterTree();             //根节点
            root.letters = new LetterTree[26];              
            foreach (string word in words)
            {
                LetterTree current= root;
                for (int i=word.Length-1;i>=0;i--)
                {
                    int index = word[i] - 'a';
                    if (current.letters != null)
                    {           // 如果当前位置不是最末的节点
                        if (current.letters[index] != null)
                        {   //有重复路径
                            current = current.letters[index];
                        }
                        else
                        {  //没有重复路径 出现分叉
                            min += word.Length - i + 1;   // min要加上 该单词从第i个字母开始到结束的字母个数 再加上1（#）
                            current.letters[index] = new LetterTree();
                            current = current.letters[index];
                        }
                    }
                    else
                    {   //是最末节点 出现延长
                        min++;                    
                        current.letters = new LetterTree[26];
                        current.letters[index] = new LetterTree();
                        current = current.letters[index];
                    }
                }
            }
            return min;
    }
}
```