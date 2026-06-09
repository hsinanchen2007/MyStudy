### 解题思路
进制转换+按位取反

### 代码

```cpp
class Solution {
public:
    int findComplement(int num) {
        vector<int> t;
        while(num!=0){
            t.push_back(num%2);
            num/=2;
        }
        for(int i=0;i<t.size();i++)
            if(t[i]==0)
                t[i]=1;
            else
                t[i]=0;
        int res=0;
        for(int i=t.size()-1;i>=0;i--)
            res=res*2+t[i];
        return res; 
    }
};
```