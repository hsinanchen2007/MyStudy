![image.png](https://pic.leetcode-cn.com/c05c7b1207a165fc9f9eef750b7ed300f7319bc23bb0f013d183a613c5e2138b-image.png)

字符串分割,然后依次比较
~~a 可以把数字类型的字符串转换成数字类型，如果是undefined，会转换成0


```javascript
var compareVersion = function(version1, version2) {
    let v1 = version1.split('.');
    let v2 = version2.split('.');

    let len =Math.max(v1.length,v2.length);
    for(let i = 0;i<len;i++){
        if(~~v1[i]>~~v2[i]){
            return 1;
        }else if(~~v1[i] < ~~v2[i]){
            return -1;
        }
    }
    return 0;
};
```
