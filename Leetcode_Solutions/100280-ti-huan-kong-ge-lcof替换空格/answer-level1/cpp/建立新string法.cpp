### 解题思路


### 代码

```cpp
class Solution {
public:
    string replaceSpace(string s) {
        if(s.size()==0) return "";
        //方法二：建立一个新的string
        string s2;
        for (auto c:s)
        {
            if (c==' ')
            {
                s2=s2+"%20";
            }
            else
            s2=s2+c;
        }
        return s2;
    

    }
};
```