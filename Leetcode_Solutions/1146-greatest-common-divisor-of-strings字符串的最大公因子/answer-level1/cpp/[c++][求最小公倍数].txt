
### 代码

```cpp
class Solution{
    public:
        int gcd(int m, int n){
            int r = m % n;
            return !r ? n:gcd(n,r);
        }
        string gcdOfStrings(string str1, string str2){
            if(str1 == "" || str2 == "") return "";
            if(str1.length() < str2.length()) swap(str1, str2);
            int a = str1.length(), b = str2.length();
            int g = gcd(a,b);
            for(int i=0, j=0;i < a;i++,j++){
                j = j == b? 0:j;
                if(str1[i] != str2[j]) return "";
            }
            return str1.substr(0, g);
        }
};

```