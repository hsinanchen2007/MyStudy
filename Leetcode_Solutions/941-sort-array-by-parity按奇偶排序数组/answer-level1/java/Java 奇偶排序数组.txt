击败绝大部分用户哦。
思路：弄一个跟现在已有数组相等长度的空数组，然后往里放数据，奇数从最后一个位置开始放，偶数从第一个位置开始放，记录两个int值，来表示奇数偶数分别已经放到哪个位置了。遍历一遍A数组就ok了
看了一下其他人的做题方式，基本都会涉及一个交换的过程。稍微感觉不妥。交换感觉更耗时间一点。或者会涉及数组拼接。数组拼接更耗费时间吧。
自恋ing。。。思路新奇呀。
```
    public int[] sortArrayByParity(int[] A) {
        int[] ret = new int[A.length];
        int min = 0, max = A.length-1;
        for (int i : A) {
            if (i % 2 == 0) {
                ret[min++] = i;
            }else {
                ret[max--] = i;
            }
        }
        return ret;
    }
```

