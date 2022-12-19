- 遍历字符串，根据不同情况做出不同操作，要注意**结尾字符**的情况讨论。
- 执行用时 :12 ms, 在所有 C++ 提交中击败了66.96%的用户。
- 内存消耗 :8.8 MB, 在所有 C++ 提交中击败了94.67%的用户。
```
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        map<string,int> result;
        string buffer="";
        string tmp;
        int count=0;
        for(int i=0;i<paragraph.length();i++){
            //若是大写字母
            if(paragraph[i]>='A'&&paragraph[i]<='Z')buffer.push_back(paragraph[i]+32);
            //若是小写字母
            else if(paragraph[i]>='a'&&paragraph[i]<='z')buffer.push_back(paragraph[i]);
            else{
                if(buffer=="")continue;
                //查找result里是否已有buffer字符串的key
                map<string,int>::iterator it;
                it=result.find(buffer);
                //若存在，value+1
                if (it != result.end())result.at(buffer)++;
                //若不存在，新建一个<key,value>
                else result[buffer]=1;
                //重置各变量
                buffer="";
                continue;
            }
            //若是最后一个字符，且是字母
            if(i+1==paragraph.length()){
                if(buffer=="")continue;
                //查找result里是否已有buffer字符串的key
                map<string,int>::iterator it;
                it=result.find(buffer);
                //若存在，value+1
                if (it != result.end())result.at(buffer)++;
                //若不存在，新建一个<key,value>
                else result[buffer]=1;
                //重置各变量
                buffer="";
            }
        }
        //从result中删去banned有的单词
        for(int i=0;i<banned.size();i++){
            map<string,int>::iterator it;
            it=result.find(banned[i]);
            if (it != result.end())result.erase(it);
        }
        //遍历result，查找value值最大的key
        map<string,int>::iterator it;
        it=result.begin();
        while(it!=result.end()){
            if(it->second>count){
                tmp=it->first;
                count=it->second;
            }
            it++;
        }
        return tmp;
    }
};
```
