### 解题思路
dfs
1.用一个二维数组(connects)保存单词的关系
2.用一个数组(passFlags)保存走过的点，这样可避免dfs超时

### 代码

```csharp
public class Solution {
    public IList<string> FindLadders(string beginWord, string endWord, IList<string> wordList) {
        List<string> newWordList = new List<string>(wordList);

        int endIndex = -1;
        for(int i = 0; i < newWordList.Count; i++)
        {
            if(newWordList[i] == endWord)
            {
                endIndex = i;
                break;
            }
        }

        if(endIndex < 0)
        {
            return new List<string>();
        }

        if(beginWord == endWord)
        {
            return new List<string>(){endWord};
        }

        int startIndex = -1;
        for(int i = 0; i < newWordList.Count; i++)
        {
            if(newWordList[i] == beginWord)
            {
                startIndex = i;
                break;
            }
        }

        if(startIndex < 0)
        {
            startIndex = newWordList.Count;
            newWordList.Add(beginWord);
        }

        bool[][] connects = new bool[newWordList.Count][];
        for(int i = 0; i < connects.Length; i++)
        {
            connects[i] = new bool[connects.Length];
        }

        for(int i = 0; i < newWordList.Count; i++)
        {
            string word = newWordList[i];
            for(int j = i + 1; j < newWordList.Count; j++)
            {
                string word2 = newWordList[j];

                if(word.Length == word2.Length)
                {
                    int c = 0;
                    for(int k = 0; k < word2.Length; k++)
                    {
                        if(word[k] != word2[k])
                        {
                            c++;
                            if(c >= 2)
                            {
                                break;
                            }
                        }
                    }

                    if(c <= 1)
                    {
                        connects[i][j] = true;
                        connects[j][i] = true;
                    }
                }
            }
        }

        
        
        bool[] passFlag = new bool[newWordList.Count];
        List<int> indices = new List<int>();
        Search(connects, startIndex, endIndex, passFlag, indices);
        List<string> names = new List<string>();
        for(int i = 0; i < indices.Count; i++)
        {
            names.Add(newWordList[indices[i]]);
        }
        return names;
    }

    bool Search(bool[][] connects, int startIndex, int endIndex, bool[] passFlag, List<int> indices)
    {
        indices.Add(startIndex);

        if(startIndex == endIndex)
        {
            return true;
        }
        
        passFlag[startIndex] = true;
        for(int i = 0; i < connects.Length; i++)
        {
            if(connects[startIndex][i] && !passFlag[i])
            {
                if(Search(connects, i, endIndex, passFlag, indices))
                {
                    return true;
                }
            }
        }

        //这行一定要注释，避免查过的单词反复查，否则会走时
        // passFlag[startIndex] = false;
        indices.RemoveAt(indices.Count - 1);
        return false;
    }
}
```