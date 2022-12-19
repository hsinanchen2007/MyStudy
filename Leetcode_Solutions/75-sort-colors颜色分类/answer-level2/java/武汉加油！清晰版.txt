## 思路

三路归并，其实也是 Arrays.sort() 这里采用的方法，也是三色旗的解决方案。

三个指针，分别是 left、cur、right。left指向数组最左侧，right指向数组最右侧，cur代表当前正在遍历的数组元素，当 cur 遍历的元素是 0 时，将 cur 指向的元素 与 p0 指向的元素交换，然后 cur++，p0++。当 cur 遍历的元素是 1 时，cur++。当 cur 遍历的元素是 2 时，将 cur 指向的元素与 p2 指向的元素交换，然后 p2--，cur不动！！！直到 cur > p2 ,循环结束（即全部扫描完毕）。

对于以上，有一个难点！

* ***为何 cur 在于 p0 交换时需要 p0++，cur++；而在 cur 与 p2 交换时，却只需要 p2++？***

对于上面这个问题，有两种解释思路：1.cur 与 p0 交换需要自加，是因为其左边已经扫描过了，交换过来的值也是之前就扫描过了的，而右边不是， p2 交换过来的值 cur 并没有扫描过；2.当 cur 与 p0 不是一个指向同一个索引值时，那 cur 指向的索引值如果发生交换，那交换过来的一定是 1（原因是只有当遍历过的节点有1，p0 和 cur 才不会同步），而 如果索引是 1 刚好也就不用有任何操作，所以可以直接继续向右扫描，当 cur 和 p0 指向的是同一个索引，那交换就等于没交换，故也是直接可以向右扫描，右边的就不行。

## 代码

```java
class Solution {
    public void sortColors(int[] nums) {
        int left = 0, cur = 0;
        int right = nums.length - 1;
        while (cur <= right) {
            if (nums[cur] == 0) {
                swap(nums, left, cur);
                left++;
                cur++;
            } else if (nums[cur] == 2) {
                swap(nums, right, cur);
                right--;
            } else cur++;
        }
    }

    public void swap(int[] nums, int a, int b) {
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }
}
```