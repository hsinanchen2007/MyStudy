```
int add(int a, int b) {
        int ans = a ^ b;
        unsigned int bit = (unsigned int)(a & b) << 1;
        while(bit)
        {
            int tmp = ans;
            ans ^= bit;
            bit = (tmp & bit) << 1;
        }
        return ans;
    }
```
