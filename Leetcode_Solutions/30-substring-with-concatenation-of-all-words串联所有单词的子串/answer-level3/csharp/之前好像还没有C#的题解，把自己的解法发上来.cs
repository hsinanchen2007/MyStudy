```
public class Solution {
    //暴力法，s中查找所有可能子串，返回结果
    //相比暴力法，怎么尽量过滤非法的值？
    //一次遍历中，生成一个列表[符合某word的子串起始下标]；然后遍历该列表
    public IList<int> FindSubstring(string s, string[] words) {
        IList<int> result = new List<int>();
            int count = words.Length;
            if (count == 0)
            {
                return result;
            }
            int length = words[0].Length;
            if (length == 0)
            {
                return result;
            }
            //生成Dic<word, 重复次数>
            Dictionary<string, int> wordDic = new Dictionary<string, int>();
            for (int i = 0; i < words.Length; i++)
            {
                string word = words[i];
                if (!wordDic.ContainsKey(word))
                {
                    wordDic.Add(word, 0);
                }
                wordDic[word]++;
            }
            //处理只有一个word时的情况
            if (wordDic.Count == 1)
            {
                var str = string.Join("", words.ToList());
                wordDic.Clear();
                wordDic.Add(str, 1);
                length = str.Length;
                count = 1;
            }
            //生成Dic<s中的下标，下标对应的word>
            List<int> indexList = new List<int>();
            for (int i = 0; i < s.Length - length + 1; i++)
            {
                string str = s.Substring(i, length);
                if (wordDic.ContainsKey(str))
                {
                    indexList.Add(i);
                }
            }
            //遍历所有匹配子串
            for (int i = 0; i < indexList.Count - count + 1; i++)
            {
                int start = indexList[i];
                if (start + length * count > s.Length) break;
                Dictionary<string, int> tmpCheck = new Dictionary<string, int>(wordDic);
                bool success = true;
                for (int j = 0; j < count; j++)
                {
                    int sIndex = start + j * length;
                    string str = s.Substring(sIndex, length);
                    if (!tmpCheck.ContainsKey(str) || tmpCheck[str] <= 0)
                    {
                        success = false;
                        break;
                    }
                    tmpCheck[str]--;
                }
                if (success) result.Add(start);
            }
            return result.ToList();
    }
}
```
