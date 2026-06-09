### 解题思路
直接上代码

### 代码

```cpp
class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size()>b.size()){
            int count=a.size()-b.size();
            while(count-->0)
            b='0'+b;
        }
        else if(a.size()<b.size()){
            int count=b.size()-a.size();
            while(count-->0)
            a='0'+a;
        }
        else NULL;
        for(int i=a.size()-1;i>0;i--){
            a[i]+=b[i]-'0';
            if(a[i]>='2')
            a[i-1]+=1,a[i]-=2;
        }
        a[0]+=b[0]-'0';
        if(a[0]>='2'){
        a[0]-=2;
        a='1'+a;
        }
        return a;
    }
};
```