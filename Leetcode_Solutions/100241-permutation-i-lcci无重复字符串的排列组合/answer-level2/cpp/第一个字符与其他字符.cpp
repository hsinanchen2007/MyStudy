### 解题思路
1.将字符串分为两部分：第一个字符与其他字符，再将其他字符分为第一个字符和其他字符。。。。。，一直递归
2.对整个字符串循环，每个字符做一次第一个字符。

### 代码

```cpp
class Solution {
public:
    vector<string> ans;
    void swap(char& a,char& b){
        char temp=a;
        a=b;
        b=temp;
    }
    void helper(string& S,int start){
        if(start==S.size()-1){
            ans.push_back(S);
            return;
        }
        for(int i=start;i<S.size();i++){
            swap(S[i],S[start]);//每个字符做一次第一个字符
            helper(S,start+1);//对其他字符递归处理
            swap(S[i],S[start]);
        }
    }
    vector<string> permutation(string S) {
        if(S=="") ans.push_back(S);
        else helper(S,0);
        return ans;
    }
};
```