### 解题思路

递归所有字典序

### 代码

```cpp
class Solution {
public:
    int ind =0;
    vector<int> ret;
    int nn;
    vector<int> lexicalOrder(int n) {
        ret = vector<int>(n);
        nn=n;
        for(int i=1;i<=9;i++){
            if(i<=n)ret[ind++]=i;
            helper(i);
        }
        return ret;
    }
    void helper(int a){
        a=a*10;
        if(a>nn)return;
        for(int i=0;i<=9;i++){
            int b=a+i;
            if(b<=nn){
                ret[ind++]=b;
                helper(b);
            }
        }
    }
};
```