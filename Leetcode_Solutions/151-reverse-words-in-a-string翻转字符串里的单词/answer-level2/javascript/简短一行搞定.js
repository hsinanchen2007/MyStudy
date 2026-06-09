### 解题思路
![image.png](https://pic.leetcode-cn.com/b06af0667608ac4521c4b3177df72adb096b99844db5993c1f17e969bbdf6971-image.png)
1。空格分割字符串
2。过滤空数据
3。反转数组
4。拼接空格

### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
    //     分割         过滤     
    return s.split(" ").filter(function(res){  
        return res && res.trim(); 
    }).reverse().join(" ");
    //  反转       拼接
};
```