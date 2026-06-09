#### 方法 1： 使用 Collection.sort()

**算法**

直观地，我们可以将数组中的元素按照与目标 `x` 的差的绝对值排序，排好序后前 k 个元素就是我们需要的答案。

```Java []
class Solution {
    public List<Integer> findClosestElements(int[] arr, int k, int x) {
        List<Integer> ret = Arrays.stream(arr).boxed().collect(Collectors.toList());
        Collections.sort(ret, (a,b) -> a == b ? a - b : Math.abs(a-x) - Math.abs(b-x));
        ret = ret.subList(0, k);
        Collections.sort(ret);
        return ret;
    }
}
```

**复杂度分析**

* 时间复杂度： $O(n\log n)$。 Collections.sort() 使用二叉排序所以时间复杂度是 $O(n\log n)$。

* 空间复杂度： $O(k)$。就地排序不需要额外的空间。但是生成长度为 $k$ 的子列表需要消耗空间。

#### 方法 2：二叉查找和双指针

**算法**
原本的数组是有序的，所以我们可以像如下步骤利用这一特点。
1. 如果目标 `x` 小于等于有序数组的第一个元素，那么前 `k` 个元素就是答案。
2. 类似的，如果目标 `x` 大于等于有序数组的最后一个元素，那么最后 `k` 个元素就是答案。
3. 其他情况，我们可以使用二分查找来找到恰好大于 `x` 一点点的元素的索引 `index` 。然后让 `low` 等于 `index` 左边 `k-1` 个位置的索引，`high` 等于 `index` 右边 `k-1` 个位置的索引。我们需要的 $k$ 个数字肯定在范围 [index-k-1, index+k-1] 里面。所以我们可以根据以下规则缩小范围以得到答案。
    * 如果 `low` 小于 `0` 或者 `low` 对应的元素比 `high` 对应的元素更接近 `x` ，那么减小 `high` 索引。
    * 如果 `high` 大于最后一个元素的索引 `arr.size()-1` 或者它比起 `low` 对应的元素更接近 `x` ，那么增加 `low` 索引。
    * 当且仅当 [low, high] 之间恰好有 k 个元素，循环终止，此时范围内的数就是答案。

```Java []
public class Solution {
 	public List<Integer> findClosestElements(int[] arr, int k, int x) {
        List<Integer> ret = Arrays.stream(arr).boxed().collect(Collectors.toList());
		int n = ret.size();
		if (x <= ret.get(0)) {
			return ret.subList(0, k);
		} else if (ret.get(n - 1) <= x) {
			return ret.subList(n - k, n);
		} else {
			int index = Collections.binarySearch(ret, x);
			if (index < 0)
				index = -index - 1;
			int low = Math.max(0, index - k - 1), high = Math.min(ret.size() - 1, index + k - 1);

			while (high - low > k - 1) {
				if ((x - ret.get(low)) <= (ret.get(high) - x))
					high--;
				else if ((x - ret.get(low)) > (ret.get(high) - x))
					low++;
				else
					System.out.println("unhandled case: " + low + " " + high);
			}
			return ret.subList(low, high + 1);
		}
	}
}
```

**复杂度分析**

* 时间复杂度： $O(\log n +k)$。$O(\log n)$ 是二分查找的时间，$O(k)$ 是压缩剩 $k$ 个元素的时间。

* 空间复杂度： $O(k)$。产生结果数组所需要的空间。
