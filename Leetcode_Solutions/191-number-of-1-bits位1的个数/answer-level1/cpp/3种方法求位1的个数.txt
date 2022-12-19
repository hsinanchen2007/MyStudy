# stl法
```
class Solution {
public:
    int hammingWeight(uint32_t n) {
        bitset<32> bit(n);
        return bit.count();
    }
};
```
# 巧妙消除1法
每一次的 n & (n-1) 都可以把n最后一个1给变成0
```
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int sum = 0;
        while(n){
                n&=(n-1);
                ++sum;
        }
        return sum;
    }
};
```
# 平行算法求位1的个数
若相邻的两个数为00则结果为00， 相邻的两个数为01或10则结果为01，相邻两个数为11则结果为10，也就是先小范围统计每两位中1的个数，后面的步骤在累计有多少个1.
```
class Solution {
public:
    int hammingWeight(uint32_t n) {
        unsigned int temp = n;
        temp = (temp & 0x55555555) + ((temp>> 1) & 0x55555555);  //temp相邻位相加  
        temp = (temp & 0x33333333) + ((temp >> 2) & 0x33333333);  //temp相邻（以2为单位）相加
        temp = (temp & 0x0f0f0f0f) + ((temp>> 4) & 0x0f0f0f0f);    //temp相邻（以4为单位）相加
        temp = (temp & 0xff00ff) + ((temp>> 8) & 0xff00ff);       //temp相邻（以8为单位）相加
        temp = (temp & 0xffff) + ((temp>> 16) & 0xffff) ;          //temp相邻（以16为单位）相加
        return temp;
    }
};
```
