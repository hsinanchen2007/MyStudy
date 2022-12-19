```
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> st;
        for(auto s:emails)
        {
            st.insert(getUnique(s));
        }
        return st.size();
    }
    string getUnique(string email)
    {
        int i = email.find('@');
        string local = email.substr(0, i);
        string domain = email.substr(i);
        i = local.find('+');
        if(i>0)
        {
            local = local.substr(0, i);
        }
        i = -1;
        while((i = local.find('.', i+1))>0)
        {
            local.replace(i, 1, "");
        }
        return local+domain;
    }
};
```
