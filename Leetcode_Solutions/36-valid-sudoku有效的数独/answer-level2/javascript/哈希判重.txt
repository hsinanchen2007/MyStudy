### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {character[][]} board
 * @return {boolean}
 */
var isValidSudoku = function(board) {
    var rows = {};
    var columns = {};
    var boxs = {};

    for (var i = 0; i < board.length; i++) {
        var arr = board[i];
        for (var j = 0; j < arr.length; j++) {
            var num = arr[j];
            var index =  parseInt(i/3) * 3 + parseInt(j/3);
            
            if (num === '.') continue;
            if(rows[i+'-'+num] || columns[j+'-'+num] || boxs[index+'-'+num]){
                return false;
            }
            // 以各自方向 + 不能出现重复的数字 组成唯一键值，若出现第二次，即为重复
            rows[i+'-'+num] = true;
            columns[j+'-'+num] = true;
            boxs[index+'-'+num] = true;
        }
    }

    return true;
};
```