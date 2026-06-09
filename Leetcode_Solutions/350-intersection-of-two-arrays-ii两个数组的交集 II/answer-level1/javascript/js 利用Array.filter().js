执行用时 :76 ms, 在所有 JavaScript 提交中击败了94.59%的用户
内存消耗 :33.6 MB, 在所有 JavaScript 提交中击败了95.21%的用户

借鉴[1002. 查找常用字符 题解](https://leetcode-cn.com/problems/find-common-characters/solution/js-by-blzbanme/)的解法三。
我发现还有几道题也能按照这个解法三去套

大概的思路：
直接把nums1作为结果数组，然后对这个结果数组进行过滤。
过滤时把nums2中已经查过的值用100（因为数组没有100这个数）或是Infinity代替，保证过滤重复值时不会出现问题。

```javascript
var intersect = function(nums1, nums2) {
    let res = nums1;
    res = res.filter(e => {
        let index = nums2.indexOf(e);
        return index !== -1 ? nums2[index] = 100 : false;  //①
    });
    // console.log(nums1);
    // console.log(nums2);//会发现直接将nums2的数组值给改了，如果不想改，一开始的时候弄一个let temp = nums2即可
    return res;
};
```
①：之前的解题都是把nums2[index]赋值为1的，但那是因为其他题原先是字母，而这题不是，所以我给定了一个相对大一点的值（100）或Infinity。而设成100的用时会比设成Infinity要短