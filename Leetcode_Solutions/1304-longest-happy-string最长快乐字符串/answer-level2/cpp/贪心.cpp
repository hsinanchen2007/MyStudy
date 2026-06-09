```c++
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string res = "";
        while((a+b+c) > 0){
            int len = res.size();
            int x = max(a,max(b,c));
            if(x == a){
                if(len < 2 || res.substr(len-2) != "aa"){
                    res += 'a';
                    a--;
                }else if(max(b,c) > 0){
                    if(b == max(b,c)){
                        res += 'b';
                        b--;
                    }else{
                        res += 'c';
                        c--;
                    }
                }else break;
            }else if(x == b){
                if(len < 2 || res.substr(len-2) != "bb"){
                    res += 'b';
                    b--;
                }else if(max(a,c) > 0){
                    if(a == max(a,c)){
                        res += 'a';
                        a--;
                    }else{
                        res += 'c';
                        c--;
                    }
                }else break;
            }else if(x == c){
                if(len < 2 || res.substr(len-2) != "cc"){
                    res += 'c';
                    c--;
                }else if(max(a,b) > 0){
                    if(a == max(a,b)){
                        res += 'a';
                        a--;
                    }else{
                        res += 'b';
                        b--;
                    }
                }else break;
            }
        }

        return res;
    }
};
```