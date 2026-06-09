直接反向记录，遍历再替换：
```
class Solution {
public:
    bool isword(char a){
        if(a-'a'>=0&&a-'z'<=0||a-'A'>=0&&a-'Z'<=0) return true;
        else return false;
    }
    string reverseOnlyLetters(string S) {
        string t="";
        for(int i=S.size();i>=0;i--){
            if(isword(S[i])) t+=S[i];
        }
        int j=0;
        for(int i=0;i<S.size();i++){
            if(isword(S[i])) S[i]=t[j++];
        }
        return S;
    }
};
```
双指针：
```
class Solution {
public:
    bool isword(char a){
        if(a-'a'>=0&&a-'z'<=0||a-'A'>=0&&a-'Z'<=0) return true;
        else return false;
    }
    string reverseOnlyLetters(string S) {
        int i=0,j=S.size()-1;
        while(i<j){
            if(isword(S[i])&&isword(S[j])){
                char temp=S[i];
                S[i]=S[j];
                S[j]=temp;
                i++,j--;
            }
            if(!isword(S[i])) i++;
            if(!isword(S[j])) j--;
        }
        return S;
    }
};
```




