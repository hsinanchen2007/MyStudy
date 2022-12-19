### 解题思路
c#递归

### 代码

```csharp
public class Solution {
    int[][] minCountBackup;
    public int MinDistance(string word1, string word2) {
        minCountBackup = new int[word1.Length][];
        for(int i = 0; i < word1.Length; i++)
        {
            minCountBackup[i] = new int[word2.Length];   
        }

        for(int i = 0; i < minCountBackup.Length; i++)
        {
            for(int j = 0; j < minCountBackup[i].Length; j++)
            {
                minCountBackup[i][j] = -1;
            }
        }

        return Search(word1, word2, 0, 0);
    }

    int Search(string word1, string word2, int startIndex1, int startIndex2)
    {
        if(startIndex1 >= word1.Length)
        {
            return word2.Length - startIndex2;
        }

        if(startIndex2 >= word2.Length)
        {
            return word1.Length - startIndex1;
        }

        if(minCountBackup[startIndex1][startIndex2] >= 0)
        {
            return minCountBackup[startIndex1][startIndex2];
        }

        if(word1[startIndex1] == word2[startIndex2])
        {
            minCountBackup[startIndex1][startIndex2] = Search(word1, word2, startIndex1 + 1, startIndex2 + 1);
        }
        else
        {
            int replaceOpCount = 1;
            replaceOpCount += Search(word1, word2, startIndex1 + 1, startIndex2 + 1);

            int deleteOpCount = 1;
            deleteOpCount += Search(word1, word2, startIndex1 + 1, startIndex2);

            int insertOpCount = 1;
            insertOpCount += Search(word1, word2, startIndex1, startIndex2 + 1);

            int minCount = replaceOpCount;
            minCount = Math.Min(minCount, deleteOpCount);
            minCount = Math.Min(minCount, insertOpCount);

            minCountBackup[startIndex1][startIndex2] = minCount;
        }

        return minCountBackup[startIndex1][startIndex2];
    }
}
```