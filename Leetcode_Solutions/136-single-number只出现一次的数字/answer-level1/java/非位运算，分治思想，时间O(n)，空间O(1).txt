除了位运算，如何满足时间复杂度 $O(n)$、空间复杂度 $O(1)$？

### 分治思想

- 目标：**所有成双成对的人群里，找到一只「单身狗」**（狗子不服！
- 做法：
  - 无需所有成双成对的人都紧密牵手（全排序，同值相邻）
  - 告诉所有人：A、B 两区，情侣同区即可（分治）
  - 排除双数人群区
  - 单数人群区必有「单身狗」（递归）

```java
// 关键伪代码
public int search(区域, begin, end) {
    int 随机某人p = 分区(); // 严格小的在A区，否则在B区

    if (A区奇数) return search(区域, begin, p - 1); // 递归A区

    for (B区);
    if (B区无情侣) return p;
    return search(区域, p + 2, end); // 递归B区(除了p这对)
}
```

```java
// 完整代码
public int singleNumber(int[] nums) {
    return search(nums, 0, nums.length - 1);
}

// T(n) = T(n/2) + O(n) + O(n/2)
private int search(int[] arr, int l, int r) {
    // base case
    if (l >= r) return arr[r];
    // O(n) 快排分区
    int p = quickPartition(arr, l, r);

    // T(n/2) 若左侧奇数，则肯定在左侧，递归搜左侧
    if ((p - l) % 2 == 1) return search(arr, l, p - 1);

    // O(n/2) 相同的一定在右侧
    for (int i = p + 1; i < r + 1; i++) {
        if (arr[i] == arr[p]) {
            // 换到p旁边，下次搜右侧时可排除
            int swap = arr[i];
            arr[i] = arr[p + 1];
            arr[p + 1] = swap;
            break;
        }
    }
    // lucky，右侧没有相同的
    if (p + 1 > r || arr[p] != arr[p + 1]) return arr[p];

    // T(n/2) unlucky, 右侧有相同的，递归搜右侧
    return search(arr, p + 2, r); // p + 2 排除了 arr[p], arr[p+1]
}

// 分区，同快速排序的分区
private int quickPartition(int[] arr, int l, int r) {
    int pivot = r, counter = l;
    for (int i = l; i < r; i++) {
        if (arr[i] < arr[pivot]) { // 小的都在左侧，相等的在右侧
            int swap = arr[i];
            arr[i] = arr[counter];
            arr[counter++] = swap;
        }
    }
    int swap = arr[counter];
    arr[counter] = arr[pivot];
    arr[pivot] = swap;
    return counter;
}
```

### 复杂度分析

- 空间复杂度 $O(1)$
  - 不计递归栈调用的内存，未开辟新数组，分区是原地操作
- 时间复杂度 $O(n)$
  - 严格说是 $O(2n)$ ，即比位运算解法的 $O(n)$ 大，但仍然是线性的时间复杂度
  - 递归的时间复杂度如何计算？参考 [主定理](https://zh.wikipedia.org/wiki/%E4%B8%BB%E5%AE%9A%E7%90%86)
  - 在 `search()` 方法中，非递归部分有两处
    - `int p = quickPartition(arr, l, r);` 分区，$O(n)$
    - `for (int i = p + 1; i < r + 1; i++)` 遍历右侧，$O(n/2)$
    - 故非递归部分时间复杂度以大的计 $O(n)$
  - 在 `search()` 方法中，递归部分分析
    - 某层的递归时间复杂度表示为 $T(n)$
    - **其下一层要么只看左侧，要么只看右侧**，故 $T(n/2)$
      - 假设刚好一半，若不是一半呢？后续会说明
  - 则算法总时间 $T(n) = T(n/2) + O(n)$

### 感性理解

- 每一层递归遍历了所有的元素已经 $O(n)$，又进行了递归，为何还是 $O(n)$？
- 会不会是 $O(nlog(n))$ ？
- 答案是肯定比 $O(nlog(n))$ 小
- 思考：$O(nlog(n))$ 是完整的快速排序的时间复杂度，但快排是分区后再递归左右两个区间，而此代码时分区后只递归其中的一个区间，故肯定比完全快排的 $O(nlog(n))$ 小

### 通过主定理证明

- 根据主定理 $T(n) = aT(n/b)+f(n)$
  - $n$ 为问题规模，$a$ 为递推的子问题数量，$n/b$ 为每个子问题的规模，$f(n)$ 为递归以外的计算工作
- 上述代码中，每层要么递归区间左侧，要么递归区间右侧，故子问题数量为 $1$，即 $a = 1$
  - 完整的快速排序是左右都要递归，故快排的 $a = 2$
- 每个子问题（下一层）的问题规模都是上一层的一半（假设分区点在中间），即 $b = 2$
- 非递归部分在上文已提及，为 `quickPartition(arr, l, r)` 的 $O(n)$
- 故此算法 $T(n) = T(n/2) + O(n)$
- 根据主定理，符合情况三：$f(n) > n^{log_b{a}} = n^{log_2{1}} = 1$
- 故最终时间复杂度 $O(n)$

### 从递归树角度统计

![image.png](https://pic.leetcode-cn.com/fa34c3958736cace9da4b19524abc3fff13447a13589bdddc89793ee7c7fec11-image.png)

- 第一层需要 $O(n)$，因为要么递归左区、要么右区，故每层只可能走其中一侧
- 第二层需要 $O(n/2)$
- 第 $k$ 层需要 $O(n/2^k)$
- 每个节点时间复杂度相加
  - $n + n/2 + n/4 + ... + n/2^k = 2n$
- 忽略常数，时间复杂度总和 $O(n)$


### 若分区点不在中间

- 假设很不巧，分区点在 $8/10$ 处（只要不是分到最左、最右，即：分到中间某个值，假设 $9998/10000$ 是一样的）
- 这个证明太长了，$T(n)=T(n-2)+O(n)$，**左侧至少两个是有成双成对的**，故 $T(n-2)$
  - 若左侧只有一个，那么那一个就是「单身狗」
- 结论仍然是 $O(n)$，参考 [b站麻省理工的算法导论课程](https://www.bilibili.com/video/BV1Tb411M7FA?p=4) 的 20:05 开始，以及 [b站麻省理工的算法导论课程](https://www.bilibili.com/video/BV1Tb411M7FA?p=6) 的 15:44 开始

### 分到最左、最右怎么办

- 可考虑随机分区点，而非每次都取最右侧的 `int pivot = r` 为分区点，参考 [b站麻省理工的算法导论课程](https://www.bilibili.com/video/BV1Tb411M7FA?p=4) 的 41:21 开始
- 若最右，则该点就是「单身狗」
- 若最左，非常不幸，继续搜。若每次都最左，将导致时间复杂度下降到 $n^2$

### 一些后记

- 题目是简单题，也的确有许多方法做出来，符合时间、空间复杂度要求的，可以有 python 的数学法、位运算，都很简洁
- 但由于没有找到相同的题解（也许有但未找到，若找到请补充…），而笔者认为分治思想在这里得到很好的体现，且有机会写一个可能极有争议的时间复杂度分析，非常难得，故还是决定花些时间留下此篇
- 相同的思考题有：无需数组求第 `k` 大元素，也是 $O(n)$
  - [面试题40. 最小的k个数](https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof)
  - 快排分区，看分区的左侧有几个，决定下一层递归左侧还是右侧
  - 真的很精彩（不是说我的题解，是指分治思想的应用