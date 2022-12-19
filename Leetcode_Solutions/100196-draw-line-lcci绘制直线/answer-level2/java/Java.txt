```
class Solution {
    public int[] drawLine(int length, int w, int x1, int x2, int y) {
        int[] result = new int[length];
        /**
         * 屏幕每一行数字的个数
         */
        w /= 32;
        /**
         * 直线覆盖的所有数字中索引最小值
         */
        int start = y * w + x1 / 32;
        /**
         * 直线覆盖的所有数字中索引最大值
         */
        int end = y * w + x2 / 32;

        if (start == end) {
            /**
             * 当前数字的32位二进制表示中从左向右的第x1到第x2个0要改为1
             */
            x1 -= x1 / 32 * 32;
            x2 -= x2 / 32 * 32;
            /**
             * 将直线覆盖的数字的32位二进制表示从左向右的第x1到第x2个0改为1
             */
            for (int i = x1; i <= x2; i++) {
                result[start] += 1 << (31 - i);
            }
        } else {
            /**
             * 直线覆盖的第一个数字的32位二进制表示中最右边count1个0要改为1
             */
            int count1 = 32 - (x1 - x1 / 32 * 32);
            /**
             * 直线覆盖的最后一个数字的32位二进制表示中最左边count2个0要改为1
             */
            int count2 = x2 + 1 - x2 / 32 * 32;
            /**
             * 将直线覆盖的第一个数字的32位二进制表示最右边count1个0改为1
             */
            for (int i = 0; i < count1; i++) {
                result[start] += 1 << i;
            }
            /**
             * 将直线覆盖的最后一个数字的32位二进制表示最左边count2个0改为1
             */
            for (int i = 0; i < count2; i++) {
                result[end] += 1 << (31 - i);
            }
            /**
             * 直线覆盖的除首尾外的中间那些数字全部变为0b11111111111111111111111111111111，即十进制的-1
             */
            for (int i = start + 1; i < end; i++) {
                result[i] = -1;
            }
        }
        return result;
    }
}
```
