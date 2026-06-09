### 解题思路
合并成一个字符串并且反转
1、split('-')：分割成字符串数组，但是每个元素会有多个字符；
2、join('')：合并成一个字符串；
3、split('')：分割成数组，每个元素中只有一个字符；
4、reverse()：最后反转过来，从后往前处理。

### 代码

```javascript
/**
 * @param {string} S
 * @param {number} K
 * @return {string}
 */
var licenseKeyFormatting = function(S, K) {
    let arr = S.toUpperCase().split('-').join('').split('').reverse();
    let targetArr = [];
    let i = 0;
    let tmp = '';
    while(i<arr.length){
        // 此处要注意顺序，若是tmp+=arr[i]的话则顺序会不对
        tmp=arr[i]+tmp;
        if(tmp.length==K){
            console.log(tmp)
            targetArr.unshift(tmp);
            tmp='';
        }
        if(i==arr.length-1 && tmp.length){ // 是否处理到了最后一个并且tmp中还有字符
            targetArr.unshift(tmp);
        }
        i++;
    }
    return targetArr.join('-')
};
```