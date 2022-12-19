```
class Solution {
public:
    //将string字符串所有大写字母转换为小写
    void strlwr(string &s){
        for(int i = 0;i != s.size();i++){
            s[i] = tolower(s[i]);
        }
    }
    //判断字符是否是字母
    bool isLetter(char &c)
    {
        return isupper(c) || islower(c);
    }
    string mostCommonWord(string paragraph, vector<string>& banned) {
        map<string,int> bannerMap;//将禁用列表转换为字典形式，牺牲空间以达到快速查找的目的。
        for(string s : banned){
            bannerMap[s] = 1;
        }

        bool isWord = false;//标记区间是否包含字母
        int startIndex = 0;//记录单词开始的索引值
        map<string,int> wordRecord;//记录非禁用单词出现次数。
        for(int i = 0;i != paragraph.size();i++)
        {
            if(!isLetter(paragraph[i])){
                //每当访问到不是字母的字符时，截取目标区间，并进行统计。
                if(isWord){
                    string word = paragraph.substr(startIndex,i - startIndex);
                    strlwr(word);
                    if(bannerMap[word] != 1)
                        wordRecord[word]++;
                }
                startIndex = i + 1;//startIndex应标记为单词开始字母的下标，所以需要在非字母下标的基础上+1;
                isWord = false;
            }else{
                //可能存在结尾也是字母的的情况，例如"Bob"
                if(i == paragraph.size()-1){
                    string word = paragraph.substr(startIndex,i - startIndex + 1);
                    strlwr(word);
                    if(bannerMap[word] != 1)
                        wordRecord[word]++;
                    break;
                }

                isWord = true;
            }
        }

        //遍历wordRecord得到出现次数最多的单词
        int recordNumber = 0;
        string result;
        for(auto it = wordRecord.begin();it != wordRecord.end();it++){
            if(it->second > recordNumber){
                recordNumber = it->second;
                result = it -> first;
            }
        }
        return result;
    }
};
```
