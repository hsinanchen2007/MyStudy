> 想用最简单的冒泡排序来解决，结果超时未通过。


查了一些资料，进行了几轮优化，还是死在了最后一个用例上，记录一下。

### 0. 首先辅助函数
```php
private function swap(&$nums, $i, $j)
{
    $tmp = $nums[$i];
    $nums[$i] = $nums[$j];
    $nums[$j] = $tmp;
}
```

### 1. 基础版的冒泡排序
```php
function bubbleSort($nums)
{
    $n = count($nums);
    if ($n <= 1) return $nums;
    // 外层循环控制内层循环中极值最终上浮到的位置
    for ($i = $n - 1; $i >= 0; --$i) {
        // 内层循环用来两两比较并交换
        for ($j = 0; $j < $i; ++$j) {
            if ($nums[$j] > $nums[$j + 1]) {
                $this->swap($nums, $j, $j + 1);
            }
        }
    }

    return $nums;
}
```

### 2. 优化 1：处理在排序过程中数组整体已经有序的情况，无需重复进行比较
```php
function bubbleSortOpt1($nums)
{
    $n = count($nums);
    if ($n <= 1) return $nums;
    // 外层循环控制内层循环中极值最终上浮到的位置
    for ($i = $n - 1; $i >= 0; --$i) {
        $isSorted = true;
        // 内层循环用来两两比较并交换
        for ($j = 0; $j < $i; ++$j) {
            if ($nums[$j] > $nums[$j + 1]) {
                $isSorted = false;
                $this->swap($nums, $j, $j + 1);
            }
        }

        // 数组整体已排好序，直接返回
        if ($isSorted) return $nums;
    }

    return $nums;
}
```

### 3. 优化2：数组局部有序 最后一次交换的位置，就是无序序列与有序序列的边界
```php
function bubbleSortOpt2($nums)
{
    // 在遍历过程中可以记下最后一次发生交换事件的位置，下次的内层循环就到这个位置终止，可以节约多余的比较操作.
    // 使用一个变量来保存最后一个发生了交换操作的位置，并设置为下一轮内层循环的终止位置

    // 记录这一轮循环最后一次发生交换操作的位置
    $endPos = count($nums) - 1;
    while ($endPos > 0) {
        $thisTurnEndPos = $endPos;
        for ($i = 0; $i < $thisTurnEndPos; ++$i) {
            if ($nums[$i] > $nums[$i + 1]) {
                $this->swap($nums, $i, $i + 1);
                // 设置 (更新) 最后一次发生了交换操作的位置
                $endPos = $i;
            }
        }

        // 若这一轮没有发生交换, 则证明数组已经有序, 直接返回即可
        if ($thisTurnEndPos == $endPos) {
            return $nums;
        }
    }

    return $nums;
}
```

### 4. 优化 3：同时将最大最小值归位 双向冒泡排序
```php
function bubbleSortOpt3($nums)
{
    // 设置每一轮循环的开始与结束位置
    $start = 0;
    $end = count($nums) - 1;
    while ($start < $end) {
        // 从 start 位置 end 位置过一遍安排最大值的位置
        for ($i = $start; $i < $end; ++$i) {
            if ($nums[$i] > $nums[$i + 1]) {
                $this->swap($nums, $i, $i + 1);
            }
        }
        $end--;
        // 从 end 向 start 位置过一遍, 安排最小值的位置
        for ($i = $end; $i > $start; --$i) {
            if ($nums[$i] < $nums[$i - 1]) {
                $this->swap($nums, $i, $i - 1);
            }
        }
        $start++;
    }
    return $nums;
}
```

### 5. 将上述优化 1 和 2 结合，处理数组局部有序和排序过程中整体有序的情况

```php
function bubbleSortOpt12($nums)
{
    $endPos = count($nums) - 1;
    while ($endPos > 0) {
        $thisTurnEndPos = $endPos;
        $isSorted = true;
        for ($i = 0; $i < $thisTurnEndPos; ++$i) {
            if ($nums[$i] > $nums[$i + 1]) {
                $this->swap($nums, $i, $i + 1);
                $isSorted = false;
                $endPos = $i;
            }
        }

        if ($isSorted) return $nums;
        if ($endPos == $thisTurnEndPos) return $nums;
    }

    return $nums;
}
```

### 6. 将优化 2 和 3 结合起来，从双向同时处理最大最小值，而且处理数组局部有序的情况
```php
function bubbleSortOpt23($nums)
{
    $start = $startPos = 0;
    $end = $endPos = count($nums) - 1;
    while ($start < $end) {
        // 从前向后过一遍
        for ($i = $start; $i < $end; ++$i) {
            if ($nums[$i] > $nums[$i + 1]) {
                $this->swap($nums, $i, $i + 1);
                // 记录这个交换位置
                $endPos = $i;
            }
        }
        // 设置下一轮的遍历终点
        $end = $endPos;
        // 从后向前过一遍
        for ($i = $end; $i > $start; --$i) {
            if ($nums[$i] < $nums[$i - 1]) {
                $this->swap($nums, $i, $i - 1);
                // 记录这个交换位置
                $startPos = $i;
            }
        }

        // 设置下一轮的遍历起点
        $start = $startPos;
    }

    return $nums;
}
```


### 7. 三种优化方式结合
```php
function bubbleSortOpt123($nums)
{
    $start = $startPos = 0;
    $end = $endPos = count($nums) - 1;
    while ($start < $end) {
        // 从前向后过一遍
        $isSorted = true;
        for ($i = $start; $i < $end; ++$i) {
            if ($nums[$i] > $nums[$i + 1]) {
                $this->swap($nums, $i, $i + 1);
                // 记录这个交换位置
                $endPos = $i;
                $isSorted = false;
            }
        }
        // 设置下一轮的遍历终点
        $end = $endPos;
        // 从后向前过一遍
        for ($i = $end; $i > $start; --$i) {
            if ($nums[$i] < $nums[$i - 1]) {
                $this->swap($nums, $i, $i - 1);
                // 记录这个交换位置
                $startPos = $i;
                $isSorted = false;
            }
        }

        if ($isSorted) return $nums;
        // 设置下一轮的遍历起点
        $start = $startPos;
    }

    return $nums;
}
```

提交，还是超时。

算了，换其他排序方式了。