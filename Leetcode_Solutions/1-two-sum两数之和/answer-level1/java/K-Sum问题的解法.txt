K Sum问题比较常见，而且有较多的变种。

# [Two Sum](https://leetcode-cn.com/problems/two-sum/)

## 暴力解法

暴力解法非常简单，只需要两层循环即可，需要注意的是不能重复利用这个数组中同样的元素，所以第二层循环的起始位置是第一层循环的下标加一，其复杂度是：
- 时间复杂度 $O(n^2)$
- 空间复杂度 $O(1)$

```
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int size = nums.length;
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                if (nums[i] + nums[j] == target) {
                    return new int[]{i, j};
                }
            }
        }
        throw new IllegalArgumentException();
    }
}
```

### 空间换时间的思路

空间换时间就简单的多了，直接用一个HashMap来保存遍历过的结果，这样就只需要遍历一遍就可以了，复杂度是：
- 时间复杂度 $O(n)$
- 空间复杂度 $O(n)$

ps: 这个方法其实有弊端，因为是使用`HashMap`来做的，实际上没法保证在`HashMap`中查找效率是 $O(1)$，因为存在Hash碰撞，而`HashMap`采用了链表以及红黑树来应对Hash碰撞时的查找效率降低到 $O(n)$ 的情况的，Hash碰撞的情况下，`HashMap`的查询效率最多只能优化到 $O(log n)$。所以，只能说这个方法只能做到时间复杂度趋近于 $O(n)$

```
public class Solution {
    public int[] twoSum(int[] nums, int target) {
        final Map<Integer, Integer> indexToValueMap = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            // 这是核心部分，遍历的时候，用一个 Map 保存了 
            // key: target - nums[i] ， value: index 这样的键值对
            // 循环到后面的数值的时候，只需要看 map 中有没有保存对应的值就可以了
            final Integer value = indexToValueMap.get(nums[i]);
            if (value != null) {
                return new int[]{value, i};
            } else {
                indexToValueMap.put(target - nums[i], i);
            } 
        }
        throw new IllegalArgumentException();
    }
    
}
```

# [Two Sum II](https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/)

Two Sum中所输入的数组是无序的，所以如果我们想只遍历一次就得到结果，即意味着必须有一个类似于`HashMap`之类的容易来保存数据，否则无法找到已经遍历过的值。但是，如果这个数组是排过序的，就可以有一个更巧妙的思路了，就是利用排序这个特性。

**假设按照从小到大排序，那么这个数组拥有的特性是：**
- 它所有的元素，前一个始终小于后一个
- 只要从左向右移动指针，就可以把获得的数变大
- 同理从右往左移动指针，就可以把获得的数变小


## 双指针

然后在这个题目里，求两数之和等于target，我们可以用逼近的方法来做，即：取两个数相加，如果得到的结果大于target，那么就减小加数中的一个；如果得到的结果小于target，那么就增大加数中的一个。这两个数的初始值我们取最小值和最大值，这是因为，初始值取最大值和最小值的好处是，当我们要做增大加数操作的时候，只能操作小的那个数；要做减小加数的操作时，只能操作大的那个数。

```
public class Solution {
    public int[] twoSum(int[] nums, int target) {
        int start = 0, end = nums.length - 1;
        final int size = nums.length;
        while (start < end) {
            final int tmp = nums[end] + nums[start];
            if (target == tmp) {
                return new int[]{ start, end };
            }
            if (tmp < target) {
                start += 1;
            } else {
                end -= 1;
            }
        }
        throw new IllegalArgumentException();
    }

}
```

# [Two Sum IV](https://leetcode-cn.com/problems/two-sum-iv-input-is-a-bst/)

这一题的输入是BST，即二叉搜索树，具有如下的特性：
- 可以是一棵空树
- 如果左子树不为空，则左子树上所有的节点的值都小于它的根节点的值
- 如果右子树不为空，则右子树上所有的节点的值都大于它的根节点的值
- 它的左右子树也是二叉搜索树

这题就是把二叉搜索树和两数之和结合了一下，关于两数之和的思路都是差不多的，无非就是暴力+空间换时间的思路罢了，因为输入是二叉搜索树的缘故，就不使用双指针了，因为不容易在$(O1)$的时间内找到最大值和最小值。(虽然还是能在$O(n)$的时间复杂度内把BST直接打散为排好序的列表，然后再用双指针，但这样没太大意义，反而会让整个的查找复杂度提升到$2 * O(n)$。

所以使用空间换时间的思路来做，因为这里不需要输出索引，所以直接使用HashSet即可，因为HashSet本身就是使用HashMap来实现的，所以查找效率可以达到$O(1)$的时间复杂度。

然后这题主要考察的就是BST的遍历方式了：
- BFS
- DFS

## BFS

BFS的思路就很简单，使用队列先进先出的特性来做：
```
class Solution {
    public boolean findTarget(TreeNode root, int k) {
         final Set<Integer> integerSet = new HashSet<>();
        final LinkedList<TreeNode> queue = new LinkedList<>();
        queue.addFirst(root);
        while (!queue.isEmpty()) {
            final TreeNode currentNode = queue.peek();
            if (integerSet.contains(k - currentNode.val)) {
                return true;
            }
            integerSet.add(currentNode.val);
            if (currentNode.left != null) {
                queue.addLast(currentNode.left);
            }
            if (currentNode.right != null) {
                queue.addLast(currentNode.right);
            }
            queue.remove();
        }
        return false;
    }
}
```


## DFS

DFS就是利用栈先进后出的方式来实现。

```
class Solution {
    public boolean findTarget(TreeNode root, int k) {
        final Set<Integer> integerSet = new HashSet<>();
        // BFS 和 DFS 的差别其实就是个队列和栈的区别而已
        // 代码基本一样
        final LinkedList<TreeNode> stack = new LinkedList<>();
        stack.push(root);
        while (!stack.isEmpty()) {
            final TreeNode currentNode = stack.pop();
            if (integerSet.contains(k - currentNode.val)) {
                return true;
            }
            if (currentNode.right != null) {
                stack.push(currentNode.right);
            }
            if (currentNode.left != null) {
                stack.push(currentNode.left);
            }
            integerSet.add(currentNode.val);
        }
        return false;
        
    }
}
```


# [Three Sum](https://leetcode-cn.com/problems/3sum/)

3Sum问题其实和2Sum没啥区别，也没有更好的解法，只能在2Sum的解法之外套一层循环，这个解法的边界条件比较麻烦：
- 先对nums排序，然后写一个高效的双指针2Sum解法
- 然后外层循环

这个解法的复杂度是：
- 时间复杂度：排序时间复杂度$O(n*logn)$ + 一层循环复杂度$O(n)$ $\ *$ 双指针时间复杂度$(n)$，差不多是$O(n^2)$
- 空间复杂度：$O(n)$

```
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        final List<List<Integer>> result = new ArrayList<>();
        final int size = nums.length;
        if (size < 3) {
            return result;
        }
        // 这里是用了一次快排，复杂度是 O(n * logn)
        Arrays.sort(nums);
        // i < size - 2 条件是是因为必须有三个值
        for (int i = 0; i < size - 2; i++) {
            // 如果当前的数大于0，由于数组已经排过序，所以后面的数肯定也大于0
            // 因此就不会再存在当前数加上后面两个数等于0的情况了，可以直接返回
            if (nums[i] > 0) {
                return result;
            }
            // 去重
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int start = i + 1;
            int end = size - 1;
            int target = -nums[i];
            final List<List<Integer>> twoSumResult = twoSum(nums, start, end, target);
            for (final List<Integer> l : twoSumResult) {
                final List<Integer> tmp = new ArrayList<>(3);
                tmp.add(nums[i]);
                tmp.addAll(l);
                result.add(tmp);
            }
        }
        return result;
    }

    public List<List<Integer>> twoSum(int[] nums, int start, int end, int target) {
        final List<List<Integer>> result = new ArrayList<>();
        int size = end - start + 1;
        if (size < 2) {
            return result;
        }
        while (start < end) {
            int tmp = nums[start] + nums[end];
            if (tmp == target) {
                final List<Integer> tmpList = new ArrayList<>(2);
                tmpList.add(nums[start]);
                tmpList.add(nums[end]);
                result.add(tmpList);
                // 去重
                while (start < end && nums[start] == nums[start + 1]) {
                    start += 1;
                }
                while (start < end && nums[end] == nums[end - 1]) {
                    end -= 1;
                }
                start += 1;
                end -= 1;
            } else if (tmp < target) {
                start += 1;
            } else {
                end -= 1;
            }
        }
        return result;
    }
}

```

## [3Sum Closest](https://leetcode-cn.com/problems/3sum-closest/)

Three Sum问题的变种，题目假定了**每组输入只存在唯一答案**，反而更简单了，因为不需要去重。
思路是：
- 外层一层循环，内部双指针实现
- 空间复杂度$O(1)$，时间复杂度$O(1)$


```
class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int result = nums[0] + nums[1] + nums[2];
        int size = nums.length;
        for (int i = 0; i < size - 2; i++) {
            int start = i + 1;
            int end = size - 1;
            while (start < end) {
                int tmp = nums[i] + nums[start] + nums[end];
                if (Math.abs(target - tmp) < Math.abs(target - result)) {
                    result = tmp;
                }
                if (tmp == target) {
                    return tmp;
                }
                if (tmp < target) {
                    start += 1;
                }
                if (tmp > target) {
                    end -= 1;
                }
            } 
        }
        return result;
    }
}
```

# [Four Sum](https://leetcode-cn.com/problems/4sum/solution/)

解题思路和Three Sum差不多：
- 先写一个双指针的Two Sum实现
- 然后外层增加一个循环升级到Three Sum
- 最后在最外层再增加一个循环升级到Four Sum

```
public class Solution {
    // 这是一个不那么清真的写法，有大量的代码重复，但是这样可以看的更清楚一些
    public static List<List<Integer>> fourSum(int[] nums, int target) {
        Arrays.sort(nums);
        final int size = nums.length;
        final List<List<Integer>> result = new ArrayList<>();
        for (int i = 0; i < size - 3; i++) {
            // 去重，这个步骤比较关键
            // 需要当出现重复的时候，总是使用第一个数进行求解，然后后面出现的数都过滤掉
            if (i != 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            final List<List<Integer>> threeSumResult = threeSum(nums,
                    target - nums[i], i + 1, size - 1);
            for (final List<Integer> list : threeSumResult) {
                final List<Integer> tmpList = new ArrayList<>(4);
                tmpList.add(nums[i]);
                tmpList.addAll(list);
                result.add(tmpList);
            }

        }

        return result;
    }

    // 这部分其实和 fourSum 基本上一致，只需要注意数组的下标索引即可
    public static List<List<Integer>> threeSum(int[] nums, int target, int start, int end) {
        final int size = end - start + 1;
        final List<List<Integer>> result = new ArrayList<>();
        for (int i = 0; i < size - 2; i++) {
            // 去重
            if (i != 0 && nums[i + start] == nums[i + start - 1]) {
                continue;
            }
            final List<List<Integer>> twoSumResult = twoSum(nums, target - nums[i + start],
                    i + start + 1, end);
            for (final List<Integer> list : twoSumResult) {
                final List<Integer> tmpList = new ArrayList<>(3);
                tmpList.add(nums[i + start]);
                tmpList.addAll(list);
                result.add(tmpList);
            }

        }

        return result;
    }

    // 最终都会递归的调用 twoSum 进行求解
    // 双指针解法，参考上面 twoSum 的解析
    public static List<List<Integer>> twoSum(int[] nums, int target, int start, int end) {
        int left = start;
        int right = end;
        final List<List<Integer>> result = new ArrayList<>();

        while (left < right) {
            int tmp = nums[left] + nums[right];
            if (target == tmp) {
                final List<Integer> tmpList = new ArrayList<>(2);
                tmpList.add(nums[left]);
                tmpList.add(nums[right]);
                result.add(tmpList);
                // 去重
                while (left < right && nums[left] == nums[left + 1]) {
                    left += 1;
                }
                while (left < right && nums[right] == nums[right - 1]) {
                    right -= 1;
                }
                left += 1;
                right -= 1;
            } else if (target > tmp) {
                left += 1;
            } else {
                right -= 1;
            }
        }
        return result;
    }

}
```


# 延伸到 K-Sum 问题

从上面的Four-Sum问题的解法中，我们基本上可以确定写一个高效的twoSum解法，然后递归就可以解决K-Sum问题了。

```
public class Solution {
    public static List<List<Integer>> kSum(int[] nums, int target, int k, int start, int end) {
        Arrays.sort(nums);
        int size = end - start + 1;
        final List<List<Integer>> result = new ArrayList<>();
        if (k == 2) {
            int left = start;
            int right = end;
            while (left < right) {
                int tmp = nums[left] + nums[right];
                if (target == tmp) {
                    final List<Integer> tmpList = new ArrayList<>(2);
                    tmpList.add(nums[left]);
                    tmpList.add(nums[right]);
                    result.add(tmpList);

                    while (left < right && nums[left] == nums[left + 1]) {
                        left += 1;
                    }
                    while (left < right && nums[right] == nums[right - 1]) {
                        right -= 1;
                    }
                    left += 1;
                    right -= 1;
                } else if (target > tmp) {
                    left += 1;
                } else {
                    right -= 1;
                }
            }
            return result;
        } else {
            // 直接递归解决
            for (int i = 0; i < size - k + 1; i++) {
                if (i != 0 && nums[i + start] == nums[i - 1 + start]) {
                    continue;
                }
                final List<List<Integer>> kSumTmpResult = kSum(nums, target - nums[i + start],
                        k - 1, i + start + 1, end);
                for (final List<Integer> list : kSumTmpResult) {
                    final List<Integer> tmpList = new ArrayList<>();
                    tmpList.add(nums[i + start]);
                    tmpList.addAll(list);
                    result.add(tmpList);
                }
            }

        }
        return result;
    }

}


```

