![image.png](https://pic.leetcode-cn.com/b0b762eae96d0c4968e894465b0ce911b436dbd4a3c1a9b183e5720e8dde43ec-image.png)

### 解题思路

JS的内置函数sort不知道怎么实现的，我使用它内存的时候和时间都消耗的挺多的，于是换了一种方法，从C++中的快速排序迁移过来

https://blog.csdn.net/qq_42842786/article/details/94304146

快速排序算法首先需要有一个基准数，把小于基准数的放到基准数的左边，大于基准数的放到右边，再对当前基准数的左右两边的数据在进行同样的操作，直到所有的基准数归位

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
 var sortArray = function (nums) {
        function quicksort(left, right)
        {
            var key = nums[left],
                i = left,
                j = right;
            if (left > right) return;
            while (i != j) 
            {
                while (nums[j] >= key && i < j)
                    j--;
                while (nums[i] <= key && i < j)
                    i++; 
                if (i < j) 
                {
                    nums[i] = [nums[j], nums[j] = nums[i]][0];
                }
            }
            nums[left] = [nums[i], nums[i] = nums[left]][0]; //交换基准数与哨兵的值
            quicksort(left, i - 1);
            quicksort(i + 1, right);
        }
        quicksort(0, nums.length - 1);
        return nums;

    };
    var num = [4, 5, -2, 3, 9, -5, 2, 3];
    console.log(sortArray(num));
```