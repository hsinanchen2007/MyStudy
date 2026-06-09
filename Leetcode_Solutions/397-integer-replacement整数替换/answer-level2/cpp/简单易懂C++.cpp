思路：
偶数的操作就是右移1位；
奇数的操作，判断次低bit是否为1，如果为1，即最低2bit为11b，此时采用加1操作，因为加1后会进位变为100b，后面右移时就少了一次基数操作

class Solution {
public:
    int integerReplacement(int n) {
        int time = 0;
        int64_t v = n;
        while (v != 1) {
            if ((v & 0x1) == 0) {
                v >>= 1;
            } else if ((v & 0x2) && v > 3) {
                v++;
            } else {
                v--;
            }
            time++;
        }
        return time;
    }
};