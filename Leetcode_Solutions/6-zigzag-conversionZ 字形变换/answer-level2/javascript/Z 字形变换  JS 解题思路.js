### 解题思路
numRows 确定了一共有多少行，难点就是确定列数。
以 示例2 为例：

找规律：
    - 第0列是满的
    - 第1列有空缺
    - 第2列有空缺
    - 第3列是满的
    - 第4列有空缺
    - 第5列有空缺
    - 第6列是满的
    - ...
    
依次类推不难发现规律 第 i 列是满的条件为  i % (numRows-1)  === 0 

接下来查找空缺的规律：
    - 第1列 2行 有数据
    - 第2列 1行 有数据
    - 第4列 2行 有数据
    - 第5列 1行有数据
    - ...

依次类推不难发现规律 空缺列有数据的满足条件为  numRows- 1 - i % (numRows-1) 有数据

根据上述规律 ， 将字符串存储到二维数组中，最后再按照规律  便利二维数组将不为空的数据存储  即可得到数据

### 代码

```javascript
/**
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */
var convert = function(s, numRows) {
    if(numRows == 0){
        return s;
    }
    if(!s){
        return s;
    }
    var list = [[]];
    var num = 0;
    var length = s.length;
    var i = 0 ;
    var result  = "";
    while (length > num){
        var row = 0;
        if(numRows > 1){
            row = i %(numRows - 1) 
        }
        if(!list[i]){
            list[i] = [];
        }

        if(row === 0 ){
        
        for(let j = 0; j < numRows; j ++){
            list[i][j] = s[num];
            num = num +1 ;
        }
        }else{
            list[i][numRows- 1 - row] = s[num];
            num = num + 1;
        }
        i = i +1; 
    }
    var len = list.length;
    var rows = list[0].length;
    var n = 0;
    while( n < rows){
        for(var z = 0; z < len; z ++){
            var temp = list[z];
            if(temp [n]){
                result += temp[n];
            }
        }
        n++;
    }
    return result;
    
};
```