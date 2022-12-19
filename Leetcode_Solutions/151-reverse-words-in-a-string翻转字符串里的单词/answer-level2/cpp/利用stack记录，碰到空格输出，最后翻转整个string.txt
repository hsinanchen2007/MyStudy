class Solution {
public:
    string reverseWords(string s) {

        trim(s);
        string temp;
        stack<char> st;
        for(string::iterator it = s.begin();it!=s.end();it++)
        {
            if((*it)!=' ')
                st.push(static_cast<char>(*it));
            else
            {
                while(!st.empty())
                {
                    temp += st.top();
                    st.pop();
                }
                if((*(it+1))!=' ')
                     temp += ' ';
            }
            if(it+1==s.end())
                while(!st.empty())
                {
                    temp += st.top();
                    st.pop();
                }
                
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
    std::string& trim(std::string &s)   
    {  
        if (s.empty())   
        {  
             return s;  
        }  
  
         s.erase(0,s.find_first_not_of(" "));  
         s.erase(s.find_last_not_of(" ") + 1);  
         return s;  
    } 
};