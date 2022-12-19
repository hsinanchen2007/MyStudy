### 解题思路
####解法一：
使用额外的数组来进行复制修改，在进行回赋，刚开始没把题目最后的要求看完时就想了这种比较low的方法，然后最后看到才发现题目要求空间复杂度为O(1).
这种方法不行，该方法的时间复杂度为O(n),空间复杂度为O(n);
--但是发现力扣官方解答给了这种方法。

### 代码

```java
class Solution {
    public void rotate(int[] nums, int k) {
        int[] tempnums = new int[nums.length];

        for (int i = 0 ; i < nums.length ; i++) {
            //(i + k) % n 可以直接得到旋转过后的数组下标
            tempnums[(i + k) % nums.length] = nums[i];
        }

        for (int i = 0 ; i < nums.length ; i++) {
            nums[i] = tempnums[i];
        }


    }
}
```


####解法二：
就是用直接替换的方法，直接将某个下标的值进行移动，但是要将被替换的值进行保存，一直移动到回到原来的位置。

###代码

```java
class Solution {
    public void rotate(int[] nums, int k) {
        k = k % nums.length;
        int count = 0;
        for (int i = 0 ; count < nums.length ; i++) {
            int preNum  = nums[i];
            int currentIndex = i;
            do {
                int nextIndex = (currentIndex + k) % nums.length;
                int temp = nums[nextIndex];
                nums[nextIndex] = preNum;
                preNum = temp;
                count++;
                currentIndex = nextIndex;

            } while (i != currentIndex);
        } 

    }
}
```
