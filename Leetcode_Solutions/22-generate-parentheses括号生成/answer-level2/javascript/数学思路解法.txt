### 解题思路
数学思路 "(" 做 1 ")" 做 0 显然的区间就是101010 - 111000 然后找规律解决就行

### 代码

```javascript
/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function(n) {
    var start = Math.pow(2,2*n-1);
    var end = Math.pow(2,2*n);

    var arr = new Array();
    var result = new Array();

    for(var i=end-1;i>=start;i--){
        var temp = i.toString(2);
        if(temp.replace(/0/g,"").length==n)
            arr.push(temp);
    }

    for(var i=0;i<arr.length;i++){
        var flag = true;
        var num = 0;
        for(var j=0;j<arr[i].length;j++){
            if(arr[i][j]==1 && j>2*num++){
                flag = false;
                break;
            }
        }
        if(flag)
            result.push(arr[i]);
    }

    for(var i=0;i<result.length;i++){
        result[i] = result[i].replace(/1/g,"(").replace(/0/g,")");
    }

    return result;
};
```