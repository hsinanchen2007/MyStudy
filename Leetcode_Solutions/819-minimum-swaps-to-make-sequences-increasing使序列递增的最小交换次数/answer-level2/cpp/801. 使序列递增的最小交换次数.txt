```
class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int n=A.size();
        int step_keep=0;
        int step_swap=1;
        for(int i=1;i<n;++i)
        {
            bool b1=(A[i]>A[i-1]&&B[i]>B[i-1]);
            bool b2=(A[i]>B[i-1]&&B[i]>A[i-1]);
            if(b1&&b2)
            {
                step_keep=min(step_keep,step_swap);
                step_swap=step_keep+1;
            }
            else if(b1)
            {
                ++step_swap;
            }
            else if(b2)
            {
                swap(step_keep,step_swap);
                ++step_swap;
            }
            else
            {
                return -1;
            }
        }
        return min(step_keep,step_swap);
    }
};
```
