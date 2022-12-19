**设置三个标志点, 左边的部分等于0 右边的部分等于2 遍历中间的部分 然后维持循环变量的不变性就好了 其实就是保持循环变量的语义在循环的过程保持不变**

```
其实这类问题最关键的就是如何定义循环变量, 并在循环的过程中保持其语义不变

1. 这个问题首先定义一个循环变量 **i** 用来遍历数组
2. 然后定义一个变量zero, 使得 [0...zero] 这个区间中的值都为0 
3. 再定义一个变量two, 使得 [two...nums.length - 1] 这个区间的值都为2

要满足上述条件, 三个变量的初值如下
int i = 0;
int zero = -1;
int two = nums.length;

就是一开始三个区间都不存在, 通过i在遍历数组的过程中比较数组中的元素是否等于 0 或者 2 来不断修改 zero 和 tow 的值, 使得数组中的值满足 1,2,3 中的定义
```

**java代码如下:**

```
class Solution {
    // 3 ways quick sort
    public void sortColors(int[] nums) {
        int i = 0;
        int zero = -1; // [0, zero] == 0
        int two = nums.length; // [two...nums.length-1] == 2

        while ( i < two ) {
            if (nums[i] == 0) {
                swap(nums, i, zero+1);
                i ++;
                zero ++;
            } else if (nums[i] == 2) {
                swap(nums, i, two - 1);
                two -- ;
            } else 
                i ++;
        }
    }
    
    private void swap(int[] arr, int i, int j) {
        int t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }
}
```

