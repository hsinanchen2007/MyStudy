```
class Solution {
public:
    int firstBadVersion(int n) {
        long i = 1;
        long j = n;
        long m;
        while(i<=j)
        {
            m = (i+j+1)/2;
            if(isBadVersion(m))
                j = m-1;
            else
                i = m+1;
        }
        return i;
    }
};
```
第二种条件
```
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long i = 1;
        long j = n;
        long m;
        while(i<j)
        {
            m = (i+j)/2;
            if(isBadVersion(m))
                j = m;
            else
                i = m+1;
        }
        return i;
    }
};
```
