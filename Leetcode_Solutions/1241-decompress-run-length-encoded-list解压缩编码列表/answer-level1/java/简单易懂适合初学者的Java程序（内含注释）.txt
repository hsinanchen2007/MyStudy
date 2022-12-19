直接上代码了：
```
class Solution {
    public int[] decompressRLElist(int[] nums) {
        int[] a = new int[nums.length/2];//a数组获取nums[奇数]
        int[] b = new int[nums.length/2];//b数组获取nums[偶数]

        for (int i = 0; i < nums.length; i++){
            if (i % 2 == 0)     a[i/2] = nums[i];
            if (i % 2 == 1)     b[i/2] = nums[i];
        }

        List list = new ArrayList();//创建一个List集合来存放最终的数据

        for (int j = 0; j < a.length; j++) {
            for (int i = 0; i < a[j]; i++) {
                list.add(b[j]);
            }
        }

        int[] c = new int[list.size()];

        Iterator it = list.iterator();//将List里面的值填到c[]中

        for (int m = 0; m < c.length; m++){
            c[m] = (int) it.next();
        }

        return c;
    }
}

```

