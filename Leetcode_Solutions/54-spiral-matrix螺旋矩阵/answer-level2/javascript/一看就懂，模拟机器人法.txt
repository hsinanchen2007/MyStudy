### 解题思路
用面向对象的思想，假设有个机器人在(0,0)位置，向右一直走，走到边界向下走，走到下面的边界向左走，以此类推，边界一直在缩小
用四个数字表示边界
```
let top = 0,left = 0, right = matrix[0].length-1, bottom = matrix.length - 1;
```
根据规律我们发现，机器人一直按着右，下，左，上的固定转向方式。
所以设定一个dire值，用来表示当前的行进方向，每行进结束加1，同时在控制逻辑里用dire%4的方式来控制行进逻辑。
isEnd表示是否已经无路可走，i,j表示当前位置，result表示结果集。
move就是前进方法，他判断dire来决定向哪边走，每次走完就缩小边界，同时转向。

时间复杂度: O(n)
空间复杂度: O(1)

### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var spiralOrder = function(matrix) {
    // 右 下 左 上 对应0 1 2 3
    // 四个指针 对应上下左右的边界
    if(matrix.length === 0) return [];
    let dire = 0;
    let top = 0,left = 0, right = matrix[0].length-1, bottom = matrix.length - 1;
    let isEnd = false;
    let i = 0,j=0;
    let result = [];
    while(!isEnd){
        move()
    }
    function move(){
        switch(dire%4){
            case 0: moveRight();turnDown();break;
            case 1: moveDown();turnLeft();break;
            case 2: moveLeft();turnUp();break;
            case 3: moveUp();turnRight();break;
        }
    }
    function moveRight(){
        while(j <= right) {
            result.push(matrix[i][j]);
            j++;
        }
        j--;
        top ++;
    }
    function moveDown(){
        while(i <= bottom) {
            result.push(matrix[i][j]);
            i++;
        }
        i--;
        right --;
    }
    function moveLeft(){
        while(j >= left) {
            result.push(matrix[i][j]);
            j--;
        }
        j++;
        bottom --;
    }
    function moveUp(){
        while(i >= top) {
            result.push(matrix[i][j]);
            i--;
        }
        i++;
        left ++;
    }
    function turnDown(){
        dire++;
        i++;
        if(i > bottom){
            isEnd = true;
        }
    }
    function turnLeft(){
        dire++;
        j--;
        if(j < left){
            isEnd = true;
        }
    }
    function turnUp(){
        dire++;
        i--;
        if(i < top){
            isEnd = true;
        }
    }
    function turnRight(){
        dire++;
        j++;
        if(j > right){
            isEnd = true;
        }
    }
    return result;
};
```