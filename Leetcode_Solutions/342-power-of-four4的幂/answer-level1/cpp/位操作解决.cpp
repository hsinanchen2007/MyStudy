位操作~~ 4的幂一定满足：该数的二进制的1只有一个且1一定在奇数位(从低到高），比如64:1000000 (1在第7位）
```
class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num < 0)
            return false;
        int i = 0;
        int tag = 0;
        int one_num = 0;
        while(num != 0)
        {
            if(num & 1 != 0)
            {
                one_num++;
                tag = i + 1;
            }
            i++;
            num = num >> 1;
        }
        if(tag % 2 != 0 && one_num == 1)
            return true;
        else
            return false;
        
    }
};
```
