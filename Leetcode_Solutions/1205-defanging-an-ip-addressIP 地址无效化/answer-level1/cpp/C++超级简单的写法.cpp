```
class Solution {
public:
    string defangIPaddr(string address) {
        string result;
        for(int i(0);i<address.size();i++)
        {
            if(address[i]=='.')
            {
                result=result+"[.]";
            }
            else
            {
                result.push_back(address[i]);
            }
        }
        return result;
    }
};
```
简单的正序遍历而已
击败100%和79%