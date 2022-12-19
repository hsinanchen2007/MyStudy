### 解题思路
使用p与q两个指针查找i位置前后第一个遇到的C，分类讨论

### 代码

```cpp
class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> res;
        for(int i=0;i<S.size();i++){
            if(S[i]==C)
                res.push_back(0);
            else{
                int p=i-1,q=i+1;
                while(p>=0)
                    if(S[p]==C)
                        break;
                    else
                        p--;
                while(q<S.size())
                    if(S[q]==C)
                        break;
                    else
                        q++;
                if(p==-1)
                    res.push_back(q-i);
                else
                    if(q==S.size())
                        res.push_back(i-p);
                    else
                        res.push_back(min(i-p,q-i));
            }
        }
        return res;
    }
};
```