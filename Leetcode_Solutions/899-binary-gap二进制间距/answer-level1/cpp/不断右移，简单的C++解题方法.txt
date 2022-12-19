class Solution {
public:
    int binaryGap(int N) {
        if((N & (N-1)) == 0)
        {
            return 0;
        }
        int count0 = 1;
        int count1 = 0;
        int max = 0;
        while(N)
        {
            if(N%2 == 1)
            {
                count1 = 1;
                max = max>count0?max:count0;
                count0 = 1;
            }else if(count1 == 1)
            {
                count0++;
            }
            N>>=1;
        }
        return max;
    }
};