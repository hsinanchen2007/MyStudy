# 方法一 先排序后交换
**思路**
1. 先对数组进行从小到大排序；
2. 然后将奇数索引的元素与下一个元素进行交换即可。如$[1,2,3,4,5]$通过处理，变成$[1,3,2,5,4]$。其中$2$和$3$发生的交换，$4$和$5$发生的交换。

```java
   private void swap(int[] nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }

    public void wiggleSort(int[] nums) {
        Arrays.sort(nums);
        int len = nums.length;
        for (int i = 1; i < len - 1; i += 2) {
            swap(nums, i, i + 1);
        }
    }
```
**复杂度**
时间复杂度：$O(nlogn)$。由于进行了排序。
空间复杂度：$O(1)$。并没有开辟额外空间。

# 方法二 直接交换
**思路**
还是看奇数索引，如果奇数索引的数字比前面一个数字小，则两者进行交换，交换完之后，再跟后面一个元素比，如果小于后面一个元素的话，则二者再进行交换。这样遍历完所有的奇数索引就会生成一个摆动排序后的结果。如$[2, 1, 3]$，我们判断$1$比$2$小，交换后变成$[1,2,3]$，这时候又发现$2$比$3$小，再进行交换变成$[1,3,2]$，这样就满足要求了。

```java
    private void swap(int[] nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }

    public void wiggleSort(int[] nums) {
        int len = nums.length;
        for (int i = 1; i < len; i += 2) {
            if (nums[i] < nums[i-1]) {
                swap(nums, i, i-1);
            }

            if (i < len - 1 && nums[i] < nums[i+1]) {
                swap(nums, i, i+1);
            }
        }
    }
```
**复杂度**
时间复杂度：$O(n)$
空间复杂度：$O(1)$
