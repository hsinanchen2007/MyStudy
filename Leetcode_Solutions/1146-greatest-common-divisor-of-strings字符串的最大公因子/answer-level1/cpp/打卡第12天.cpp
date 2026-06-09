求出最大公约数作为长度， 然后求出子串
```
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1.empty() || str2.empty()) return "";
        if(str1[0]!=str2[0]) return "";
        unsigned l1 =str1.size(), l2=str2.size();

        unsigned g = gcd(l1, l2);
        string m = str2.substr(0,g);
      
        unsigned i = 0;
        while(i<l1){
           
          
            if(m.compare(str1.substr(i,g))){
              
            return "";
            }
            i+=g;
        }
        return m;

    }
    unsigned gcd( unsigned a, unsigned b){
        unsigned m = a>b?a:b;
        unsigned n = a>b?b:a;
        if(n==0) return m;
        return gcd(m-n, n);

    }
};
```
