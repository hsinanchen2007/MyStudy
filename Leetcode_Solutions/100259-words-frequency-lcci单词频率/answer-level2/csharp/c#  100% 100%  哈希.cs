
应该是最简单的一道题了~
可以关注c# 刷题：https://blog.csdn.net/us2019/article/details/104867660
```
public class WordsFrequency {
        Dictionary<string, int> dic = new Dictionary<string, int>();

    public WordsFrequency(string[] book) {
for (int i = 0; i < book.Length; i++)
            {
                if (dic.ContainsKey(book[i]))
                {
                    dic[book[i]]++;
                }
                else
                {
                    dic[book[i]] = 1;
                }
            }
    }
    
    public int Get(string word) {
 if (dic.ContainsKey(word))
            {
                return dic[word];
            }
            return 0;
    }
}

 
```
