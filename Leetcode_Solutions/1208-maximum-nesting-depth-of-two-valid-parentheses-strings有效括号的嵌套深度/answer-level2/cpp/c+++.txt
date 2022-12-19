### 解题思路
保持两个结果集深度尽量同步上涨
### 代码

```cpp
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int>res;
        int a=0,b=0;
        for(int i=0;i<seq.size();i++){
            if(seq[i]=='('){
                if(a>=b){
                    res.push_back(1);
                    b++;
                }
                else{
                    res.push_back(0);
                    a++;
                }
            }
            if(seq[i]==')'){
                if(a>=b){
                    res.push_back(0);
                    a--;
                }
                else{
                    res.push_back(1);
                    b--;
                }
            }
        }
        return res;
    }
};
```