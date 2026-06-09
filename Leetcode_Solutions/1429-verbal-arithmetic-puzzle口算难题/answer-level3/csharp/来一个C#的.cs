这个题基本上是一个回溯解法
基本思路：统计所有出现的char，每个char尝试0-9依次赋值，并且每个数字只能用一次，其中首字母不能为0。
当所有char都赋值之后，对每个单词转成int然后判断left==right。如果相等，后面的回溯可以不用做了。如果不想当就回溯，直到遍历所有可能性。

第一遍做的时候没有考虑太多。只求写一个回溯算法暴力破解。但是这种暴力破解，首先取char的时候是每个单词从左往右遍历的，所以在赋值回溯的时候也是每个单词从左往右尝试。但是这样的缺点是没有办法优化，因为当一个单词只有前一半的字母赋值的时候没法计算结果。只能在所有单词都赋值之后才能比较一次，看是否pass。因为这种真的是暴力破解，所有的分支都会走到。

后来冷静下来思考了一遍，发现其实从后往前回溯就会可以提前把最后一位相加，最后两位相加....直到所有位数相加。这样可以对tail逐级比较，只要一次不能pass，当前的赋值就可以return。这样绝大部分的分支都可以提前结束。
当然这样子的方案代码写起来略有点难度。
![微信截图_20191230151550.png](https://pic.leetcode-cn.com/197d4f8ebab1f03819ef48fed37da0d68c7fa3bcca85f3ff7581f33c27d6705a-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20191230151550.png)

先声明一下成员变量，免得在函数中传参数
```
    Dictionary<char, int> map = new Dictionary<char, int>();
    HashSet<int> useNums = new HashSet<int>();
    HashSet<char> initials = new HashSet<char>();
    string[] words;
    string result;
    string[] allWords;
    int maxChars = 0;
    bool solved = false;
```

一开始统计首字母，同时计算maxChars
```
    void AddInitialLetter(string s)
    {
        maxChars = Math.Max(s.Length, maxChars);
        if (!initials.Contains(s[0]))
            initials.Add(s[0]);
    }
```
```
    foreach (var w in words) AddInitialLetter(w);
    AddInitialLetter(result);
```

charIndex = [0, maxChars]，表示倒数第几位字符。从0开始。
wordIndex用来遍历所有单词。因为要words+result所有单词的倒数charIndex位都完成赋值再CheckSumOk才有意义吧。因为把words+result放到一个新数组allWords中方便遍历。当wordIndex == allWords.Length时，表示所有单词的这一位都赋值完成。
```
this.allWords = new string[words.Length + 1];
Array.Copy(words, allWords, words.Length);
allWords[allWords.Length - 1] = result;
```
接着开始回溯
注意在哪里wordIndex++，在哪里charIndex++就行
附上完整代码
```
public class Solution
{
    Dictionary<char, int> map = new Dictionary<char, int>();
    HashSet<int> useNums = new HashSet<int>();
    HashSet<char> initials = new HashSet<char>();
    string[] words;
    string result;
    string[] allWords;
    int maxChars = 0;
    bool solved = false;

    int CalcInt(string s, int start)
    {
        var ret = 0;
        for (int i = s.Length - 1; i >= Math.Max(0, start); i--)
            ret += (int)Math.Pow(10, s.Length - 1 - i) * map[s[i]];
        return ret;
    }

    void AddInitialLetter(string s)
    {
        maxChars = Math.Max(s.Length, maxChars);
        if (!initials.Contains(s[0]))
            initials.Add(s[0]);
    }

    bool CheckSumOk(int charIndex)
    {
        var left = 0;
        foreach (var w in words)
            left += CalcInt(w, w.Length - 1 - charIndex);
        var right = CalcInt(result, result.Length - 1 - charIndex);
        var modBase = (int)Math.Pow(10, charIndex + 1);
        left = left % modBase;
        right = right % modBase;
        return left == right;
    }

    void Backtrace(int wordIndex, int charIndex)
    {
        if (solved) return;
        if (wordIndex == allWords.Length)
        {
            if (CheckSumOk(charIndex))
            {
                if (charIndex == maxChars - 1)
                    solved = true;
                else
                    Backtrace(0, charIndex + 1);
            }
        }
        else
        {
            var w = allWords[wordIndex];
            if (w.Length - 1 - charIndex < 0)
                Backtrace(wordIndex + 1, charIndex);
            else
            {
                var c = w[w.Length - 1 - charIndex];
                if (map.ContainsKey(c))
                    Backtrace(wordIndex + 1, charIndex);
                else
                {
                    var start = 0;
                    var end = 9;
                    if (initials.Contains(c))
                        start = 1;
                    for (int i = start; i <= end; i++)
                    {
                        if (!useNums.Contains(i))
                        {
                            useNums.Add(i);
                            map.Add(c, i);
                            Backtrace(wordIndex + 1, charIndex);
                            useNums.Remove(i);
                            map.Remove(c);
                        }
                    }
                }
            }
        }
    }

    public bool IsSolvable(string[] words, string result)
    {
        foreach (var w in words) AddInitialLetter(w);
        AddInitialLetter(result);
        this.words = words;
        this.result = result;
        this.allWords = new string[words.Length + 1];
        Array.Copy(words, allWords, words.Length);
        allWords[allWords.Length - 1] = result;
        Backtrace(0, 0);
        return solved;
    }
}
```
