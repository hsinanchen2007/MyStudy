/**
 * Project:
 * Author : zhaozhen
 * Email  :
 * Date   : 2019/8/27
 *
 * 解题思路：java 位运算 注意一点 左移右边空出的位用0填补高位左移溢出则舍弃该高位,  右移左边空出的位用0(+)或者1(-)填补。正数用0填补，负数用1填补
 *
 * 负数 左移变小,右移动变大; 正数 左移变大,右移动变小;  0 一直是本身  -1右移动一直是自己 负数右移动变大最终停在-1
 * 
 * 位运算 取某一位用1&
 */
```

public int hammingWeight(int n) {

        int low = 0;
        int count = 0;
        int i = 32;
        while(i-- > 0){
            low = 1&n;
            if(low == 1){
                count++;
            }
            n = n >> 1;
        }
        return count;
    }
```