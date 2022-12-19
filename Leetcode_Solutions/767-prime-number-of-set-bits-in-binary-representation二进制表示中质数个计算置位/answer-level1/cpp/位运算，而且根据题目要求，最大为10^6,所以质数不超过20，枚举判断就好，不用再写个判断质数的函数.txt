```
class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        int num;
        int val;
        int answer = 0;
        for(int i = L; i <= R; ++i)
        {
            num = 0;
            val = i;
            while(val != 0)
            {
                if(val & 1 != 0) //判断最后一位是否为1
                    num++;
                val = val >> 1; //向右移一位
            }
            if(num == 2 || num == 3 || num == 5 || num == 7 || num == 11 || num == 13 || num == 17 || num == 19)
                answer++;
        }
        return answer;
    }
};
```
