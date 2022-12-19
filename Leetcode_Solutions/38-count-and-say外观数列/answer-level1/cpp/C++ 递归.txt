
class Solution {
public:
    string countAndSay(int n) {
        string result;
        RecursiveConstruct(n, result);
        return result;
    }
    void RecursiveConstruct(int n,string &s){
        if(n==1){
            s="1";
            return;
        }
        if(n==2){
            s="11";
            return;
        }
        RecursiveConstruct(n-1, s);
        
        string tempResult={};
        int number = 1;
        for(int i=1; i<s.size();i++){
            if(s[i]==s[i-1]){
                number++;
                continue;
            }
            tempResult+=number+'0';
            tempResult+=s[i-1];
            number=1;
        }
        tempResult+=number+'0';
        tempResult+=*(s.end()-1);
        s=tempResult;
    }
};