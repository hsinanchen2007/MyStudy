看了一些大神的有点不明白，转不过弯，自己整理了一下思路，看对不对，有没有改进的，欢迎指证优化！谢谢！

1。定义一个pattern 和word映射的 MAP  
2。单词分割到列表，在边分割的时候，就遍历处理逻辑了
3.从前往后，分割遍历单词，在map中查找，以pattern[index] (index 与单词同步往后) 为主键的 word是否存在
4。如果存在，判断一下是否在同一位置，方法  map[pattern[i]] == word
5.如果不存在，还需要判断有没有其他pattern 与此单词有匹配过了，如果有返回false;  （判断方法：遍历map，看是否有值为word的项。）
6。没有其他pattern匹配，加入一组匹配到 map

7。分割完单词，看单词与pattern是否同时走完，是的话则返回true，否则返回false;


class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char,string> patWordMap;
        int index = 0;
        string word;
        istringstream  wordlist(str);

        while (wordlist>>word)
        {
            if(patWordMap.find(pattern[index]) != patWordMap.end())//已经加入到一组匹配，看是不是在同一位置
            {
                if(patWordMap[pattern[index]] != word)
                {
                    return false;
                }
            }
            else //不包含的时候，看是不有其他pattern对应
            {
                for(auto iter = patWordMap.begin();iter!=patWordMap.end();iter++)
                {
                    if(iter->second == word)
                    return false;
                }
                patWordMap[pattern[index]] = word;//加入map
            }
            index++;
        }
        if(index == pattern.size())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
