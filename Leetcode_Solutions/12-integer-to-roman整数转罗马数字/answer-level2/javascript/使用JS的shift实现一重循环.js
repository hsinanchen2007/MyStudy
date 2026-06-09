### 解题思路
借鉴了评论里的代码，创建了两个对应的数组。
让这个数每次只跟数组的第一项进行比较，如果不够格，就把相应的下标后移。
或是使用JS中提供的shift方法，弹出最前面的数据。
代码感觉比较好理解，这可能就是高级语言的优势吧![逃]
### 代码

```javascript
/**
 * @param {number} num
 * @return {string}
 */
var intToRoman = function(num) {
    let nums=[1000,900,500,400,100,90,50,40,10,9,5,4,1],
        chars=['M','CM','D','CD','C','XC','L','XL','X','IX','V','IV','I'];
    let result='';
    while(num){
        if(num>=nums[0]){
            result+=chars[0];
            num-=nums[0];
        }else{
            nums.shift();
            chars.shift();
        }
    }
    return result;
};
```