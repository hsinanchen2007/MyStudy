### 解题思路
先利用cmp自定义排序，按照长度由大到小。然后开始建立S = S+words[i]+‘#’，#的作用是为了使用find函数，不会因为内部字符串重复而影响结果。

### 代码

```cpp
bool cmp(string a,string b){
    return a.size()>b.size();
}
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        string S;
        S = S+words[0]+'#';
        for(int i=1;i<words.size();i++){
            string::size_type k = S.find(words[i]+'#');
            if(k==string::npos){
                S = S+words[i]+'#';
            }
        }
        return S.size();
    }
};
```