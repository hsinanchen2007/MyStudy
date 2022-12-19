### 解题思路
一开始暴力解，超时，于是改用hash。说实话，感觉如果字符串长度和范围很大且离散，如（0<len<1000）还是第一种暴力好些

### 代码


```cpp
//超时超时超时警告
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int cnt=0,num=0,n=words.size(),len;
        sort(words.begin(),words.end(),[](string a,string b){return a.length()<b.length();});
        for(int i=0;i<n;i++){
            len=words[i].length();
            num+=len+1;
            for(int j=i+1;j<n;j++)
                if(words[j].substr(words[j].length()-len,len)==words[i]){
                    cnt+=len+1;
                    break;
                }
        }
            return num-cnt;
    }
};
```

```cpp
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
       unordered_set<string> ms;
       sort(words.begin(),words.end(),[](string a,string b){return a.length()>b.length();});
       int num=0,cnt=0;
       for(string str:words){
           int len=str.size();
           if(ms.find(str)==ms.end()){
               num+=len+1;
                for(int i=0;i<len;i++){
                    string tp=str.substr(i);
                    if(ms.find(tp)!=ms.end())break;
                    else ms.insert(tp);
                }
           }
       }
       return num;
    }
};
```