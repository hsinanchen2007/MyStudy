
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
    vector<string> finish;//储存最终结果
    huisu(S,0,finish);
    return finish;  
    }
    void huisu(string &s,int wei,vector<string> &finish){
        if(wei==s.size()-1)
        {
            if(s[wei]>='a'&& s[wei]<='z')
            {
            finish.push_back(s);
            s[wei]-=32;
            finish.push_back(s);
            return;
            }
            if(s[wei]>='A'&& s[wei]<='Z')
            {
            s[wei]+=32;
            finish.push_back(s);
            s[wei]-=32;
            finish.push_back(s);
            return;
            }
            if(s[wei]<='9'&&s[wei]>='0')
            {
            finish.push_back(s);
            return;
            }
        }
        else{
        if(s[wei]>='0' && s[wei]<='9')
        {
            huisu(s,wei+1,finish);
        }
        if(s[wei]>='a'&& s[wei]<='z')
        {
            huisu(s,wei+1,finish);
            s[wei]-=32;
            huisu(s,wei+1,finish); 
        }
        else
        if(s[wei]>='A'&& s[wei]<='Z')
        {
            s[wei]+=32;
            huisu(s,wei+1,finish);
            s[wei]-=32;
            huisu(s,wei+1,finish);  
        }
        }
    }
};