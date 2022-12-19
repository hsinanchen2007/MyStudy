[本人博客](https://blog.csdn.net/qq_43152052/article/details/100593307)
题解：使用字符串流来分割句子，然后将句子中的单词与字符串数组里面的前缀单词进行比较。
这里与其使用前缀树，不如直接比较单词的第一个字符和前缀树组的某个元素的第一个字符效率来的快。
```cpp
class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
       istringstream line(sentence);
        string word,result="";
        while(line>>word)
        {
            int i=0;
            for(;i<dict.size();++i)
            {
                //找到前缀词，将前缀词加到result中
                if(dict[i][0]==word[0]&&word.substr(0,dict[i].size())==dict[i]){result+=dict[i]+" ";break;}
            }
            //没有找到前缀词，将原有的单词添加到result中
            if(i==dict.size())result+=word+" ";
        }
        if(result.size()>0)result.resize(result.size()-1);//删除最后一个空格
        return result;
    }
};
```
