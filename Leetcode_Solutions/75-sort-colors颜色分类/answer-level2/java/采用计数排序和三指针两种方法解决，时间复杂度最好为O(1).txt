

第一种解题思路：采用计数排序，统计0,1,2的元素出现的个数，重写当前数组（ps： 0、 1 和 2 分别表示红色、白色和蓝色）
时间复杂度 O(n + k)   空间复杂度 O(k) n为元素个数 k为元素去重后的元素个数

```
    public static void sortColors1(int[] nums) {
        // 因为只有0,1,2，所以最小值为0，最大值为 2
        int max = 2;
        int[] counts = new int[max + 1];
        // 遍历数组，统计元素出现的个数
        for (int i = 0; i < nums.length; i++) {
            counts[nums[i]]++;
        }

        int cur = 0;
        // 遍历计数数组 索引为0的位置存放0出现的个数，索引为1的位置存放1出现的个数...
        for (int i = 0; i < counts.length; i++) {
            while (counts[i]-- > 0) {
                nums[cur++] = i;
            }
        }
    }

```

第二种解题思路：三指针法。一个left指针记录左边0的位置，一个cur指针，记录扫描位置，
一个right指针记录2的位置。当cur扫描到0，就与left索引位置交换元素；
当cur扫描到2时，就与right位置的元素进行交换，同时在在判断cur位置的元素是否为2
时间复杂度为O(n), 空间复杂度为O(1)

```
    public static void sortColors2(int[] nums) {
        // 定义当前指针，记录扫描的位置
        int cur = 0;
        // 左边指针，记录左边0的位置
        int left = 0;
        // 记录右边2的位置
        int right = nums.length - 1;

        while (cur <= right) {
            int val = nums[cur];
            if (val == 0) {
                // 如果元素为0，left和cur位置的元素进行交换
                swap(nums, left++, cur++);
            }else if (val == 1) {
                // 如果元素为1，cur+1往后扫描
                cur++;
            }else {
                // 如果元素为2，right和cur位置的元素进行交换
                swap(nums, cur, right--);
            }
        }

    }

    private static void swap(int[] nums, int i1, int i2) {
        int temp = nums[i1];
        nums[i1] = nums[i2];
        nums[i2] = temp;
    }
```

