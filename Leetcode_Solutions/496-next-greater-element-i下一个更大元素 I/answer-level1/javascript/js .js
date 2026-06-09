思路：
循环nums1
找到nums1循环中当前值cur在nums2中的位置（t）
从t处开始循环nums2
    如果有比cur大的就返回
    否则等nums2循环完后返回-1

```
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var nextGreaterElement = function (nums1, nums2) {
    return nums1.map(cur => {
        let t = nums2.indexOf(cur) //获取nums1中的当前值（cur）在nums2中位置
        for (t, len = nums2.length; t < len; t++){ //循环nums2，从t位置开始
            if (nums2[t] > cur){ //如果t位置 右侧有比cur大的值  就返回；如果此for循环完之后没有发现比cur更大的值，则返回-1
                return nums2[t]
            }
        }
        return -1
    })
};
```

谁给来个复杂度分析：
