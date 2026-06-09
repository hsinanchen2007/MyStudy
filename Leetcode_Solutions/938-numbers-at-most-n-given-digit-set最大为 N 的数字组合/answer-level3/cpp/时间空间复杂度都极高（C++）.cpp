### 解题思路
我认为这道题的坑：
1.int转string方便些。
2.循环嵌套的使用。

### 代码

```cpp
class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& D, int N) {
        string s=to_string(N);
        int add1{};
        for(int i =1;i<s.size();++i)
        {
            add1+=pow(D.size(),i);
        }
        int add2{};
        for(int i=0;i<s.size();++i)
        {
            int tem{};
            for(int j=0;j<D.size();++j)
            {
                if(D[j][0]<s[i])
                {
                    ++tem;
                }
            }
            if(tem)
            {
                add2+=tem*pow(D.size(),s.size()-i-1);
            }
            bool flag=false;
            for(int k=0;k<D.size();++k)
            {
                if(D[k][0]==s[i])
                {
                    flag=true;
                }
            }
            if(!flag)
            {
                break;
            }
            if(flag&&i==s.size()-1)
            {
                ++add2;
            }
        }
        return add1+add2;
    }
};
```