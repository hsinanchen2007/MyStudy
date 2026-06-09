```
/*
分析例子，总结规律：
1，str与pattern数量相同
2，拆解出一个str单词时，若该单词在str已经出现，则该单词对应的pattern字符必须是曾经对应的pattern字符
3，拆解出一个str单词时，若该单词在str未出现，则该单词对应的pattern字符必须未出现
很明显这是一种及其强烈的映射关系，本题我们考虑str----pattern的映射
算法思路：str=“dog cat cat *” pattern=“abb？”
1，设置单词str到pattern'的哈希映射，使用数组used[128]记录pattern字符是否使用
2，遍历str，按照空格拆分单词，同时对应移动pattern的指针，判断
    如果该单词从未出现在哈希表：
        如果pattern的used使用了，false
        否则当前单词与pattern作映射，并且used标记
    否则
        如果当前哈希表单词映射不是指向pattern字符，false
3，str pattern数量不匹配 false
总体说：就是同时遍历两个集合，未出现作映射，都出现过作判断，全部遍历后看数量。
*/
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        std::map<std::string, char> word_map;//单词到pattern的映射
        char used[128] = {0};//pattern已经使用的记录
        std::string word;//临时保存拆分出来的单词
        int pos = 0;//用于指向pattern的下标
        str.push_back(' ');//用来处理最后一个字符，遇到''，说明word保存好了
        for(int i = 0; i < str.length(); i++){
            if(str[i] == ' '){//遇到了空格，说明word已经保存好了
                if(pos == pattern.length()){//现在已经拆分出一个word，但是无pattern
                    return false;
                }
                if(word_map.find(word) == word_map.end()){//find找到了end，说明word未在map里面
                    if(used[pattern[pos]]){
                        return false;//如果对应pattern被使用过，返回错
                    }
                    word_map[word] = pattern[pos];//map插入
                    used[pattern[pos]] = 1;
                }
                else{//word在map里面
                    if(word_map[word] != pattern[pos]){
                        return false;//如果之前记录的映射与现在扫描的pattern不一致，返回false
                    }
                }
                word = "";//完成了一个单词的插入和查询，清空word用于下次扫描单词存储
                pos++;   
            }
            else{
                word += str[i];
            }
        }
       if(pos != pattern.length()){//pattern多一个
           return false;
       } 
       return true;
    }
};
```