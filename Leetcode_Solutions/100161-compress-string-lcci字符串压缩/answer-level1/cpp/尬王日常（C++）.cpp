### 解题思路
通俗易懂就是有点耗时
![image.png](https://pic.leetcode-cn.com/10bade942b8fff6ed9b4b6fc01445895f6a600506a1f1cc46e63cb79a4e0e5e8-image.png)

### 代码

```cpp
class Solution {
public:
    string compressString(string S) {
        if(S.size()==0){return "";}
        string st = "";int t = 0;int count = 1;int f = 1;
        for(int i = 0;i<S.size();i++)
        {
            if(S[i]==S[i+1]&&i+1<S.size())
            {
                count++;
            }
            else
            {
                st.push_back(S[i]);
                string temp = to_string(count);
                st+=temp;
                count = 1;f = 1;
            }
            if(st.size()>=S.size()){return S;}
        }
        return st;
    }
};
```