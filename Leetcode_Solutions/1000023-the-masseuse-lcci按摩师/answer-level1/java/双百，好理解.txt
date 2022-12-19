```
public static int massage(int[] nums) {
        //将下面三行代码放在前面可以用于对长度<=1的数组直接返回结果
        int len = nums.length;
        if (len == 0) return 0;
        if (len == 1) return nums[0];
        //定义一个长度为len+1的数组用于放每个长度所对应最大值（最长时间值）
       int[] d = new int[len+1];
       //将已知的子问题结果存入数组
       d[0] = 0;d[1] = nums[0];
        //将长度为2到len的子问题的结果计算出来并存入数组中
        for (int k = 2; k <=len; k++) {
//对长度为K的问题，其结果是基于长度为K-2和长度为K-1的子问题的结果的。关系如下面的递推公式所示。
            d[k] = Math.max(nums[k-1]+d[k-2],d[k-1]);
            System.out.println(d[k]);
        }
        //d[len]中所存的就是所求的最大值
        return d[len];
    }
```
