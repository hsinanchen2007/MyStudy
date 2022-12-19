```
class Solution {
public:
    bool isPerfectSquare(int num) {
        int i = 0;
        int j = num;
        while(i<=j)
        {
            long m = (i + j) / 2;
            long m2 = m*m;
            if (m2 == num)
            {
                return true;
            }
            else if(m2<num)
            {
                i = m+1;
            }
            else
            {
                j = m-1;
            }
        }
        return false;
    }
};
```
