如果你不懂为什么要定义两个数，可以进来看看。
首先理解：如果一个数字出现的频率超过总数的1/2,那么出现次数count++,不是此数count--,最后count肯定会大于0
其次理解：如果一次数字出现的频率超过总数的1/3，一次扔掉3个数字，最多扔n/3次，如果一个数字超过总数的1/3,最后其count毕竟大于0。
(这里要注意一下：是超过总数的1/3毕竟会被留下，并不是留下的每一个都是超过1/3)

```
var majorityElement = function(nums) {
    let num1 = null, num2 = null;
    let count1 = 0, count2 = 0;
    let length = nums.length;
    for (let num of nums) {
        if (num1 == num) {
            count1++;
        } else if (num2 == num) {
            count2++;
        } else if (count1 == 0) {
            [num1, count1] = [num, 1];
        } else if (count2 == 0) {
            [num2, count2] = [num, 1];
        } else {
            count1--;
            count2--;
        }
    }
    count1 = 0, count2 = 0;
    for (const num of nums) {
        if (num === num1) {
            count1++;
        }
        if (num === num2) {
            count2++;
        }
    }
    let arr = [];
    if (count1 > length / 3) {
        arr.push(num1);
    }
    if (count2 > length / 3) {
        arr.push(num2);
    }
    return arr;
};

```

