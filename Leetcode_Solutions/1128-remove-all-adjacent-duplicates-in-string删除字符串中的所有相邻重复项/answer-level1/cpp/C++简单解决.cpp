解题思路：
设结果字符串为res
1.如果res为空，那么就放入字符串S[i]
2.如果res不为空：
①最后一位字符等于下一位S[i]，那么删除
②最后一位字符不等于下一位S[i]，添加进res中


```
#include <string>
class Solution {
public:
    string removeDuplicates(string S) {
        string res="";
        for(int i=0;i<S.length();i++){
            if(res.length()==0){
                res.push_back(S[i]);
            }else if(S[i]==res[res.length()-1]){
                res.erase(res.length()-1);
            }else{
                res.push_back(S[i]);
            }
        }
        return res;
    }
};
```
