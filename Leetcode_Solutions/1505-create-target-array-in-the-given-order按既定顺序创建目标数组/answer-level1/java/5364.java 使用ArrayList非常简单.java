// ### 解法

// ```java
public int[] createTargetArray(int[] nums, int[] index) {
        int n = nums.length;
        List<Integer> res = new ArrayList<>();
        for(int i = 0; i < n; i++){
            res.add(index[i], nums[i]);
        }
        int[] target = new int[n];
        for(int i = 0; i < n; i++){
            target[i] = res.get(i);
        }
        return target;
    }
// ```

// 思路分析：

// * 题目啰嗦一大堆，其实就是不断在数组的指定的索引`index[i]`处插入元素。这里注意题目提示中有一个限制条件`index[i] <= i`，也就是说在插入第`i`个元素时，索引最多为为最后一个元素。
// * 有了上述条件，直接使用java中`ArrayList`类中的`add(int index, Object o)`函数即可将制定元素插入到指定位置。最后再将`List`中元素依次放到数组中即可。
// * `ArrayList`是使用数组进行实现，当然这里我们也可以自己写一个数组的实现，不过每次插入都需要进行大量的数组的移动。时间复杂度为$O(n^2)$的。为了避免大量数组的移动，也可以采用链表来进行插入过程，最后顺序遍历转换为数组。

// 运行结果：

// * 难度 easy。 1ms

// 更多LeetCode题解请看我的[github](https://github.com/ustcyyw/yyw_algorithm)，地址https://github.com/ustcyyw/yyw_algorithm。还有别的小项目也很好玩~卑微求个小星星💖