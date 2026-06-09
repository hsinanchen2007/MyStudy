## 方法一、排序数组

时间复杂度 O(nlogn)

空间复杂度 O(1)

```
impl Solution {
  pub fn get_least_numbers(arr: Vec<i32>, k: i32) -> Vec<i32> {
    let mut arr = arr;
    arr.sort();
    arr[..k as usize].iter().cloned().collect()
  }
}
```

## 方法二、调用 BinaryHeap 实现的最小堆

时间复杂度 O(nlogn)

因为把整个数组保存到了堆里面，所以空间复杂度 O(n)

```
use std::cmp::Reverse;
use std::collections::BinaryHeap;

impl Solution {
  pub fn get_least_numbers(arr: Vec<i32>, k: i32) -> Vec<i32> {
    let mut heap = BinaryHeap::with_capacity(arr.len());
    for num in arr {
      heap.push(Reverse(num));
    }
    let mut result = Vec::with_capacity(k as usize);
    for _ in 0..k {
      result.push(heap.pop().unwrap().0);
    }
    result
  }
}
```

## 方法三、调用 BinaryHeap 实现的最大堆

时间复杂度 O(nlogk)

因为堆里面只保存了 k 个元素，所以空间复杂度 O(k)

```
use std::collections::BinaryHeap;

impl Solution {
  pub fn get_least_numbers(arr: Vec<i32>, k: i32) -> Vec<i32> {
    let mut heap = BinaryHeap::with_capacity(k as usize);
    for num in arr {
      if heap.len() < k as usize {
        heap.push(num);
      } else {
        if !heap.is_empty() && *heap.peek().unwrap() > num {
          heap.pop();
          heap.push(num);
        }
      }
    }
    heap.iter().cloned().collect()
  }
}
```

## 方法四、利用快速排序的 partition 函数

时间复杂度 O(n)

没有申请而外空间，所以空间复杂度 O(1)

但是该方法会修改原数组。

```
impl Solution {
  pub fn get_least_numbers(arr: Vec<i32>, k: i32) -> Vec<i32> {
    let mut arr = arr;
    let k = k - 1;
    let mut start: i32 = 0;
    let mut end: i32 = (arr.len() - 1) as i32;
    let mut partition_index = -1;
    while partition_index != k {
      partition_index = Solution::partition(&mut arr, start as usize, end as usize);
      if partition_index < k {
        start = partition_index + 1;
      } else {
        end = partition_index - 1;
      }
    }
    arr[..((k + 1) as usize)].iter().cloned().collect()
  }

  fn partition(arr: &mut [i32], start: usize, end: usize) -> i32 {
    let pivot = arr[end];
    let mut partition_index = start;
    for i in start..end {
      if arr[i] < pivot {
        arr.swap(i, partition_index);
        partition_index += 1;
      }
    }
    arr.swap(partition_index, end);
    partition_index as i32
  }
}
```
