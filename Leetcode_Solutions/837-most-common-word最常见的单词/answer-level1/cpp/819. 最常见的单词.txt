### 解题思路
字符串的题就是麻烦
用map记录禁用单词和paragraph里出现过的单词
最好先处理一下标点符号和字母大小写问题
可以先在paragraph最后加个空格统一情况

### 代码

```cpp
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        paragraph+=' ';
        unordered_map<string,int>mp1,mp2;
        for(int i=0;i<banned.size();i++){
            mp1[banned[i]]=1;
        }
        set<char>ss={'!','?',',',';','.','\''};
        for(int i=0;i<paragraph.size();i++){
            if(ss.find(paragraph[i])!=ss.end()) paragraph[i]=' ';
            else if(paragraph[i]<='Z'&&paragraph[i]>='A'){
                paragraph[i]+='a'-'A';
            } 
        }
        int i=0,j=0;
        int maxn=0;string res,s;
        while(i<paragraph.size()){
            if(paragraph[i]==' '&&j<=i){
                s=paragraph.substr(j,i-j);
                if(mp1.count(s)==0){
                    mp2[s]++;
                    if(mp2[s]>maxn){
                        maxn=mp2[s];res=s;
                    }
                }
                j=i;while(paragraph[j]==' ') j++;
            }
            i++;
        }
        return res;
    }
};
```