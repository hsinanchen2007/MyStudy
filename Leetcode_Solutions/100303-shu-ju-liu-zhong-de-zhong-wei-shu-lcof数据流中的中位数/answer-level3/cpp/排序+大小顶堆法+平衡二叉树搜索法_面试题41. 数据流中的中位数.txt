### 解题思路一 简单排序法
    /*
     * 方法一 简单排序法 O(nlogn) 超时
     *
     * 每添加一个数，就对当前数组进行排序std::sort()，
     * 判断数组大小为奇偶数，再取数组中间的值
     * */
### 代码

```cpp
    std::vector<double> nums;

void addNum(int num) {
    nums.push_back(num);
}

double findMedian() {
    if (nums.empty()) {
        return 0;
    }

    // 使用std::sort()函数对数组进行简单排序
    std::sort(nums.begin(), nums.end());

    int n = nums.size();
    // 总数为奇数时直接取中值
    // 总数为偶数时取中间两值的平均数
    if (n & 1) {
        return nums[n / 2];
    } else {
        return (nums[n / 2 - 1] + nums[n / 2]) / 2;
    }
}
```

### 解题思路二 插入排序法
    /*
     * 方法二 插入排序法 O(n)
     *
     * 每添加一个数，先在之前的数组中找到不小于该数的数的位置std::lower_bound()，
     * 再在找到的数的位置处插入添加的数std::insert()，则数组一直保持有序，
     * 二份查找时间O(logn)，插入时间为O(n)
     * */
### 代码

```cpp
    std::vector<double> nums;

void addNum2(int num) {
    // 数组为空时添加元素
    if (nums.empty()) {
        nums.push_back(num);
    } else {
        // 先使用std::lower_bound()找到nums范围内不小于num的数的位置
        // 在该位置前使用std::insert()插入num
        nums.insert(std::lower_bound(nums.begin(), nums.end(), num), num);
    }
}

double findMedian2() {
    if (nums.empty()) {
        return 0;
    }

    int n = nums.size();
    // 总数为奇数时直接取中值
    // 总数为偶数时取中间两值的平均数
    if (n & 1) {
        return nums[n / 2];
    } else {
        return (nums[n / 2 - 1] + nums[n / 2]) / 2;
    }
}
```

### 解题思路三 大小顶堆法
    /*
     * 方法三 大小顶堆法(优先队列) O(logn)
     *
     * 设置一个大顶堆存储较小的一半数，
     * 设置一个小顶堆存储较大的一半数，
     * 则两个堆堆顶节点必为数组中间元素。
     *
     * 而要保持大顶堆和小顶堆平衡，
     * 则大顶堆节点数量最多比小顶堆多一个或少一个，
     * 如果总共插入了k个元素，则有：
     * 1. k = 2*n + 1;    大顶堆n+1个，小顶堆n个；
     * 2. k = 2*n;        大顶堆和小顶堆都为n个。
     *
     * 这样若数组大小为奇数时，中位数为大顶堆的堆顶；
     * 数组大小为偶数时，中位数为大顶堆和小顶堆堆顶和的一半。
     *
     * 每添加一个数num时，
     * 1. 将num添加到大顶堆，此时大顶堆比小顶堆多一个元素，
     *    为保持小顶堆平衡，从大顶堆中取堆顶，添加到小顶堆中；
     * 2. 在操作1后，小顶堆可能比大顶堆保留更多元素，
     *    为保持大顶堆平衡，从小顶堆取堆顶，添加到大顶堆。
     *
     * 举例：输入[41, 35, 62, 4, 97, 108]
     * Adding number 41
     * MaxHeap lo: [41]           // MaxHeap stores the largest value at the top (index 0)
     * MinHeap hi: []             // MinHeap stores the smallest value at the top (index 0)
     * Median is 41
     * =======================
     * Adding number 35
     * MaxHeap lo: [35]
     * MinHeap hi: [41]
     * Median is 38
     * =======================
     * Adding number 62
     * MaxHeap lo: [41, 35]
     * MinHeap hi: [62]
     * Median is 41
     * =======================
     * Adding number 4
     * MaxHeap lo: [35, 4]
     * MinHeap hi: [41, 62]
     * Median is 38
     * =======================
     * Adding number 97
     * MaxHeap lo: [41, 35, 4]
     * MinHeap hi: [62, 97]
     * Median is 41
     * =======================
     * Adding number 108
     * MaxHeap lo: [41, 35, 4]
     * MinHeap hi: [62, 97, 108]
     * Median is 51.5
     *
     * 最坏情况下，从顶部有三个堆插入两个堆删除，每个需要O(logn)
     * */
### 代码

```cpp
    // 大顶堆
    std::priority_queue<double> qmax;
    // 小顶堆
    std::priority_queue<double, std::vector<double>, std::greater<>> qmin;

void addNum3(int num) {
    // 先将元素添加到大顶堆
    qmax.push(num);

    // 再将大顶堆的堆顶即最大元素添加到小顶堆
    qmin.push(qmax.top());
    // 大顶堆中弹出刚刚添加到小顶堆中的数
    qmax.pop();

    // 如果大顶堆数量比小顶堆少
    // （理想情况是大顶堆数量比小顶堆大1或相等）
    if (qmax.size() < qmin.size()) {
        // 则将小顶堆堆顶即最小元素添加到大顶堆
        qmax.push(qmin.top());
        // 小顶堆中弹出刚刚添加到大顶堆中的数
        qmin.pop();
    }
}

double findMedian3() {
    // 大顶堆数量大于小顶堆1个，取大顶堆堆顶
    // 大顶堆数量等于小顶堆，取两堆堆顶平均数
    if (qmax.size() > qmin.size()) {
        return qmax.top();
    } else {
        return (qmax.top() + qmin.top()) / 2;
    }
}
```

### 解题思路四 平衡二叉搜索树法
    /*
     * 方法四 平衡二叉搜索树法(AVL树) O(logn)
     *
     * 平衡二叉搜索树将树的高度保持在对数范围内，
     * 中位数在树根或它的一个子树上。
     * 使用multiset类模拟平衡二叉树的行为，
     * 同时保持两个指针，一个用于较中位数低的元素，
     * 另一个用于较中位数高的元素。
     * 当数组总数为奇数时，两指针指向同一中值元素;
     * 当数组总数为偶数时，指针指向两元素的平均值为中位数。
     *
     * 平衡二叉搜索树的构建是O(logn)
     * */
### 代码

```cpp
    // 平衡二叉搜索树
    std::multiset<double> data;
    std::multiset<double>::iterator mid;

void addNum4(int num) {
    // 当前平衡二叉搜索树的元素数量
    const int n = data.size();
    // 添加元素num
    data.insert(num);

    // 如果n=0,即树为空，添加第一个元素
    //
    // 如果添加元素小于当前中位数，
    // 若当前树大小为奇数，则中位数不变
    // 若当前树大小为偶数，则中位数为原中位数的前1个元素
    //
    // 如果添加元素大于等于当前中位数，
    // 若当前树大小为奇数，则中位数为原中位数的后1个元素
    // 若当前树大小为偶数，则中位数不变
    if (!n) {
        mid = data.begin();
    } else if (num < *mid) {
        mid = (n & 1 ? mid : std::prev(mid));
    } else {
        mid = (n & 1 ? std::next(mid) : mid);
    }
}

double findMedian4() {
    const int n = data.size();
    // n % 2 - 1 为0时，表示树大小为奇数，此时返回中位数mid
    // n % 2 - 1 为-1时，表示树大小为偶数，此时返回*mid和mid前1个元素的和的均值
    return (*mid + *std::next(mid, n % 2 - 1)) / 2;
}
```