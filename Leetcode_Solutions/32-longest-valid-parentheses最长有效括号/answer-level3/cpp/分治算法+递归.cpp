class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size()<=0)
            return 0;
        int len=0;
        longestmatch(s,len);
        return len;
    }
    void longestmatch(string s,int& len){
        if(s.size()<=1)
            return;
        if(s.size()%2==1){//长度是奇数
            longestmatch(s.substr(0,s.size()-1),len);
            longestmatch(s.substr(1,s.size()-1),len);
        }
        else{
            bool jud=match(s);
            if(jud){
                if(len<s.size()){
                    len=s.size();
                    return;
                }
            }
            else{
                longestmatch(s.substr(0,s.size()-2),len);
                longestmatch(s.substr(1,s.size()-2),len);
                longestmatch(s.substr(2,s.size()-2),len);
            }
        }
    }
    bool match(string& s){
        if(s.size()%2==1)
            return false;
        stack<char> temp;
        for(auto c:s){
            if(c=='(')
                temp.push(c);
            else{
                if(temp.empty())
                    return false;
                temp.pop();
            }
        }
        if(temp.empty())
            return true;
        return false;
    }
};