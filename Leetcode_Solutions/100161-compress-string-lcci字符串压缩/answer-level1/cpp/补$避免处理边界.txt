![图片.png](https://pic.leetcode-cn.com/cadc1407ab4e38a49d9d883b669fd8ad24003a9e2ec4eacc75e9f09d7363b233-%E5%9B%BE%E7%89%87.png)
class Solution {
public:
    string compressString(string S) {
        int n=S.size();
        if(n==1)return S;
        string newS=S;
        newS+='$';
        string dst="";
        dst+=newS[0];
        int count=1;
        for(int i=1;i<=n;i++){
            if(newS[i]==newS[i-1]){
                count++;
            }
            else{
                dst+=to_string(count);
                if(newS[i]!='$'){
                    dst+=newS[i];
                    count=1;
                }
            }
        }
        if(dst.size()>=n)
            return S;
        return dst;
    }
};