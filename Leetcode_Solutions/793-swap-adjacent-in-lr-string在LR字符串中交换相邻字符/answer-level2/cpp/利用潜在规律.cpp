### 解题思路
容易看出，若可以转换，则start和end的长度要相同，且将start和end中X去掉后，剩下的由L、R构成的字符串应该相等。还有一点，若可以转换，则将start和end中的X去掉后，剩下的两个字符串st，et应相同，且st中的第i个字符和et中第i个字符应该相同。若st的第i个字符为L，则在原start字符串中该L的位置应该小于et的第i个字符在原end字符串中的位置，若st的第i个字符为R是情况相反。

### 代码

```cpp
class Solution {
public:
    bool canTransform(string start, string end) {
        if(start.size()!=end.size())
        return false;
        string st;
        string et;
        vector<int>arr_st;
        vector<int>arr_et;
        for(int i=0;i<start.size();i++)
        if(start.at(i)!='X')
        {
            st.push_back(start.at(i));
            arr_st.push_back(i);
        }
        for(int i=0;i<end.size();i++)
        if(end.at(i)!='X')
        {
            et.push_back(end.at(i));
            arr_et.push_back(i);
        }
        if(st!=et)
        return false;
        else
        {
            for(int i=0;i<st.size();i++)
            {
                if(st.at(i)=='R')
                {
                    if(arr_st[i]>arr_et[i])
                    return false;
                }
                if(st.at(i)=='L')
                {
                    if(arr_st[i]<arr_et[i])
                    return false;
                }
            }
        };
        return true;
    }
};
```