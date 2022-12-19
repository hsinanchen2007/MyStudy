## 解题思路
先算出最后的位置，从后往前依次赋值
注意原串指针curendpos和新串指针realendpos，不要混淆
## 代码
```
class Solution {
public:
    string replaceSpaces(string S, int length) {
        vector<int> pos;
        for(int i=0;i<length;i++){
            if(S[i]==' '){
                pos.push_back(i);
            }
        }
        int endpos = length-1 + 2*pos.size();
        int curendpos = length-1;
        int realendpos = endpos;
        for(int i=pos.size()-1;i>=0;i--){
            for(int j=curendpos;j>=pos[i]+1;j--){
                S[realendpos--]=S[j];
            }
            S[realendpos--]='0';
            S[realendpos--]='2';
            S[realendpos--]='%';
            curendpos=pos[i]-1;
        }
        return S.substr(0,endpos+1);
    }
};
```
