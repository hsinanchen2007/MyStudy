### 解题思路
没有用字典树，主要是没听说过这么高级的数据结构。。。。
就是把字符串按长度排序，然后从后面，由长到短，挨个比对。
如果能在当前的字符串里找到这个单词，且单词尾部后一位就是"#"，说明可以使用当前字符串匹配；否则在末尾加上这个单词+"#"。
代码少，但是比较粗糙，没啥亮点。

### 代码

```cpp
class Solution {
public:

    int minimumLengthEncoding(vector<string>& words) {
        int len=words.size();
        sort(words.begin(), words.end(), [](string &a, string &b){  
            return a.size() < b.size();  
        });
        string str="";
        for(int i=len-1;i>=0;i--){
            int findindex=str.find(words[i]);
            int index=findindex+words[i].length();
            if(findindex!=-1&&str[index]=='#') continue;
            else{
                str+=words[i]+"#";
            }
        }
        // cout<<str<<endl;
        return str.length();
    }
};
```