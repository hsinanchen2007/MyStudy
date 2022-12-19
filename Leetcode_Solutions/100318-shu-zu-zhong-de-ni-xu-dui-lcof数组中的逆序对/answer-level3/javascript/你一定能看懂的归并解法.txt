### 解题思路

首先贴一张归并排序的动图：
![img](https://pic.leetcode-cn.com/066bc0ae3f1c0cf4524eed4fc1efe1e4fb51b5c69a90009c7a3cd422216b5ef9-file_1584437845064)

这个题解假设你已经明白归并排序的原理。

就以arr = [7,5,6,4]这个例子来讲解为什么一遍归并排序就看可以解决逆序对的问题。

按照归并排序的思路，会将arr分解为arrL = [7,5],arrR = [6,4];

继续分解为arrLL = [7], arrLR = [5]; arrRL = [6], arrRR = [4];

自此分解完成。

接下来合并：

假设i为arrLL的数组下标，j为arrLR的数组下标, index为新数组res的下标，初始值都为0

首先arrLL与arrLR合并，因为arrLL[i] > arrLR[j](7>5)，

  所以可以说明arrLL中7及其之后的所有数字都大于arrLR中的5，

  也就是说7及其之后的所有元素都可以与5组成逆序对，

  所以此时7及其之后的所有元素个数（leftLen - i）即我们要的逆序对数，需要添加到结果sum中。即sum += leftLen - 1

  （这也就是此算法高效的地方，一次可以查找到好多次的逆序对数，而且不会重复）

合并之后为arrL=[5,7].

根据上述方法将arrRL和arrRR合并为arrR=[4,6];

现在将arrL和arrR合并为arr：

5 > 4，说明5及其之后的所有元素都能与4组成逆序对；所以sum += （leftLen - 1）；

5 < 6，正常排序，不做处理

7 > 6，说明7及其之后的所有元素都能与6组成逆序对；所以sum += （leftLen - 1）；

7，正常排序，不作处理

最后sum就是所有逆序对的总个数！

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var reversePairs = function(nums) {
    // 归并排序
    let sum = 0;
    mergeSort(nums);
    return sum;

    function mergeSort (nums) {
        if(nums.length < 2) return nums;
        const mid = parseInt(nums.length / 2);
        let left = nums.slice(0,mid);
        let right = nums.slice(mid);
        return merge(mergeSort(left), mergeSort(right));
    }

    function merge(left, right) {
        let res = [];
        let leftLen = left.length;
        let rightLen = right.length;
        let len = leftLen + rightLen;
        for(let index = 0, i = 0, j = 0; index < len; index ++) {
            if(i >= leftLen) res[index] = right[j ++];
            else if (j >= rightLen) res[index] = left[i ++];
            else if (left[i] <= right[j]) res[index] = left[i ++];
            else {
                res[index] = right[j ++];
                sum += leftLen - i;//在归并排序中唯一加的一行代码
            }
        }
        return res;
    }
};
```