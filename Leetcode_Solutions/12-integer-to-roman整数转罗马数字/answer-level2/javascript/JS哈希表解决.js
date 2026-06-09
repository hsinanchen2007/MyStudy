### 解题思路
通过循环哈希表，`从大到小`依次判断当前数是否`大于等于`哈希表的key

### JavaScript的坑
1、forin循环遍历对象为无序，通过`Object.keys(hashMap).reverse()`曲线救国
2、必须通过循环才能批量处理字符串，看都python居然可以通过"M"*2输出"MM"，泪流满面

### 代码

```javascript
/**
 * @param {number} num
 * @return {string}
 */
var intToRoman = function(num) {
    var hashMap = {
        1000: 'M',
        900: 'CM',
        500: 'D',
        400: 'CD',
        100: 'C',
        90: 'XC',
        50: 'L',
        40: 'XL',
        10: 'X',
        9: 'IX',
        5: 'V',
        4: 'IV',
        1: 'I'
    };
    var s = '';
    for(var key of Object.keys(hashMap).reverse()) {
        if(num >= key) {
            var count = parseInt(num / key);
            for(var i = 0; i < count; i++)
                s = s.concat(hashMap[key]);
            num -= key * count;
        }
    }
    return s;
};
```