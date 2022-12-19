### 解题思路
![image.png](https://pic.leetcode-cn.com/a6ecdcab85acdf8ab52ac66015d431f4bf787fd44d4db22853c3f2be6677ad3f-image.png)

见下方代码注释

### 代码

```javascript
/**
 * @param {number[]} heights
 * @return {number}
 */
function small(arr) {
    let small = arr[0];
    for (let j = 1; j < arr.length; j++) {
        (arr[j] < small) && (small = arr[j]);
    }
    return small;
}

// 暴力法: 两轮遍历O(n2)
// 遍历a, 并向后遍历，找出a-b点的最小值
// 求出面积，找出整个循环最大的面积；
var largestRectangleAreaWithTwoCycle = function(heights) {
    let large = 0;
    for(let i = 0; i < heights.length; i++) {
        let min = heights[i];
        for (let j = i; j < heights.length; j++) {
            heights[j] < min && (min = heights[j]);
            large = Math.max(large, (j + 1 -i) * min);
        }
    }
    return large
};

// 栈顶法,思路：
// 遍历元素，如果下一个元素形成的是升序列，直接加入到栈中，如果下一个元素是降序列，
// 则遍历计算栈中当前元素形成的面积， 以[2,1,5,6,2,3]为例，假如当前已遍历到6，即将遍历到2；
// 则当前栈是[{-1, -1}, {1,1}, {2,5}, {3,6}], 当前最大面积为2，因为即将遍历到2，是一个降序列
// 所以先弹出{3,6}，面积为6,更新，5仍然大于2，弹出{2,5}，（3 + 1 - 2)*5 = 10,更新为10，由于2 > 1是一个升序 
// 所以入栈形成[{-1, -1}, {1,1}, {4,2}]，接着3，也是形成[{-1, -1}, {1,1}, {4,2}，{5,3}] 
// 因为升序不会去计算最大面积，所以在所有元素遍历后，还要去遍历计算栈中的面积；
var largestRectangleArea = function(heights) {
    let large = 0;
    let shift = [{ index: -1, height: -1 }];
    for(let i = 0; i < heights.length; i++) {
        // 队列中最后一个元素为非初始化元素
       while(shift[shift.length - 1].height !== -1 && shift[shift.length - 1].height > heights[i]) {
           const pop = shift.pop();
           large = Math.max(large, pop.height * (i - 1 - shift[shift.length - 1].index) );
       }
       shift.push({ index: i,height: heights[i] });
    }
    const top = shift[shift.length - 1].index;
    // 
    while(shift[shift.length - 1].height !== -1) {
        const pop = shift.pop();
        large = Math.max(large, pop.height * (top - shift[shift.length - 1].index));
    }
    return large
};
```