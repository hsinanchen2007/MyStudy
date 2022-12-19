这是我当初笔试看到这道题脑海里第一印象蹦出来的解法，但是由于时间不够没有写完，所以记录一下
```
/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var spiralOrder = function(matrix) {
    let result=[];              //存放结果
    if(matrix.length===0){      //空矩阵情况
        return result;
    }
    let x=0,y=0;                //x为矩阵高，y为矩阵宽
    let width=matrix[0].length,height=matrix.length;    //获得矩阵的宽高
    let circle=Math.ceil(Math.min(width,height)/2);     //获得需要遍历的圈数
    for(let i=0;i<circle;i++){  //遍历
        x=y=i;                  //初始默认从当前圈的第一个元素遍历
        if(width===height&&i===circle-1){   //如果最后一圈只有一个数的情况
            result.push(matrix[x][y]);
            if(y<width-1-i){                //如果最后一圈只有两行两列的情况
                y++;
            }
        }
        while(y<width-1-i){                 //遍历当前圈的上面部分
            result.push(matrix[x][y]);
            y++;
        }
        while(x<height-1-i){                //遍历当前圈的右边部分
            result.push(matrix[x][y]);
            x++;
        }
        while(y>i){                         //遍历当前圈的下面部分
            result.push(matrix[x][y]);
            if(x===i){                      //如果最后一圈只有一行的情况
                break;
            }
            y--;
        }
        while(x>i){                         //遍历当前圈的左边部分
            result.push(matrix[x][y]);
            if(y===width-1-i){              //如果最后一圈只有一列的情况
                break;
            }
            x--;
        }
    }
    return result;
};
```

