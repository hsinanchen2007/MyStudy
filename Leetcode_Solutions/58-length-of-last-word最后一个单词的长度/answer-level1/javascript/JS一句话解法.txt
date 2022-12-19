### 思路
利用JS字符串处理方法，先将字符串头尾空格通过`trim()`去掉（避免`"a "`这样会出错），然后把按空格把字符串分割成数组，取出最后一位返回其长度
### 代码

```JavaScript
var lengthOfLastWord = function(s) {
    return s.trim().split(" ").pop().length;
};
```
### 执行结果

![image.png](https://pic.leetcode-cn.com/6a150ca2c8e47ff1891bce15db2022125c30d8ae4068d4fe1cee0cfcf862cc6c-image.png)
