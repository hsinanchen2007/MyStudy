#解题思路#
用了一个无序哈希表反复统计所给的字母表中字母的数量，然后遍历每一个单词，对哈希表中的出现的字母数量做减法。（然后看到官方解答，emmm发现自己有点憨憨）不过还是很高兴自己能写出来的，毕竟是我第二次用哈希表。后面继续加油！！！

具体代码如下：

#代码#
```
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) 
    {
        unordered_map<char, int> word_count; //定义一个无序哈希表
        string str;
        int size = words.size();
        
        if(size == 0)
            return 0;
        for(int i = 0; i < size; i++)
        {
            string word = words[i];
            int word_size = word.size();
            for(char ch:chars) //反复统计给的字母表的字母个数
            {
                ++word_count[ch];
            }
            int j; 
            for(j = 0; j < word_size; j++) //将出现的字母数量做减法
            {                 
                auto ans = word_count.find(word[j]);
                if(ans == word_count.end()) //字母表没有这个字母
                    break;
                else 
                {
                    if(ans->second == 0) //字母表中的这个字母被用完
                        break;
                    else
                        ans->second--;
                }
            }
            if(j == word_size) //说明字母表中的字母可以拼写这个单词，中间没有（break）跳出循环
                str += word;
            word_count.clear(); //清空哈希表，为下一次统计做准备
        }
        return str.size();
    }
};
```
