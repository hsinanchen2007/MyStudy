####  方法一：哈希映射
前面的问题 [349. 两个数组的交集](https://leetcode-cn.com/problems/intersection-of-two-arrays/)，我们使用 `set` 来实现线性时间复杂度。在这里，我们需要使用 `HashMap` 来跟踪每个数字出现的次数。

我们先在 `HashMap` 记录一个数组中的存在的数字和对应出现的次数。然后，我们遍历第二个数组，检查数字在 `HashMap` 中是否存在，如果存在且计数为正，则将该数字添加到答案并减少 `HashMap` 中的计数。
![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvMzUwLzM1MF9hcHByb2FjaDEtdjIucG5n?x-oss-process=image/format,png)
检查数组的大小并对较小的数组进行哈希映射是一个小细节，当其中一个数组较大时，会减少内存的使用。

**算法：**
- 如果 `nums1` 元素个数大于 `nums2`，则交换数组元素。
- 对于 `nums1` 的每个元素，添加到 `HashMap m` 中，如果元素已经存在则增加对应的计数。
- 初始化 `k = 0`，记录当前交集元素个数。
- 遍历数组 `nums2`：
	-  检查元素在 `m` 是否存在，若存在且计数为正：
		- 将元素拷贝到 `nums1[k]`，且 `k++`。
		- 减少 `m` 中对应元素的计数。
- 返回 `nums1` 前 `k` 个元素。

```c++ [solution1-C++]
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size()) {
        return intersect(nums2, nums1);
    }
    unordered_map<int, int> m;
    for (auto n : nums1) {
        ++m[n];
    }
    int k = 0;
    for (auto n : nums2) {
        auto it = m.find(n);
        if (it != end(m) && --it->second >= 0) {
            nums1[k++] = n;
        }
    }
    return vector(begin(nums1), begin(nums1) + k);
}
```

```java [solution1-Java]
public int[] intersect(int[] nums1, int[] nums2) {
    if (nums1.length > nums2.length) {
        return intersect(nums2, nums1);
    }
    HashMap<Integer, Integer> m = new HashMap<>();
    for (int n : nums1) {
        m.put(n, m.getOrDefault(n, 0) + 1);
    }
    int k = 0;
    for (int n : nums2) {
        int cnt = m.getOrDefault(n, 0);
        if (cnt > 0) {
            nums1[k++] = n;
            m.put(n, cnt - 1);
        }
    }
    return Arrays.copyOfRange(nums1, 0, k);
}
```

**复杂度分析**

* 时间复杂度：$\mathcal{O}(n + m)$。其中 $n$，$m$ 分别代表了数组的大小。
* 空间复杂度：$\mathcal{O}(\min(n, m))$，我们对较小的数组进行哈希映射使用的空间。


####  方法二：排序
当输入数据是有序的，推荐使用此方法。在这里，我们对两个数组进行排序，并且使用两个指针在一次扫面找出公共的数字。
![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvMzUwLzM1MF9hcHByb2FjaDItdjIucG5n?x-oss-process=image/format,png)

**算法：**
- 对数组 `nums1` 和 `nums2` 排序。
- 初始化指针 `i`，`j` 和 `k` 为 `0`。
- 指针 `i` 指向 `nums1`，指针 `j` 指向 `nums2`：
	- 如果 `nums1[i] < nums2[j]`，则 `i++`。 
	- 如果 `nums1[i] > nums2[j]`，则 `j++`。 
	- 如果 `nums1[i] == nums2[j]`，将元素拷贝到 `nums1[k]`，且 `i++`，`j++`，`k++`。
-  返回数组 `nums1` 前 `k` 个元素。

```c++ [solution2-C++]
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    sort(begin(nums1), end(nums1));
    sort(begin(nums2), end(nums2));
    int i = 0, j = 0, k = 0;
    while (i < nums1.size() && j < nums2.size()) {
        if (nums1[i] < nums2[j]) {
            ++i;
        } else if (nums1[i] > nums2[j]) {
            ++j;
        } else {
            nums1[k++] = nums1[i++];
            ++j;
        }
    }
    return vector<int>(begin(nums1), begin(nums1) + k);
}
```

```java [solution2-Java]
public int[] intersect(int[] nums1, int[] nums2) {
    Arrays.sort(nums1);
    Arrays.sort(nums2);
    int i = 0, j = 0, k = 0;
    while (i < nums1.length && j < nums2.length) {
        if (nums1[i] < nums2[j]) {
            ++i;
        } else if (nums1[i] > nums2[j]) {
            ++j;
        } else {
            nums1[k++] = nums1[i++];
            ++j;
        }
    }
    return Arrays.copyOfRange(nums1, 0, k);
}
```

**复杂度分析**

* 时间复杂度：$\mathcal{O}(n\log{n} + m\log{m})$。其中 $n$，$m$ 分别代表了数组的大小。我们对数组进行了排序然后进行了线性扫描。
* 空间复杂度：$O(1)$，我们忽略存储答案所使用的空间，因为它对算法本身并不重要。


####  方法三：
**算法：**

这类似于方法 2。我们不使用两个指针进行迭代，而是使用内置函数来查找公共元素。在 C++ 中，我们可以使用 `set_intersection` 来排序数组（或 `multisets`）。

在 Java 中的 `retainAll` 方法并不关心一个元素在另一个集合中出现的次数。

```c++ [solution3-C++]
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    sort(begin(nums1), end(nums1));
    sort(begin(nums2), end(nums2));
    nums1.erase(set_intersection(begin(nums1), end(nums1), 
        begin(nums2), end(nums2), begin(nums1)), end(nums1));
    return nums1;
}
```

**复杂度分析**

* 时空复杂度：与方法二相同。