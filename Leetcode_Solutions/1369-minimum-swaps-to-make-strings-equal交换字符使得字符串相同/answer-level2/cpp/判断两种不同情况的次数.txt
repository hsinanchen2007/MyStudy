`8ms` `8.6MB`
```
#include "Solution1247.h"
#include "string"
using namespace std;

class Solution1247 {
public:
    int minimumSwap(string s1, string s2) {
        int a = 0,b = 0;
        for(int i=0;i<s1.length();i++){
            if(s1[i]==s2[i]){
                continue;
            }
            else if(s1[i]=='x'&&s2[i]=='y'){
                a++;
            }else{
                b++;
            }
        }
        if(a%2==b%2){
            return a/2+b/2+a%2+b%2;
        }
        return -1;
    }
};
```
