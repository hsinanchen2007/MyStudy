### 解题思路
此处撰写解题思路

### 代码

```java
/*
 * Copyright (c) 2020
 * @Author:xiaoweixiang
 */

public class Solution {
    public int findMinMoves(int[] machines) {
        /**
         * 毫無思路啊 2020-02-11
         * 参考官方
         *
         */

        long sum = 0;
        for (int machine : machines) {

            sum += machine;
        }
        if (sum % machines.length != 0) {
            return -1;
        }
        int n = (int) (sum / machines.length);
        for (int i = 0; i < machines.length; i++) {
            machines[i] -= n;
        }
        int res = 0;
        int k = 0;
        int max=0;
        for (int machine : machines) {
            k += machine;
            if (Math.abs(k) > res) {
                res = Math.abs(k);
            }
            if (machine>max){
                max=machine;
            }
        }
        return Math.max(max,res);
    }
}

```