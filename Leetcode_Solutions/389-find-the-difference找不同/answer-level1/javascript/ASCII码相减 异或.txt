### 解题思路
1、分别将两个字符串每个字符的ASCII码相加，然后结果相减再转为字符
![111.png](https://pic.leetcode-cn.com/08635a52881315f5d08345dce82f9bd564b3afe58c4e318da9743c442acc0c4f-111.png)
2、异或   a^a = 0    a^0 = a   每个字符都异或一遍，就找到那个没有配对的字符了
3、排序  两个字符串分别排序，然后同时遍历，返回t中第一个不同的字符
4、计数   利用map计数，在s中出现+1，在t中出现-1，最后返回计数为-1的那个字符
   遍历t时找不到字符可提前返回

### 代码

```javascript
/**
 * @param {string} s
 * @param {string} t
 * @return {character}
 */
//相减
var findTheDifference = function(s, t) {
    return String.fromCharCode(t.split('').reduce((acc,item) => acc+item.charCodeAt() ,0) - s.split('').reduce((acc,item) => acc+item.charCodeAt() ,0))
};
```
```javascript
//异或
var findTheDifference = function(s, t) {
    return String.fromCharCode((s+t).split('').reduce((acc,item) => acc ^ item.charCodeAt() ,0))
};
```
```javascript
//排序
var findTheDifference = function(s, t) {
    const arr_s = s.split('').sort(),
    arr_t = t.split('').sort();
    for(let i = 0;i<arr_s.length;i++){
        if(arr_s[i] !== arr_t[i]){
            return arr_t[i]
        }
    }
    return arr_t[arr_t.length-1]
};

```
```javascript
//计数
var findTheDifference = function(s, t) {
    const arr_s = s.split('').sort(),
    arr_t = t.split('').sort();
    for(let i = 0;i<arr_s.length;i++){
        if(arr_s[i] !== arr_t[i]){
            return arr_t[i]
        }
    }
    return arr_t[arr_t.length-1]
};
```