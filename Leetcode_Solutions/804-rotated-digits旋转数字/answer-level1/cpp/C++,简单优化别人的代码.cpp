class Solution {
public:
    bool isGood(int i) 
    { 
        int a; int d = 0;
        while(i) 
        {
            a = i % 10;
            if(a == 3 || a == 4 || a == 7)
                return false;
            if(a == 2 || a == 5 || a == 6 || a == 9)
                d++;
            i /= 10;
        }
        return d==0? false : true;
    }

    int rotatedDigits(int N) 
    { 
        int i; int ret = 0;

        for(i = 0; i <= N; i++) {
            if(isGood(i))
                ret++;        
        }
        return ret;
    }
};