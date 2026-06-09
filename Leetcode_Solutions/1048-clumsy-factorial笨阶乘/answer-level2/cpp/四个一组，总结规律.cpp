```
class Solution {
public:
    int clumsy(int N) {
        int ret = 0;
        int data[] = {1,2,6,7};
        int data2[] = {1, 1, 2, 6};
        if(N<=4)
            return data[N-1];
        ret = N*(N-1)/(N-2)+(N-3);
        N -= 4;
        ret -= 4*(N/4);
        N = N%4;
        ret -= data2[N];
        return ret;
    }
};
```
