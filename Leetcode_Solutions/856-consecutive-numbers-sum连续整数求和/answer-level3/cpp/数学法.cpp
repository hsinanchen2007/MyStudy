class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int count = 0;
        if(N == 1) return 1;
        for(int i=1;i<N;i++){
            if(N / i - i/2 + 1 <= 0 && i%2 == 0)
                break;
            if(N/i - i/2 <= 0 && i%2 == 1)
                break;
            if(i % 2 == 0)
            {
                if(N % i == i / 2)
                    count++;
            }
            else
            {
                if(N % i == 0)
                    count++;
            }
        }
        return count;
    }
};