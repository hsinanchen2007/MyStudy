```
class Solution {
    public int[] findClosedNumbers(int num) {
        int[] res = new int[]{getNext(num), getPrev(num)};
        return res;
    }

    public int getNext(int n) {
        /*
        计算c0和c1
        */
        int c = n;
        int c0 = 0;
        int c1 = 0;
        while (((c & 1) == 0) && (c != 0)) {
            c0++;
            c >>= 1;
        }
        while ((c & 1) == 1) {
            c1++;
            c >>= 1;
        }
        /*
         * 错误：若n==1111....1111000....00,那么就没有更大的数字
         */
        if (c0 + c1 == 31 || c0 + c1 == 0) {
            return -1;
        }
        int p = c0 + c1;//最右边，非拖尾0的位置
        n |= (1 << p);//翻转最右边，非拖尾0
        n &= ~((1 << p) - 1);//将p右方的所有位清零
        n |= (1 << (c1 - 1)) - 1;//将右方插入（c1-1)个1
        return n;
    }

    public int getPrev(int n) {
        int temp = n;
        int c0 = 0;
        int c1 = 0;
        while ((temp & 1) == 1) {
            c1++;
            temp >>= 1;
        }
        if (temp == 0)
            return -1;
        while (((temp & 1) == 0) && (temp != 0)) {
            c0++;
            temp >>= 1;
        }
        int p = c0 + c1;//最右边，非拖尾1的位置
        n &= ((~0) << (p + 1));//将位0到位p清零
        int mask = (1 << (c1 + 1)) - 1;//(c1+1)个1
        n |= mask << (c0 - 1);
        return n;
    }
}
```