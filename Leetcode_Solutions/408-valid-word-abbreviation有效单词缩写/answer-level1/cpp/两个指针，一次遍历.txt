### 解题思路
根据测试数据一步一步改出来。。。

### 代码

```cpp
class Solution {
public:
    int getNumber(int& pos,string s){
        int ans=0;
        while(isdigit(s[pos])){
            ans=ans*10+(s[pos]-'0');
            pos++;
        }
        pos--;//因为i自带加1
        return ans;
    }

    bool validWordAbbreviation(string word, string abbr) {
        int j=0;
        for(int i=0;i<abbr.size();i++){
            if(isdigit(abbr[i])&&abbr[i]!='0'){
                int num=getNumber(i,abbr);
                //cout<<"数字 "<<num<<endl;
                while(num--){
                    if(!word[j]) return false;
                    j++;
                }
            }
            else{
                //cout<<"字符 "<<abbr[i]<<endl;
                if(abbr[i]!=word[j++]) return false;
            }
        }
        if(j<word.size()) return false;
        return true;
    }
};
```