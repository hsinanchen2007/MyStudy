**拥有详细解题思路的题解才是好题解**
# 解题思路：
    1、通过循环将words利用Array.Reverse()倒序
    2、将倒序后的char[]类型转换成字符串并赋值给words
    3、利用Array.Sort()对进行了倒序操作的字符串数组排序
    4、通过循环和IndexOf判断后一个单词是否包含前一个单词
    5、如果不包含即值为-1，res加上前一个单词的长度并加上#的1
    6、最后把最后一个单词的长度也加起来
# 实现代码：
```
public class Solution {
    public int MinimumLengthEncoding(string[] words) {
        for(int i = 0; i < words.Length; i++){
            var word = words[i].ToCharArray();
            Array.Reverse(word);
            words[i] = new string(word);
        }
        Array.Sort(words);
        int res = 0;
        for(int i = 1; i < words.Length; i++){
            if (words[i].IndexOf(words[i - 1]) == -1)
                res += words[i - 1].Length + 1;
        }
        res += words.Last().Length + 1;
        return res;
    }
}
```
