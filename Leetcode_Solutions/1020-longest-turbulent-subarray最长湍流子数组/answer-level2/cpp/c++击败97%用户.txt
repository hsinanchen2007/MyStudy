挺简单
```
class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int res=1;
        int len=A.size();
        int maxx=1, minn=1;
        int tmp_minn, tmp_maxx;
        for(int i=1;i<len;i++) {
            tmp_minn=minn;
            tmp_maxx=maxx;
            if(A[i]>A[i-1]) {
                minn=tmp_maxx+1;
                maxx=1;
            } else if(A[i]==A[i-1]) {
                maxx=minn=1;
            }
            else {
                maxx=tmp_minn+1;
                minn=1;
            }
            if(maxx>res) {
                res=maxx;
            }
            if(minn>res) {
                res=minn;
            }
        }
        return res;
    }
};
```
