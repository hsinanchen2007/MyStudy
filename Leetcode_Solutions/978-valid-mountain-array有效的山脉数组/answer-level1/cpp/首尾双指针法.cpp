```
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if(A.size()<3)return false;
    	int num=A.size();
        int head=0,tail=A.size()-1;
        for(;head<num-1&&A[head]<A[head+1];++head);
        for(;tail>0&&A[tail]<A[tail-1];--tail);
        if(head==tail&&head!=0&&tail!=A.size()-1)return true;
        return false;
    }
};
```
