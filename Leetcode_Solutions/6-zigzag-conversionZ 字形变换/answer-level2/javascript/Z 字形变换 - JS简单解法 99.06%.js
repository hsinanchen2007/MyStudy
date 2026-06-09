### 解题思路
![image.png](https://pic.leetcode-cn.com/0409d2a62c441efef3c89438af0e7cc6711680e609245f7b00e0b8f81cf505f1-image.png)
1. 拼接Z字形字符串： 从左到右、从上往下 按顺序拼接。
2. 将字符串按Z字形分割。

```javascript
/**
 *  s = "LEETCODEISHIRING",  numRows = 4
 *  n = numRows + ( numRows - 2 ) => 4+(4-2)=6
 * 	0L     6D       12R    	i % 6 = 0  
 * 	1E  5O 7E   11I 13I	   	i % 6 = ( 1  ||  5 )     =>  n - i % 6 = 1 
 * 	2E 4C  8I 10H   14N		i % 6 = ( 2  ||  4 )     =>  n - i % 6 = 2 
 * 	3T     9S       15G		i % 6 = 3  
 */
```
### 代码

```javascript
/**
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */

/**
 * 解法二：
 *  1. 优化暴力破解 
 *      空间复杂度：O(n)
 *      时间复杂度：O(n)
 */
var convert = function(s, numRows) {
    if( numRows < 2 ) return s
    let arr = [], n = numRows + ( numRows - 2 ) 
    for( let i=0; i<s.length; i++){
        const r = i % n
        const index = r < numRows ? r : n - r 
        arr[index] = arr[index] ? arr[index] + s[i] : s[i]
    }
    return arr.join('')
}
```

```javascript
/**
 * 解法一：暴力破解
 *      1. 根据行数得到一个二维数组。
 *      2. 根据规律 如下图，得到数组下标push，最后转化为字符串。
 * 
 *  s = "LEETCODEISHIRING",  numRows = 4
 *  n = numRows + ( numRows - 2 ) => 4+(4-2)=6
 * 	0L     6D       12R    	i % 6 = 0  
 * 	1E  5O 7E   11I 13I	   	i % 6 = ( 1  ||  5 )     =>  n - i % 6 = 1 
 * 	2E 4C  8I 10H   14N		i % 6 = ( 2  ||  4 )     =>  n - i % 6 = 2 
 * 	3T     9S       15G		i % 6 = 3  
 */
var convert = function(s, numRows) {
    if( numRows < 2 ) return s
    let arr = []
    for(let i=0; i<numRows; i++){
        arr.push([])
    }
    const n = numRows + ( numRows - 2 ) 
    for( let i=0; i <s.length; i++ ){
        const r = i % n
        arr[ r < numRows ? r : n - r  ].push(s[i])
    }
    return arr.map(item=>item.join('')).join('')
};
```