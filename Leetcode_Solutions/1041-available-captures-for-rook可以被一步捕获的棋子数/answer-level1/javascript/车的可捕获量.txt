### 解题思路
1. 开始想到的是用排除法，把无法捕捉到的情况都过滤掉，剩下的就是能捕捉的，太复杂，方向想错了
2. 想到可以通过车的上下左右去找，如果找到就直接换一个方向继续找，因为一个方向最多出现一个，知道把是个方向找完
3. 要注意找的过程中要排除有象挡路的情况，如果挡路了，直接break出当前方向的循环，换一个方向找，直到找到所有能捕捉到的p
4. 代码没有优化，太晚了，后面优化一下，现在还都是面条代码，😓

### 代码

```javascript
/**
 * @param {character[][]} board
 * @return {number}
 */
var numRookCaptures = function(board) {
    //先拿到R， B， p 所有的有效棋子的坐标
    // let index = board.flat().indexOf("R");
    // let RLoc = [8-index%8, Math.floor(index/8)]
    let RLoc = [], BLoc=[], pArr = [];

    // x, y 其中之一相同，并且没有阻挡，并且
    board.forEach((oItem, ind, oArr)=>{
        oItem.forEach((iItem, inx, iArr)=>{
            if(iItem === "R"){
                RLoc.push(inx, ind) 
            }else if(iItem === "B"){
                BLoc.push(`${inx}${ind}`)
            }else if(iItem === "p"){
                pArr.push(`${inx}${ind}`)
            }
        })
    });
    let sum = 0;
    // 按照上右下左的方式去查找，找到立即换方向，碰到B 也立即换方向，是个方向找完即结束
    let top = RLoc[1]-1, right = RLoc[0]+1, btm = RLoc[1]+1, left = RLoc[0]-1

    for(let i=top; i>=0; i--){
        let str = `${RLoc[0]}${i}`
        let nb = BLoc.filter(item=>item === str);
        if(nb.length>0){
            break;
        }
        let newArr = pArr.filter(item=>{
            return item === str
        })
        if(newArr.length > 0){
            sum++
            break;
        }
    }
    for(let i=right; i<=8; i++){
        let str = `${i}${RLoc[1]}`
        let nb = BLoc.filter(item=>item === str);
        if(nb.length>0){
            break;
        }
        let newArr = pArr.filter(item=>{
            return item === str
        })
        if(newArr.length > 0){
            sum++
            break;
        }
    }
    for(let i=btm; i<=8; i++){
        let str = `${RLoc[0]}${i}`
        let nb = BLoc.filter(item=>item === str);
        if(nb.length>0){
            break;
        }
        let newArr = pArr.filter(item=>{
            return item === str
        })
        if(newArr.length > 0){
            sum++
            break;
        }
    }
    for(let i=left; i>=0; i--){
        let str = `${i}${RLoc[1]}`
        let nb = BLoc.filter(item=>item === str);
        if(nb.length>0){
            break;
        }
        let newArr = pArr.filter(item=>{
            return item === str
        })
        if(newArr.length > 0){
            sum++
            break;
        }
    }

    return sum;
};
```