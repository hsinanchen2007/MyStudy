// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        return badordad(0,n,n);
    }
    int badordad(double low,double high,int n)
    {
        double mid=low+(high-low)/2;
        if(isBadVersion(mid) xor isBadVersion(mid-1))return mid;
        else if(isBadVersion(mid))return badordad(low,mid,n);
        else return badordad(mid,high,n);
    }
};