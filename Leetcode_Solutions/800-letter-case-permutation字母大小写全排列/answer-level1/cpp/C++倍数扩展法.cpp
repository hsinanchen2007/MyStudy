### 解题思路
解题思路如下：
一次遍历
```
for(int i=0;i<S.size();++i){//完成逐个取数，得到如[a,A].[1],[b,B],[2]类似的形式
```
取得各个结点值，如果是字母，结点值为[大写字母，小写字母]，如[A,a]或者[a,A]这样的形式。

然后将结点从头到尾进行遍历:
如果结点元素为1，则stri元素个数不变；
如果结点元素个数为2，则stri元素个数增加1倍。
至此完成。

### 代码

```cpp
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<vector<char>> elem;
        for(int i=0;i<S.size();++i){//完成逐个取数，得到如[a,A].[1],[b,B],[2]类似的形式
           vector<char> tem;
           if(S[i]>='0'&&S[i]<='9') {tem.push_back(S[i]);}
           else {
               tem.push_back(S[i]);
               if(S[i]>='a'&&S[i]<='z'){tem.push_back('A'+S[i]-'a');}
               else {tem.push_back('a'+S[i]-'A');}
           } 
           elem.push_back(tem);
           tem.clear();
        }

        vector<string> stri;//char转为string函数
        if(elem[0].size()==2) {stri.push_back( string(1,elem[0][0]) );stri.push_back( string(1,elem[0][1]) );}
        else stri.push_back( string(1,elem[0][0]) );
       for(int i=1;i<elem.size();++i){
           int len =stri.size();
           for(int j=0;j<len;++j){
               string tem;
               if(elem[i].size()==2){
                   tem = stri[j];
                   stri[j]+= elem[i][0];
                   stri.push_back( (tem+=elem[i][1]) );
               }
               else {stri[j]+=elem[i][0];}
           }
       } 
        return stri;
    }
};
```