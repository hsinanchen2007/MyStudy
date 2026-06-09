### 方法
方法1：暴力法 
方法2：使用额外空间
方法3：使用环状替换
方法4：使用反转

### 方法1
暴力法：旋转k次，每次将数组旋转1次（双层循环，外层遍历移动位数，内层遍历数组长度）
### 代码
```javascript
var rotate = function(nums, k) {
    const len = nums && nums.length
    for (let i = 0; i < k; i++) {
        // 遍历k, 每次暂存数组当前的最后项
        let previous = nums[len-1]
        for (let j = 0; j < len; j++) {
            // 遍历数组长度
            // 暂存当前下标项数据
            let temp = nums[j]
            // 先将当前下标项设置为previos
            nums[j] = previous
            // 后将previous设置为temp(当前下标项数据)
            previous = temp
        }
    }
};
```
复杂度分析：
时间复杂度： O(n*k)。每个元素都被移动一步(O(n)) k(O(k))次
空间复杂度： O(1)。常数个额外常量空间

### 方法2
使用额外空间：我们可以用一个额外的数组来将每个元素放到正确的位置上，也就是原本数组里下标为i的我们把它放到 (i+2)%数组长度 的位置。然后把新的数组拷贝到原数组中
### 代码
```javascript
var rotate = function(nums, k) {
    const len = nums && nums.length
    // 额外数组
    let newList = []
    for (let i = 0; i < len; i++) {
        // 遍历原数组
        // (下标+k)%数组长度 位置的数据设置为原数组当前下标的数据(移动 (下标+k)%数组长度 位)
        newList[(i+k)%len] = nums[i] 
    }
    for (let j = 0; j < len; j++) {
        // 数据搬移，拷贝回原数组
        nums[j] = newList[j]
    }
};
```
复杂度分析：
时间复杂度：O(n)。将数据放到新数组中需要遍历一次，将数据从新数组搬移回原数组需要遍历一次
空间复杂度：O(n)。新数组需要原数组长度的空间

### 方法3
使用环状替换：
### 代码
```javascript
var rotate = function(nums, k) {
    const len = nums && nums.length
    // k对len取模，k超过len时相当于k%len的情况, 最少旋转次数(k对数组长度取模可以忽略无效的循环（转完之后还是数组本身）)
    k = k % len
    // 记数
    let count = 0
    for (let start = 0; start < len; start++) {
        // for循环 启动外层循环
        if (count >= len) { // 环状的外层循环终止条件
            //  什么时候就保证所有元素都换完了呢？n个元素，换n次，即保证所有元素替换完成。所以最开始用一个count用来计数
            //  当统计数量count与len相等时，已经进行所有数据的挪动，不再进入下面的do while, 并跳出for循环
            break
        }
        let current = start
        let previous = nums[current]
        do {
            // do while内层循环 -- 从start位置开始，往后移动k个距离，直到执行完do之后 current=next=(current+k)%len 与 start 相等时(next回到了数组遍历所在的下标，之后，不再进入while循环)，结束while循环，重新回到for循环
            let next = (current+k) % len
            let temp = nums[next]

            nums[next] = previous
            previous = temp
            current = next

            count++
        } while (current !== start) // do while 终止条件 start !== current
    }
};
``` 
复杂度分析：
时间复杂度：O(n)。数组中每个数据只搬移了一次
空间复杂度：O(1)。使用了常数个额外空间

说明：
数据搬移工作发生在do while循环里，for循环只是用来启动原数组初始下标

### 方法4
使用反转：这个方法基于这个事实：当我们旋转数组 k 次， k%n 个尾部元素会被移动到头部，剩下的元素会被向后移动。
        在这个方法中，我们首先将所有元素反转。然后反转前 k 个元素，再反转后面 n−k 个元素，就能得到想要的结果。
        假设 n=7 且 k=3 。
        原始数组                  : 1 2 3 4 5 6 7
        反转所有数字后             : 7 6 5 4 3 2 1
        反转前 k 个数字后          : 5 6 7 4 3 2 1
        反转后 n-k 个数字后        : 5 6 7 1 2 3 4 --> 结果
### 代码
```javascript
var rotate = function(nums, k) {
    const len = nums && nums.length
    // 必须先 k 对 数组长度 取模，否则k超出数组长度时会有问题
    k %= len
    // // 反转原数组 [0, len-1]
    reverse(nums, 0, len - 1)
    // 反转前k个 [0, k-1]
    reverse(nums, 0, k - 1)
    // 反转k个后面 [k, len-1]
    reverse(nums, k, len - 1)
};
function reverse (nums, start, end) {
    while (start <= end) {
        let temp = nums[start]
        nums[start] = nums[end]
        nums[end] = temp
        start++
        end--
    }
};
```
复杂度分析：
时间复杂度：O(n)。 n个元素被反转了总共3次
空间复杂度：O(1)。 没有使用额外的空间