### 解题思路
因为两个字符串都要被整除，所以要设X，将其与s1，s2都比较
x必须从最小的那个里面取
for循环必须从后往前，因为返回最大的

### 代码

```cpp
class Solution {
    bool check(string t,string s){
        string ans="";
        int l=s.size()/t.size();
        for(int i=0;i<l;i++){
            ans+=t;
        }
        return ans==s;
    }

public:
    string gcdOfStrings(string str1, string str2) {
        int len1=str1.size(),len2=str2.size();
        for(int i=min(len1,len2);i>=1;i--){//因为求最大的，所以从长度大的开始
            if(len1%i==0&&len2%i==0){
                string X=str1.substr(0,i);//因为formmin限制，所以随便取一个就行
                if(check(X,str1)&&check(X,str2)) return X;
                //如果满足，那么就返回结果，后面的不需要查看
            }
        }
        return "";
    }
};
```