### 解题思路
![image.png](https://pic.leetcode-cn.com/90425a965cd1cb46d36bec8c3760643f3407be69bd1b6b17cef28632f9b3520c-image.png)

    我最开始的想法是建一个二维数组来存，就是一行是一个数组，然后可以很直观的存下ZZZ...，后来我看了大佬的思路，眼前一亮，其实没必要键二维数组，一维数组就够用，让数组的长度为行数，其实我们只要把每个元素应该在哪一行算好就可以了，然后从头到尾开始遍历大字符串，就可以‘对号入座’了，最后把数组转变为字符串即可！

### 代码

```javascript
/**
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */
var convert = function(s, numRows) {
    if(numRows == 0) return '';
    if(numRows == 1) return s;
    let array = new Array(numRows).fill('');
    let sLen = s.length;
    let x = 0;
    let direction = false;//表示向上走
    for(let i = 0; i < sLen; i ++) {
        array[x] += s[i];
        if(x == numRows - 1 || x == 0) 
            direction = !direction;
        if(direction)//向下走
            x ++;
        else//向上走
            x --;
    }
    return array.join('');
};
```