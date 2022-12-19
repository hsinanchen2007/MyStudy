```
class Solution {
public:
    int longestMountain(vector<int>& A) {  //这题应该算作easy
        int len=A.size();
        int start;
        int res=0;
        for(int i=0;i<len-1;i++) {
            if(A[i]<A[i+1]) {
                int cnt=0;
                while(i+1<len&&A[i]<A[i+1]) {
                    cnt++;
                    i++;
                }
                cnt++;
                if(i+1<len&&A[i]>A[i+1]) {
                    while(i+1<len&&A[i]>A[i+1]) {
                        cnt++;
                        i++;
                    }
                    i--;
                    res=max(res,cnt);
                }
            }
        }
        return res;
    }
};
```
