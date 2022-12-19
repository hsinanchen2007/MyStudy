```cpp
class Solution {
public:
    //解法1:C++二进制容器
    int hammingWeight_1(uint32_t n) {
        bitset<32> b(n);
        return b.count();//返回1的个数
    }
    
    //解法2：除2取余法
    int hammingWeight_2(uint32_t n) {
        int count=0;
        while(n){
            if(n%2==1)count++;
            n/=2;
        }
        return count;
    }
    
    //解法3：直接判读最低为是否为1即可
    int hammingWeight_3(uint32_t n) {
        int count=0;
        while(n){
            count+=n&1;//比如111与1相与得到001，所以直接判断最低位是不是1就好了
            n>>=1;//缩小2倍，给面试官装逼用的
        }
        return count;
    }
    
    //解法4：技巧法。由于在二进制表示中，数字n中最低位的1总是对应n-1中的0。因此，将n和n-1与运算总是n中最低位的1变成0（最低位的0不考虑）,并保持其他位不变。
    int hammingWeight_4(uint32_t n) {
        int count=0;
        while(n){
            count++;
            n&=n-1;
        }
        return count;
    }
};
```
注：这里说明一下，第四种解法，在二进制表示中，数字n中最低位的1总是对应n-1中的0。因此，将n和n-1与运算总是能把n中最低位的1变成0 ，并保持其他位不变。

[![image.png](https://pic.leetcode-cn.com/91507deb7e435c63ef465a54feb2fcac5916b2fd521ca64c926fdaeeca1616c7-image.png)]()

