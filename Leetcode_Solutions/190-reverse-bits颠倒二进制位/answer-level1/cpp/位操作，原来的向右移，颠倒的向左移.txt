```
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t answer = 0;
        int i = 1;
        while(i <= 32)
        {
            answer = answer << 1;
            answer += (n & 1);
            n = n >> 1;
            i++;
        }
        return answer;
    }
};
```
