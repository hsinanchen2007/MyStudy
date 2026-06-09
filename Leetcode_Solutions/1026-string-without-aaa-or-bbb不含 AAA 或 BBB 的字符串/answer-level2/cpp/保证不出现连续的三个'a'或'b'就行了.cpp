```
class Solution {
public:
    string strWithout3a3b(int A, int B) {
        string res = "";
        while(A || B){
            if(A > B){
                res += "a";
                A--;
                if(A){
                    res += "a";
                    A--;
                }
                if(B){// 确保是 aab
                    res += "b";
                    B--;
                }
            }
            if(A < B){
                res += "b";
                B--;
                if(B){
                    res += "b";
                    B--;
                }
                if(A){// 确保是 bba
                    res += "a";
                    A--;
                }
            }
            if(A == B && (A != 0 && B != 0)){
                if(res[res.size() - 1] == 'a'){
                    res += "b";
                    res += "a";
                }else{           
                    res += "a";
                    res += "b";
                }
                A--;
                B--;
            }
        }
        return res;
    }
};
```
![微信截图_20191208105942.png](https://pic.leetcode-cn.com/abd51c871883aa91ce007ef351fc6b1f35d680a186ed5b5d3ba968c1122f8d43-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20191208105942.png)
