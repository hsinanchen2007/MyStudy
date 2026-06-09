### 解题思路
此处撰写解题思路

### 代码

```javascript
var luckyNumbers  = function(matrix) {
        let arrIndex = [] //3,3,3,1
        let maxH = []
        let result = []
        for(let i=0,l=matrix.length;i<l;i++){
            arrIndex.push(matrix[i].indexOf(Math.min(...matrix[i])))
            maxH.push(Math.min(...matrix[i]))
        }
        console.log(arrIndex)
        for(let i=0,l=matrix[0].length;i<l;i++) {
            let maxL = []
            for(let a=0,b=matrix.length;a<b;a++) {
                if(arrIndex.includes(i)){
                    maxL.push(matrix[a][i])
                }
            }
            if(maxL.length > 0){
                let maxValue = Math.max(...maxL)
                let maxValueH = maxL.indexOf(maxValue)
                if(matrix[maxValueH][i] == Math.min(...matrix[maxValueH])){
                    result = [matrix[maxValueH][i]]
                    break;
                }
            }else{
                result = [];
            }
        }
        return result
    };
```