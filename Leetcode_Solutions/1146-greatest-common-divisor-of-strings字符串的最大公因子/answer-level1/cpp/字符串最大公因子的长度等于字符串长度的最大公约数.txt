### 解题思路
如题

### 代码

```cpp
class Solution {
public:
//字符串最大公因子的长度一定等于其字符串长度的最大公因数
//找到最大公因数，再去验证字符串是否能被除尽
    string gcdOfStrings(string str1, string str2) {
        int n1 = str1.size();
        int n2 = str2.size();
        int ngcd = gcd(n1, n2);

        cout<<n1<<" "<<n2<<" "<<ngcd<<endl;
        
        cout<<n1<<" "<<n2<<" "<<ngcd<<endl;
        for(int i = 0; i < n1 / ngcd - 1; i++){
            for(int j = 0; j < ngcd; j++){
                if(str1[i*ngcd + j] != str1[(i+1)*ngcd + j])
                    return "";
            }
            if(str1[i*ngcd] != str1[(i+1)*ngcd])
                return "";
        }
        for(int i = 0; i < n2 / ngcd - 1; i++){
            for(int j = 0; j < ngcd; j++){
                if(str2[i*ngcd + j] != str2[(i+1)*ngcd + j])
                    return "";
            }
        }
        for(int i = 0; i < ngcd; i++){
            if(str1[i] != str2[i])
                return "";
        }
        
        return string(str1.begin(), str1.begin() + ngcd);
    }

    inline int gcd(int a, int b){
        for(int i = 1; i < min(a, b); i++){
            if(a % i == 0){
                int res = a / i;
                if(b % res == 0){
                    return res;
                }
            }
        }
        return 1;
    }
};
```