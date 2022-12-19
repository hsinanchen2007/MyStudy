### 方法一：临时数组拷贝
这个方法是最原始的方法，也是初学者最开始能够想到的方法，思路比较简单。

将非0数值拷贝到一个新的临时数组当中，处理好后再讲临时数组的数值拷贝会原数组。

```java

    /**
     * 使用一个临时数组保存非0数值，处理好后再将其复制回原数组
     * 时间复杂度 O(n)
     * 空间复杂度 O(n)
     */
    private void moveZeroes(int[] nums) {
        int[] tmp = new int[nums.length];

        int cur = 0;
        for (int num : nums) {
            if (num != 0) {
                tmp[cur++] = num;
            }
        }
        System.arraycopy(tmp, 0, nums, 0, nums.length);
    }
```
### 方法二：插入法
从插入排序取得的思想。

数组依次从前往后遍历，找到非0数值，然后往回找到可以放置的位置

```java
    /**
     * 采用类似插入法的处理，将非0数值直接往前移动
     * 时间复杂度为O(n^2)
     * 空间复杂度为O(1)
     */
    private void moveZeroes2(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 0) {
                continue;
            }
            for (int j = i; j > 0; j--) {
                if (nums[j - 1] != 0) {
                    break;
                }
                int tmp = nums[j];
                nums[j] = nums[j - 1];
                nums[j - 1] = tmp;
            }
        }
    }
```

### 方法三：双指针法，插入优化法
这个方法其实是针对插入法的优化，使用一个慢指针记录可以交换的位置，这样不用再像插入法那样依次找到可以插入的位置。

```java
    /**
     * 双指针法
     * 第一个指针称为快指针，下面用i表示。用于查找非0的数值
     * 第二个指针称为慢指针，下面用move表示。用于表示可以将非0数值移动到的位置
     * 时间复杂度O(n)
     * 空间复杂度O(1)
     */
    private void moveZeroes3(int[] nums) {
        int move = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != 0) {
                nums[move] = nums[i];
                move++;
            }
        }
        for (int i = move; i < nums.length; i++) {
            nums[i] = 0;
        }
    }
```
### 方法四：指针优化法

```java
    /**
     * 双指针法
     * 对上面 {@link #moveZeroes3(int[])} 进行优化，最后将0拷贝的过程使用交换直接替代，避免多了一层循环（如果0非常多的时候这个效率比较高）
     */
    private void moveZeroes4(int[] nums) {
        int move = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != 0) {
                int tmp = nums[move];
                nums[move] = nums[i];
                nums[i] = tmp;
                move++;
            }
        }
    }
```