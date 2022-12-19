### 解题思路
![image.png](https://pic.leetcode-cn.com/95e27a211c0c05e35894a8a4e2bd8c2859946e8e323eb205f9bcf159dd75f081-image.png)
- 将 char 转化为数组进行判断，对每一个words里面的项也转换成数组 通过split('')
- 通过 tmp 作为判断条件 如果tmp < 0 则判断该 words 的不在 char之中，如果在，则加入num 的长度

### 代码

```javascript
/**
 * @param {string[]} words
 * @param {string} chars
 * @return {number}
 */
 var countCharacters = function(words, chars) {
    let num = 0
    for(let i = 0, len = words.length; i < len; i++){
         let length = words[i].split('').length
         let tmp = chars.split('')
         for(let j = 0; j < length; j++){
             let index = tmp.indexOf(words[i][j])
            if(index > -1){
                tmp.splice(index,1)
            }else{
                tmp = -1
                break;
            }
         }
        if(tmp.length >= 0){
            num += length
        }
    }
    return num
};
```