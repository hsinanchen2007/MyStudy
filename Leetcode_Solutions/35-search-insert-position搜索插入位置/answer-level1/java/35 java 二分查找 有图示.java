// ### 解法：二分查找最简单的运用

// ```java
public int searchInsert(int[] nums, int target) {
        int lo = 0, hi = nums.length - 1;
        while(lo <= hi){
            int mid = (hi - lo) / 2 + lo;
            if(nums[mid] > target)
                hi = mid - 1;
            else if(nums[mid] < target)
                lo = mid + 1;
            else return mid;
        }
        return lo;
    }
// ```

// 思路分析：

// * 一个排序数组和一个目标值，在数组中找到目标值，这是最最标准的二分查找；如果不存在，返回它将会被按顺序插入的位置，这也是java库函数中二分查找在做的事情。

// * 举个例子画图确定一下，插入位置的索引在哪，如`[1,2,3,7,8,10]`中查找5。图示如下：

//     [无效的图片地址](https://github.com/ustcyyw/yyw_algorithm/blob/master/easy/BinarySearch/searchInsert%E5%9B%BE%E7%A4%BA.png?raw=true)

// * 可以看到，当二分查找失败的时候，返回`lo`即是按顺序要插入位置的索引。

// * 时间复杂度为$O(log(n))$，空间复杂度$O(1)$。

// 运行结果：

// * 执行用时 :0 ms, 在所有 Java 提交中击败了100.00%的用户
// * 内存消耗 :39 MB, 在所有 Java 提交中击败了27.54%的用户

// 更多LeetCode题解请看我的[github](https://github.com/ustcyyw/yyw_algorithm)，地址https://github.com/ustcyyw/yyw_algorithm。还有别的小项目也很好玩~卑微求个小星星💖