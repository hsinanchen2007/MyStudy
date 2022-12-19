### 解题思路
爆解：最笨的办法，逐一比较，哈哈哈，因为我比较蠢，时间复杂度很高。不知道为什么字典用不了

### 代码

```csharp
public class MagicDictionary {
    public string[] MagicDict; 
    /** Initialize your data structure here. */
    public MagicDictionary() {
        MagicDict = new string[0]; 
    }
    
    /** Build a dictionary through a list of words */
    public void BuildDict(string[] dict) {
        if(dict.Length == 0)return;
        MagicDict = dict;
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    public bool Search(string word) {
        if (MagicDict.Length == 0) return false;

        for (int i = 0; i < MagicDict.Length; i++)
        {
            if (MagicDict[i].Length == word.Length)
            {
                int count = 0;
                for (int j = 0; j < word.Length; j++)
                {
                    if (!string.Equals(MagicDict[i][j], word[j])) 
                    {
                        count++;
                    }
                    if (count > 1)
                    {
                        break;
                    }
                }
                if (count == 1)
                {
                    return true;
                }
            }
        }
        return false;
    }
}

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.BuildDict(dict);
 * bool param_2 = obj.Search(word);
 */
```