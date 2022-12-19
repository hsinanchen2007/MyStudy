

![IM截图20191025142511.jpg](https://pic.leetcode-cn.com/161f19a617f0bcb26068f11ef90467ce4af46daafd55640c46d810cfc9c592bb-IM%E6%88%AA%E5%9B%BE20191025142511.jpg)



解题思路：
    1。从左往右找，找到开标签-- 添加到result暂存；
    2.找到闭合标签--判断前一个是不是对应的开标签：
        是：删掉前一个开标签，继续向右找
        否：不是正确格式 返回false
    3.结束后，result长度是0则为正确格式




```
var isValid = function(s) {
        const length = s.length;
        if(length == 0)return true;
        if(length%2 == 1) return false
        let tmp = {
            ')':'(',
            ']':'[',
            '}':'{',
        }
        
        let tmpKeys = Object.keys(tmp),
            tmpValues = Object.values(tmp);
        let arr = [];
        arr.push(s[0])

        let i = 0;
        while (++i < s.length) {
            let cur = s[i]
            if(tmpValues.includes(cur)) {
                arr.push(s[i])
            }else if(tmpKeys.includes(cur)) {
                if(arr.length == 0 || tmp[cur] !== arr[arr.length-1]) {
                    return false
                }else {
                    arr.pop()
                }
            }
        }
        return arr.length === 0
};
```

