![image.png](https://pic.leetcode-cn.com/510e5b78ba23ac8f24a12d9618f2f48d35b0ac556d77b74445a91e65f1c58d4a-image.png)

1，先判断空字符串的情况，直接返回。
2，再根据数组的split方法，分割成数组，
3，数组长度为1则说明没有当前字符串，返回-1 ，
4，其他情况直接返回数组第一个字符串的长度。

```
var strStr = function(haystack, needle) {
    if(needle === '') return 0
    const arr = haystack.split(needle)
    if(arr.length==1) return -1
    return arr[0].length
};
```


