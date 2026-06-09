### 解题思路
方法一、直接利用reverse函数
![屏幕快照 2020-03-12 上午10.10.25.png](https://pic.leetcode-cn.com/69bde939f1f09b8d58c21263b264b4c2482f8c978802e48fd8228824c5aeae9c-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-03-12%20%E4%B8%8A%E5%8D%8810.10.25.png)
### 代码

```javascript
/**
 * @param {character[]} s
 * @return {void} Do not return anything, modify s in-place instead.
 */
var reverseString = function(s) {
    s.reverse();
};
```
方法二、双指针
```
var reverseString = function(s) {
    var first=0,last=s.length-1;
    var temp='';
    while(first < last){
        temp = s[first];
        s[first]=s[last];
        s[last]=temp;
        first++;
        last--;
    }
};
```
