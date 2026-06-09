






/* 先对x、y进行异或，再对异或结果进行32次与操作 */

class Solution 
{
public:
    int hammingDistance(int x, int y) 
    {

        unsigned int a = 1;

        int cnt = 0;

        int temp = x ^ y;  // 异或运算，值相同结果为0，值不同结果为1

        for (int i=0; i<32; i++)
        {
            a = 1 << i;
            if ( (temp & a) > 0 )
                cnt++;
        }
        return cnt;
    }
};


