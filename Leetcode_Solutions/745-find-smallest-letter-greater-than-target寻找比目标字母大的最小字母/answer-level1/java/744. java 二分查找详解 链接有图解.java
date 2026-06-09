// ### 两种解法（均是基于二分查找）

// ##### 1.我的解法

// ```java
public char nextGreatestLetter(char[] letters, char target) {
        int n = letters.length;
        int lo = 0, hi = n - 1;
        while(lo <= hi){
            int mid = (hi - lo) / 2 + lo;
            if(letters[mid] <= target) lo = mid + 1;
            else if(letters[mid] > target) hi = mid - 1;
            else { // 这坑的会有多个重复的元素，一直要找到它后面的第一个不同元素
                for(int i = mid; ; i = (i + 1) % n){ // 如果i从mid + 1开始的话 mid刚好是最后一个索引 就会越界。
                    if(letters[i] != letters[mid])
                        return letters[i];
                }
            }
        }
        return letters[lo % n];
    }
// ```

// 思路分析：

// * 题目已经明确指出字符数组是有序的，并且要找到某个`target`的下一个字符。那么问题就是先找到`target`在数组中的位置（如果存在）；或者找到`target`应该插入的位置（`target`不存在数组中）。然后由于这是一个有序数组，只要从`target`所在的地方往右找到一个与他不相等的元素就是答案。
// * 当查找命中时`target`的索引即为`mid`，只需要用一个循环从`mid`开始遍历，找到第一个与`target`不同的元素即为结果。注意如果循环从`mid+1`开始，`mid`如果是数组最后一个索引，`mid+1`就会越界，所以循环从`mid`开始。
// * 当查找未命中时，`lo`就是`target`应该插入的位置（原因可以参考[35. 搜索插入位置](https://github.com/ustcyyw/yyw_algorithm/blob/master/easy/BinarySearch/searchInsert.md)），那么原数组`lo`索引处的元素就是答案。
// * 一种特殊情况就是，`target`是数组中最大的字符，那么按题目给出的示例应该返回数组的第一个元素。这种情况如果在循环中调整索引的语句为`i++`则会出现数组越界，所以应该使用`i = (i + 1) % n`。PS：这种处理方式在散列表的线性探测法语队列的数组实现中也是这样。
// * 同理，如果`target`比数组中所有字符都大，那么查找未命中，此时返回`letters[lo]`数组会越界，为了避免这个问题，返回`letters[lo % n]`。
// * 时间复杂度为$O(log(n))$，但是最坏时候可能是线性的。空间复杂度为$O(1)$。

// 运行结果：

// * 执行用时 :0 ms, 在所有 Java 提交中击败了100.00%的用户
// * 内存消耗 :40.9 MB, 在所有 Java 提交中击败了5.05%的用户

// ##### 2.官方题解

// ```java
public char nextGreatestLetter2(char[] letters, char target) {
        int n = letters.length;
        int lo = 0, hi = n - 1;
        while(lo <= hi){
            int mid = (hi - lo) / 2 + lo;
            if(letters[mid] <= target) lo = mid + 1; // 这个条件厉害 一定会使得lo落在target的下一个元素。
            else hi = mid - 1;
        }
        return letters[lo % n];
    }
// ```

// 思路分析：

// * 同样是二分查找，但是对查找命中情况的处理改变之后，可以避免最坏时候出项线性时间复杂度。
// * 当查找命中时，同样让`lo = mid + 1`，这样就能保证循环结束后，`lo`落在target的下一个元素。
// * 特殊情况的处理如方法一中所述，最后要返回`letters[lo % n]`。
// * 时间复杂度为$O(log(n))$，空间复杂度为$O(1)$。

// 更多LeetCode题解请看我的[github](https://github.com/ustcyyw/yyw_algorithm)，地址https://github.com/ustcyyw/yyw_algorithm。还有别的小项目也很好玩~卑微求个小星星💖