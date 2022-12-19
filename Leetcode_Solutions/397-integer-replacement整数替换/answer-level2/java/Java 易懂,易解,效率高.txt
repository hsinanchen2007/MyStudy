**1.如果不注意细节,坑还是挺多的;
2.n值传给Long型的m,如果n是2147483647,定义m为int类型+1立马会溢出;
3.3很特殊,拿出来,其次m如果为奇数,就和2做与运算,(m&2)==2等价于((m+1)/2)%2==0,意味着+1后的结果能被2整除再整除(整除两次),否则-1;
4.完结。**

        public int integerReplacement(int n) {
            int count = 0;
            long m = n;
            while (m != 1) {
                if (m % 2 == 0) {
                    m >>= 1;
                } else if (m == 3) {// 3 另外拿出来
                    return count + 2;
                } else if ((m & 2) == 2) {// 7 → +1 、 5 → -1
                    m += 1;
                } else {
                    m -= 1;
                }
                count++;
            }
            return count;
        }