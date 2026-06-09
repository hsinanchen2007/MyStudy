### 解题思路
正向反向各遍历一次更新最近距离即可,每次遍历将当前位置和上一个C比较计算距离.

### 代码

```cpp
class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int n = S.size();
        vector<int> res(n,n);
        int lastC = -n;
        for(int i=0;i<n;i++){
            if(S[i]==C)lastC = i;
            res[i] = min(res[i],i-lastC);
        }

        for(int i=lastC-1;i>=0;i--){
            if(S[i]==C)lastC = i;
            res[i] = min(res[i],lastC-i);
        }

        return res;
    }
};
```