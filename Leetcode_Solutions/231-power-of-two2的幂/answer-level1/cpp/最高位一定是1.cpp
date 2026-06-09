因为最高为取模运算到最后，结果一定是1，所以，只要最后返回为1就是true其他就是false

class Solution {
public:
    bool isPowerOfTwo(int n) {
         if(n==1){
            return true;
        }else
        {
            if(n<1){
                return false;
            }else
            {
                if(n%2==0){
                    int x=n;
                    while(x!=1){
                        if(x%2==0){
                            x=x/2;
                        }else
                        {
                            return false;
                        }
                    }
                    return true;
                }else
                {
                    return false;
                }
            }
        }
    }
};