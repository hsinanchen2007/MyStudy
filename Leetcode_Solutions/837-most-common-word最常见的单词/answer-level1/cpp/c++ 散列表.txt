### 解题思路
先用transform函数将字符串转为小写，再遍历字符串搜索单词，建立map 对应的key-value关系，key是单词，value是单词出现次数。
再遍历banned数组，对这些ban的单词出现次数设为INT_MIN，再创建一个迭代器遍历map，找到最大value对应的单词即可

### 代码

```cpp
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        transform(paragraph.begin(),paragraph.end(),paragraph.begin(),::tolower);
        string word="";
        map<string,int> m;
        for(int i=0;i<paragraph.size();i++){
            if(paragraph[i]>='a'&&paragraph[i]<='z'){
                word+=paragraph[i];
                continue;
            }
            if(word.size()>0){
                m[word]++;
                word="";
            }           
        }
        if(word.size()>0)
            m[word]++;
        map<string,int>::iterator it;
        for(int i=0;i<banned.size();i++)
            m[banned[i]]=INT_MIN;
        string ans_key="";
        int ans_value=0;
        for(it=m.begin();it!=m.end();it++){
            if(it->second>ans_value)
            {
                ans_value=it->second;
                ans_key=it->first;
            }
        }
        return ans_key;
    }
};
```