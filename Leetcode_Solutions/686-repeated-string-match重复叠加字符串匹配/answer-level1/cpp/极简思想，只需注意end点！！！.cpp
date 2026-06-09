### 解题思路
重复累加，当B.size()+temp.size()<n*A.size()时仍不是子串时，就可以判断false了！
原理是因为继续累加temp得到的知识重复的结果，没有意义。

### 代码

```cpp
class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int count=1;
        string temp=A;
        while(1)
        {
            if(A.find(B)!=A.npos)
                break;
            else if(A.size()>B.size()+temp.size())
                return -1;
            {
                A+=temp;
                ++count;
            }
        }
        return count;
    }
};
```