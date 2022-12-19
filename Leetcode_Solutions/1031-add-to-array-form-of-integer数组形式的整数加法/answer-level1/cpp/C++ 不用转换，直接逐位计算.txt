```
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int ad=0,next=0;
        for(int i=A.size()-1;i>=0;--i){
            ad=K%10;
            K/=10;
            int pre=A[i];
            A[i]=(A[i]+ad+next)%10;
            next=(pre+ad+next)/10;
        }
        while(K!=0||next!=0){
            A.insert(A.begin(),(K%10+next)%10);
            next=(K%10+next)/10;
            K/=10;
        }
        return A;
    }
};
```
