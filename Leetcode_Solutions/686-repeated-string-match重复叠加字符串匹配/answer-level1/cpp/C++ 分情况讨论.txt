
        1.B包含A：k=B.size()/A.size() 向上取整，结果只可能是<=k+1而不会更大了
        2.B不包含A，则结果一定不会大于2
            2.1 A包含B return 1
            2.2 A不包含B，看2*A是否包含B，包含return 2；不包含return -1；

```
class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        if(A==B)return 1;
        if(B.find(A)!=string::npos){
            int k = ceil(double(B.size())/A.size());
            string tmp1="",tmp2="";
            for(int j=0;j<k;j++){
                tmp1+=A;
            }
            for(int j=0;j<k+1;j++){
                tmp2+=A;
            }
            if(tmp1.find(B)!=string::npos)
                return k;
            if(tmp2.find(B)!=string::npos)
                return k+1;
            return -1;    
        }
        else{
            if(A.find(B)!=string::npos)return 1;
            string s= A+A;
            if(s.find(B)!=string::npos)
                return 2;
            else return -1;
        }
    }
};
```
