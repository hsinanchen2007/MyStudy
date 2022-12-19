思路：
    根据全排列的特性将4个数的所有组合列出，不需要考虑重复的情况，因为4个数也才24种情况
    然后根据排列的顺序组合进行比较即可得出答案
```
class Solution {
public:
    int rh,rm;
    string largestTimeFromDigits(vector<int>& A) {
        rh=-1,rm=-1;
        f(A,0);
        if(rh==-1) return "";
        string res="";
        res=res+(char)(rh/10+'0')+(char)(rh%10+'0')+":"+(char)(rm/10+'0')+(char)(rm%10+'0');
        return res;
        //return "";
    }
    void f(vector<int>& A,int k){
        if(k==4){
            int h=A[0]*10+A[1];
            int m=A[2]*10+A[3];
            if(h>=0&&h<24&&m>=0&&m<60){
                if(rh<h||(rh==h&&rm<m)){
                    rh=h,rm=m;
                }
            }
            return;
        }
        for(int i=k;i<4;i++){
            swap(A[k],A[i]);
            f(A,k+1);
            swap(A[k],A[i]);
        }
    }
};
```
