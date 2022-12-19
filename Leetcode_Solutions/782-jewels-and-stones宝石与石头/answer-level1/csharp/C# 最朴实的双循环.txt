最简单的思路，遍历石头，检查石头是不是宝石。
宝石存成char[]，石头存成List<char>，以便把已经判断为宝石的石头从石头中拿出，减少循环比较的次数。
同时别忘了在拿出宝石的同时下标前移一位。
```
    public int NumJewelsInStones(string J, string S) {
        char[] charJ = J.ToCharArray();
        List<char> charS = S.ToList<char>();
        int result = 0;
        for (int i = 0; i < charJ.Count(); i++)
        {
            for (int j = 0; j < charS.Count(); j++)
            {
                if (charJ[i] == charS[j])
                {
                    result++;
                    charS.Remove(charS[j]);
                    j--;
                }
            }
        }
        return result;
    }
```
