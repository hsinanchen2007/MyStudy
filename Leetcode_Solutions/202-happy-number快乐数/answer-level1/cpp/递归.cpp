class Solution {
public:
    set<int> num;//用于判断是否进入循环
    bool isHappy(int n) {
        int s=0;
        int n1=0;
        if(n==1)
            return true;
        else if(num.count(n))
            return false;
        else
        {
            num.insert(n);
            while(n!=0)
            {
                n1=n%10;
                n=n/10;
                s=n1*n1+s;
            }
            return isHappy(s);
        }
        
    }
};