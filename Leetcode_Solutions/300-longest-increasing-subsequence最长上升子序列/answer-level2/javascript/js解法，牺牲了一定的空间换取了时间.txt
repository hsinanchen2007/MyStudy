**一种新的思路，时间复杂度应该是小于O(n2)的，不太会算这个思路的平均时间复杂度，如果有大佬看到可以帮忙算一下哈。**
分析了一下题目发现最长的升序数组段不一定会是连续的，想要节省时间，**所以牺牲了一定的空间，用来解题**，大致思路如下：
1.先将原数组处理成一个个连续递减的子数组组合而成的二维数组；
2.要想让该升序数组尽可能长，就要尽可能让结果数组中的每一个元素的值尽可能的小，因此按以下约定对该二维数组进行遍历：
    2.1 该元素是二维数组的第一个元素，取该元素的最小值（即该元素数组最后一个值）作为可能满足条件的数组；
    2.2 从二维数组的第二个元素开始，若该元素数组的最小值比可能满足条件的数组的最后一个元素的值大，则直接将该元素push入可能的结果数组，否则，则将满足升序条件的最小数组元素推入结果数组，并新增一个以该元素数组最小值开始的数组作为最终符合条件的数组的备选数组。
3.获取到又一个二维数组，找到其中数组长度最长的一维数组即是题解的最长长度。

以下为代码，其中第二个reduce方法内的逻辑应该还可以优化，可以减少结果数组的长度以优化性能。

```
/**
 * @param {number[]} nums
 * @return {number}
 */
var lengthOfLIS = function(nums) {
    if (!nums.length) {
        return 0;
    }
    return Math.max(...nums.reduce((prevVal, currVal, index) => {
        const lastArr = prevVal[prevVal.length - 1];
        if (!lastArr.length) {
            lastArr.push(currVal);
        } else {
            if (currVal < lastArr[lastArr.length - 1]) {
                lastArr.push(currVal);
            } else if (currVal > lastArr[lastArr.length - 1]) {
                prevVal.push([currVal]);
            }
        }
        return prevVal;
    }, [[]]).reduce((prevVal, currVal, index) => {
        const lastValOfCurrVal = currVal[currVal.length - 1];
        if (index === 0) {
            prevVal.push([lastValOfCurrVal]);
            return prevVal;
        }
        let needPushNewArr = false;
        prevVal.map(item => {
            const lastMinVal = item[item.length - 1];
            if (lastMinVal > currVal[0]) {
                needPushNewArr = true;
            } else if (lastMinVal < lastValOfCurrVal) {
                item.push(lastValOfCurrVal);
            } else {
                needPushNewArr = true;
                for (let i = currVal.length - 1; i >= 0; i--) {
                    if (currVal[i] > lastMinVal) {
                        item.push(currVal[i]);
                        break;
                    }
                }
            }
        });
        if (needPushNewArr) {
            prevVal.push([lastValOfCurrVal]);
        }
        return prevVal;
    }, []).map(item => item.length));
};
```
