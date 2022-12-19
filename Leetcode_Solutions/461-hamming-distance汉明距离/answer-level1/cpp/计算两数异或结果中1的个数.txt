x异或y的结果中包含1的个数即为汉明距离
```C++ []
class Solution {
public:
    int hammingDistance(int x, int y) {
        //思路计算x异或y二进制1的数量
        int temp=x^y;
        int count=0;
        while(temp)
        {
            if(temp&1!=0)
                count++;
            temp>>=1;
        }
        return count;
    }
};
```
