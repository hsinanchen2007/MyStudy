### 解题思路
![image.png](https://pic.leetcode-cn.com/80f0b7a3ff39c03584c9cac3a3c4e894d47ef8801063219ae498031972f9852d-image.png)
### 代码

```javascript
/**
 * @param {number[]} height
 * @return {number}
 */
/**
 *  双指针法：
 *  开始前明白一个道理：
 *    雨水能接多少，由木桶原理而知，是由两侧最大两个值较小值决定；
 *    只要右侧最大值是大于当前左侧最大值时，那么从左侧累计雨水就是安全的；
 *    同理，只要左侧最大值是大于当前右侧最大值时，那么从右侧累计雨水就是安全的；
 * */

 function DoublePoint(height) {
    let left = 0;
    let right = height.length - 1;

    let left_max = height[left];
    let right_max = height[right];
    let res = 0;
    // 遍历结束条件就是左右指针相交；
    while (left < right) {
        // 从左侧累计雨水
        if (left_max < right_max) {
            left++;
            let target = height[left];
            // 只要小于最大值，就可以继续累计雨水，否则，需要只能更新最大值
            if (target <= left_max) {
                res += left_max - target;
            } else {
                left_max = target;
            }
        } else {
            right--;
            let target = height[right];
            // 同上
            if (target <= right_max) {
                res += right_max - target;
            } else {
                right_max = target;
            }
        }
    }

    return res;
};

/**
 *  单调递减栈：以[4,2,3,2,1,1,2] 为例
 *  道理一样: 雨水能接多少，由木桶原理而知，是由两侧最大两个值较小值决定；
 *  栈中保持递减，如果即将入栈的值大于栈顶，则调整当前栈； 
 *  eg：当前栈 [4, 2]，3即将入栈，那么调整栈，2出栈，当前能接的雨水，应该只左右两侧较小值3决定，宽度为：1
 *  调整后，继续入栈为[4,3,2,1,1], 2 即将入栈，1先出栈，左右两侧较小值为1，继续出栈，较小值为2；
 *  注意这里的宽度计算，宽度应该是**当前出栈值得索引上一个与即将入栈的值索引的差值**；
 * */
var trap = function stackDecrese(height) {
    const stack = [];
    let res = 0;
    let top = { index: 0, value: height[0] };
    // 先入栈一个再说
    stack.push({ index: 0, value: height[0] });

    for (let i = 1; i < height.length; i++) {
        let target = height[i];
        // 如果反转，不是单调递减，则迭代求当前能接的雨水；
        while(top && target > top.value) {
            top = stack.pop();
            if (!top) {
                break;
            }
            // 取上一个栈值
            const next = stack[stack.length - 1];
            if (next) {
              // 安全边界，应该是当前轮询值，和上一个值中的较小值
              const min = Math.min(next.value, target);
              // i - 1 指的是，当前要入栈的前一个索引；而不能直接用 top.index代替i - 1;
              // 像轮询到[2, 1, 1]时，即将入栈3，第一个1弹出后，和下一个1，不产生雨水，但2，1时，应该产生的
              // 雨水是3，而不是1；
              res += (min - top.value) * (i - 1 - next.index);
            }
            // 这一步很重要，改变top指向；
            top = next;
        }

        top = { index: i, value: target };
        stack.push(top);
    }

    return res;
};
```