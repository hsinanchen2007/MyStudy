### 解题思路
自己写一个由大到小的有序队列queue，队列里0的位置一直是最大的元素，里面有3个方法：
- push（val）：先将队列里面小于val的数都删掉，然后将val插入到队列；
- pop（val）：用于删除过时的最大值（比如你在找3,4,5三个位置的最大值，但是2位置的最大值还在队列里面，而且比它们都大，但是它已经过时了，要把它删掉，不能影响后续的比较），如果最大值没有过时那么它不会删除任何值
- max（）：返回队列的第一个元素，也就是最大值

然后是一遍for循环，其实下面可以用一个for循环的，但是里面每次都要比较是不是前几元素（因为前几个元素和右面的元素操作不同），看似我写的是两个for循环，但实质上是一个，时间复杂度为O(n)。

跟着思路再看代码就很好理解了

其实这道题我看了很多题解，有一个地方总是不明白，最后加上pop（val）这个方法一切就说得通了

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var maxSlidingWindow = function(nums, k) {
    class Queue {
        constructor() {
            this.queue = [];
        }
        push(val) {
            while(this.queue.length && this.queue[this.queue.length - 1] < val) {
                this.queue.pop();
            }
            this.queue.push(val);
        }
        pop(val) {
            if(this.queue[0] === val) this.queue.shift();
        }
        max() {
            return this.queue[0];
        }
    }

    let len = nums.length;
    let queue = new Queue();
    let res = [];
    if(k === 0) return [];
    for(let i = 0; i < k - 1; i ++) {
        queue.push(nums[i]);
    }
    for(let i = k - 1; i < len; i ++) {
        queue.push(nums[i]);
        res.push(queue.max());
        queue.pop(nums[i - k + 1]);
    }
    return res;
};
```