C++贪心，原理一样
```
class Solution {
public:
    const int N=3;

    struct Mychar{
        char ch;
        int n;
    };

    static bool cmpMychar(Mychar x, Mychar y){
        return x.n>y.n;
    }
    
    string longestDiverseString(int a, int b, int c) {
        Mychar A={'a',a};
        Mychar B={'b',b};
        Mychar C={'c',c};
        Mychar charArr[]={A,B,C};
        sort(charArr, charArr+N, cmpMychar);
        char p1=' ';
        char p2=' ';
        string ans="";
        while(charArr[0].n>0){
            char x=' ';
            if(!(p1==p2 && p2==charArr[0].ch)){
                x=charArr[0].ch;
                charArr[0].n--;
            }else{
                if(charArr[1].n>0){
                    x=charArr[1].ch;
                    charArr[1].n--;
                }else{
                    break;
                }
            }
            p1=p2;
            p2=x;
            ans.append(1,x);
            sort(charArr, charArr+N, cmpMychar);
        }
        return ans;
    }
};
```
