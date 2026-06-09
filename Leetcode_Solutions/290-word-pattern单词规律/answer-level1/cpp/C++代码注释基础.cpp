萌新弱鸡，这道题卡了很久，做个易懂的注释提醒自己一下。

```
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> word;
        int j = 0;
        unordered_map<string,char> hash;//建立从word到pattern的映射
        str.push_back(' ');//之前的词都以空格结尾，就最后一个词没有，所以这个绝对不能少
        int used[128] = {0};//建立从pattern到used的映射，这样映射就封闭了
        for(int i=0;i<str.size();i++){//一步步地从str中把word提取出来
            int count = 0;//当前词的长度，每找到一个词就需要清零
            while(str[i]!=' '){//只要发现了空格，就分割出来一个单词，实际上加上for也仍然是是单层循环
                count++;//当前词的长度加1
                i++;//str的指针向后移动
            }//循环跳出来后，说明找到一个单词了
            word.push_back("");//vector需要push一个位置
            word[j] = str.substr(i-count,count);//当前word的长度为count，首字母在str的位置是i-count
            j++;//vector的序号加1
        } 
        if(pattern.size()!=word.size()){//如果pattern的长度和vector不一样，肯定是错的
            return false;
        }
        for(int i=0;i<pattern.size();i++){//依次遍历pattern
            if(used[pattern[i]]==1 && hash[word[i]]!=pattern[i]){//如果pattern的字母用过了，但是新来的word和他对应的词不一样，是错的
                return false;
            }
            if(used[pattern[i]]==0 && hash.find(word[i])!=hash.end()){//如果pattern的字母没用过，但是本应该和他对应的单词却已经出现过了，是错的
                return false;
            }
            if(used[pattern[i]]==0 && hash.find(word[i])==hash.end()){//如果pattern和word都没出现过，则建立他们的关系。
                hash[word[i]] = pattern[i];
                used[pattern[i]] = 1;
            }
        }
        return true;
    }
};
```
