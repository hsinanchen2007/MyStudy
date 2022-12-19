class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int n = A.size();
        if(n <= 2)
        return true;
        bool flag1 = false, flag2 = false;//增，减
        if(A[0] <= A[1])
        {
            flag1 = true;
        }
        if(A[0] >= A[1])
        {
            flag2 = true;
        }
        for(int i = 1; i < (A.size() - 1); i++)
        {
           if(flag1 == true && A[i] > A[i + 1])
           {
               flag1 = false;
           }
           if(flag2 == true && A[i] < A[i + 1])
           {
               flag2 = false;
           }
        }
        if(flag1 || flag2)
        return true;
        else 
        return false;
    }
};
static const auto io_speed_up=[]{
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();```
代码块
```
