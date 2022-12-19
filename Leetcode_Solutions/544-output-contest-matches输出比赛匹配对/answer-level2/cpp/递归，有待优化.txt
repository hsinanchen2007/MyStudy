### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/1396be1f3ab4290ed196fbc0aa269aa950e7a887b5543e1f56677ca0432794ba-image.png)

### 代码

```cpp
class Solution {
public:

    string findContestMatch(int n) {
        vector<string> res;
        for(int i=0;i<n;i++){
            res.push_back(to_string(i+1));
        }
        for(int j=n;j>=1;j/=2){
            if(j==1) return res[0];
            for(int i=0;i<j/2;i++){
                res[i] = "("+res[i]+","+res[j-i-1]+")";
            }
        }
        return res[0];
        
    }
};
```