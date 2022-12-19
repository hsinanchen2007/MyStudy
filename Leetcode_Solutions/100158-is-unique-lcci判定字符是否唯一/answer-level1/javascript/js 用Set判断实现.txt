乍一看，按理来说for循环，查找重复元素，标志位判断即可。

后来又想到用es6的新特性，将字符串转化为数组后，用set方法来去重。然后判断老的数组长度和去重后的数组长度，相等则无重复的，不等则说明里面有重复的。提交后的效果也是很可喜的。

提交结果：

![微信图片_20200309164203.png](https://pic.leetcode-cn.com/5e4d361fac031c1a0a4dd3433ea180c3a4d8602b3678e6153360101f33cc1eff-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200309164203.png)

看下面代码
```js
 var isUnique = function(astr) {
    const initialList = astr.split('');
    const initialLen = initialList.length;
    const resultList = [...new Set(initialList)];
    const resultLen = resultList.length;
    return initialLen === resultLen;
};

const result =  isUnique('leetcode')
```

即搞定啦~
