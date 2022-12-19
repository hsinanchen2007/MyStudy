```
class Solution {
public:
    int hammingDistance(int x, int y) {
        int a = x ^ y; //异或
        //再统计x二进制1的个数，与1进行与运算
        int num = 0;
        while(a != 0)
        {
            if(a & 1 != 0)
                num++;
            a = a >> 1;  
        }
        return num;
    }
};
```
