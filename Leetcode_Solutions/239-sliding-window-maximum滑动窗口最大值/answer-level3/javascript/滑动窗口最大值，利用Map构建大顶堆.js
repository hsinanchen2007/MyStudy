### 解题思路
![image.png](https://pic.leetcode-cn.com/3c86e179f4ed5993c40d77c7ca8f375f6c2d5d91b6a189fdbbb18a2d6de5b4d6-image.png)


### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */

/*
const queue = {
    value: 2, // 值
    index: 3 // 堆位置
}; 
*/
// 大顶堆搞定滑动窗口，常规思路
// 这里用到了Map的有序，用Map来虚构一个队列，delete和set模仿入队与出队；
// 大致分三步
// 第一步： 初始化容量为K的最小堆：堆中的值是Map的索引，Map队列会存储这个索引在堆中的位置
// 第二步： 遍历数组(k, length)，先取出队列中头部位置的值，根据值存储的索引，将新入队的值，
// 插入到堆中;
// 第三步，调整堆
// 如果大于父节点，交换向上调整，依次向上迭代；
// 否则，向下调整，找出子节点较大的节点，交换位置，并依次继续向下迭代；
// 最小堆调整完后，堆顶即为当前滑动窗口最大值；
var maxSlidingWindow = function(nums, k) {
    if (nums.length === 0) {
        return [];
    } 
    const map = new Map();
    const tree = [];
    const output = [];
    // 建立第一个堆；
    const first = nums.slice(0, k);
    // 堆索引交换，map中索引更新；
    function swap(arr, lastIndex, newIndex) {
        let temp = arr[lastIndex];
        map.get(temp).index = newIndex;
        map.get(arr[newIndex]).index = lastIndex;
        arr[lastIndex] = arr[newIndex];
        arr[newIndex] = temp;
    }
    function compare(a, b) {
        // console.log(a, b);
        return map.get(a).val >= map.get(b).val;
    }
    // 大顶堆调整；
    function heapify(arr, index) {
        const length = arr.length;
        if (length < 2) {
            return;
        }
        let last = Math.floor((index - 1) / 2);
        // 父节点大于子节点；向上比较结束；
        while(last >= 0) {
            if (compare(arr[last], arr[index])) {
                break;
            }
            swap(arr, last, index);
            index = last;
            last = Math.floor((index - 1) / 2);
        }
        // 向下调整, 靠右
        while(index < length) {
            let left =  index*2 + 1;
            let right = index*2 + 2;
            let largest = index;
            if (left < length && !compare(arr[largest], arr[left])) {
                largest = left;
            }

            if (right < length && !compare(arr[largest], arr[right])) {
                largest = right;
            }

            if (largest === index) {
                break;
            }
            swap(arr, largest, index);
            index = largest;
        }
    }
    // 第一步：构建容量为K的大顶堆，堆顶为最大值
    for(let i = 0; i < k; i ++) {
        map.set(i, { val: nums[i], index: i });
        tree.push(i);
        heapify(tree, i);
    }
    // 获取第一个大顶堆的值
    output.push(map.get(tree[0]).val);
    for(let j = k; j < nums.length; j++) {
        const head = map.get(j - k);
        //第二步： 出队入队，模拟滑动窗口
        map.delete(j - k);
        map.set(j, { index: head.index, val: nums[j] });
        tree[head.index] = j;
        //第三步：调整堆
        heapify(tree, head.index);
        // 获取堆顶值
        output.push(map.get(tree[0]).val);
    }
    return output;
};
```