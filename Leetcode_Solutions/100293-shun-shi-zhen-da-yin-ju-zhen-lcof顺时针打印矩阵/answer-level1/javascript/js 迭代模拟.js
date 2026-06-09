### 解题思路
一圈一圈的旋转模拟

### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var spiralOrder = function(matrix) {
    if(matrix.length===0)return [];
    let res=[];
    let up=1;
    let down=matrix.length-1;
    let left=0;
    let right=matrix[0].length-1;
    let i=0,j=0;
    while(up<=down || left<=right){
        //左往右
        if(left>right)break;
        while(j<=right){
            res.push(matrix[i][j])
            j++;
        }
        right--;
        j--;i++;

        if(up>down )break;

        //上往下
        while(i<=down){
            res.push(matrix[i][j]);
            i++;
        }
        down--;
        i--;j--;
        if(left>right)break;
        //右往左
        while(j>=left){
            res.push(matrix[i][j]);
            j--;
        }
        left++;
        j++;i--;
        if(up>down )break;

        //下往上
        while(i>=up){
             res.push(matrix[i][j]);
             i--;
        }
        up++;
        i++;j++
    }
    return res;

};
```