在建立空栈时添加标志元素‘#’,以便后续检查是否匹配完好。

```
class Solution {
public:
    bool isValid(string s) {
        map<char,char> tMap;
        tMap['(']=')';
        tMap['[']=']';
        tMap['{']='}';

        stack<char> res;
        res.push('#');
        for(int i=0;i<s.size();++i)
        {
            if(s[i]==tMap[res.top()])
                res.pop();
            else
                res.push(s[i]);
        }
        if(res.top()=='#')
            return true;
        return false;
    }
};
```
