模拟一个人按照螺旋路径前进，前进到边界时转向，同时收缩这一侧边界，直到答案数组长度等于矩阵大小
```
/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var spiralOrder = function(matrix) {
    if(matrix.length === 0){
        return []
    }
    let border = {
        top:1,
        left:0,
        right:matrix[0].length -1,
        bottom:matrix.length - 1
    }
    let sequence = ['right', 'bottom', 'left', 'top'];
    let x = 0, y = -1;
    
    let move = {
        top:()=>x--,
        left:()=>y--,
        right:()=>y++,
        bottom:()=>x++
    }
    
    let canMove = (direction)=>{
        switch(direction){
            case 'top':{
                return x > border.top
            }
            case 'left':
                return y > border.left
            case 'right':
                return y < border.right
            case 'bottom':
                return x < border.bottom
        }
    }
    
    let changeBorder = (direction)=>{
         switch(direction){
            case 'top':{
                return border.top ++
            }
            case 'left':
                return border.left ++
            case 'right':
                return border.right --
            case 'bottom':
                return border.bottom --
        }
    }
    let total = matrix.length * matrix[0].length;
    let ans = [];
    outer: for(let i = 0;  ; i++){
        let direction = sequence[ i % 4];
        while(canMove(direction)){
            move[direction]();
            ans.push(matrix[x][y]);
            if(ans.length === total){
                break outer;
            }
        }
        changeBorder(direction)
    }
    return ans
    
    
};
```
