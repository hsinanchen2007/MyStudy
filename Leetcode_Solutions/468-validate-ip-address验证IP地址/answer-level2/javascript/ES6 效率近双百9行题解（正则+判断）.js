### 思路
其实刚一看到题的时候就想到了正则表达式，其中：
- IPv6地址比较好判断：直接判断8组数均为4位以内16进制数即可`/^[0-9a-fA-F]{1,4}$/`；
- 而IPv4的话，如果用正则表达式判断每组数小于256比较繁杂。**这里先用正则判断是否为3位数字以内**`/^0$|^[1-9]\d{0,2}$/`（注意单个0要单独判断，避免出现`01.01.01.01`这样的情况），**再判断数字是否小于256即可**。
### 代码
```JavaScript
var validIPAddress = function(IP) {
    const arr4 = IP.split(".");
    const arr6 = IP.split(":");
    if (arr4.length === 4) {
        if (arr4.every(part => (part.match(/^0$|^([1-9]\d{0,2})$/) && part < 256) )) {
            return "IPv4";
        }
    } else if (arr6.length === 8) {
        if (arr6.every(part => part.match(/^[0-9a-fA-F]{1,4}$/))) {
            return "IPv6";
        }
    }
    return "Neither";
};
```

### 运行效率
![image.png](https://pic.leetcode-cn.com/ca2ef63d0c1bc6ab4e75b0a08abd230451ae7232f628fd6530692c2e11407daf-image.png)

