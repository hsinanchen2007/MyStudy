算是暴力破解吧
思路是先获取所有未填入的坐标信息存为一个数组
然后将数组拆分为列和宫，后续可直接在这些数组里判断是否输入正确
然后就是无限递归了。。。
第一次写题解= =有点凌乱。。。
求大神指点下优化的方向
![image.png](https://pic.leetcode-cn.com/93ff8af0e1c1be1de08514a4addff5ca9b98150cd1a3e49ba1bdcf6ec2d98cf0-image.png)

```
/**
 * @param {character[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */


var solveSudoku = function(board) {
    // 数独相关json,行、列、宫
    let verifyJson={
        "row":board,
        "col":[],
        "palace":[],
        "writeCoord":[]
    }
    // 初始化行列宫
    initArr(verifyJson)
    // 开始填入
    verifyWrite(verifyJson)
    return verifyJson.row
};

function verifyWrite(verifyJson,isAllWrite,CoordId=0){
    // 遍历待填入项
    let item=verifyJson.writeCoord[CoordId]
    // 尝试填入
    for(let num=1,len=9;num<=len;num++){
        // 若已得到答案则跳过剩下的循环
        let isOk=false
        //所在行中是否存在当前数字
        isOk=!verifyJson.row[item.x].includes(''+num)?true:false
        //所在列中是否存在当前数字
        isOk=isOk?!verifyJson.col[item.y].includes(''+num)?true:false:false
        //所在宫中是否存在当前数字
        isOk=isOk?!verifyJson.palace[item.palaceId].includes(''+num)?true:false:false
        if(isOk){
            // 存在=>设置行,并根据行对宫,列进行填入
            verifyJson.row[item.x][item.y]=''+num
            // 重置行列宫,便于下次判断
            initArr(verifyJson,false)
            // 是否为最后一个填入的位置，是的话则解答完毕
            if((item.id+1)>=verifyJson.writeCoord.length){return true}
            // 递归,继续填入下一个值
            if(verifyWrite(verifyJson,isAllWrite,item.id+1)){
                // 我也忘了当初为啥写这个、、、、、
                return true
            }
            else{
                // 移除当前填入项之后填入的数
                removeArr(verifyJson,item.id+1)
            }
        }   
    }   
}

function removeArr(verifyJson,writeCoordId){
    // 移除错误填入
    for(let i=writeCoordId,len=verifyJson.writeCoord.length;i<len;i++){
        let coord=verifyJson.writeCoord[i]
        verifyJson.row[coord.x][coord.y]='.'
    }
    initArr(verifyJson,false)
}

var initArr=function(verifyJson,first=true){
    let board=verifyJson.row
    if(!first){verifyJson.col=[];verifyJson.palace=[]}
    board.map((item,index)=>{
        verifyJson.col[index]=[]
        let x=parseInt(index/3)
        item.map((it,id)=>{
            // 设置宫数组
            let y=parseInt(id/3)
            verifyJson.palace[x*3+y]=!!verifyJson.palace[x*3+y]?verifyJson.palace[x*3+y]:[]
            verifyJson.palace[x*3+y].push(it)
            
            //设置未填入的位置坐标
            if(it=='.'&&first){
                let coord={
                    "x":index,
                    "y":id,
                    "palaceId":x*3+y,
                    "id":verifyJson.writeCoord.length
                }
                verifyJson.writeCoord.push(coord)
            }
           
            // 列数组
            verifyJson.col[index].push(board[id][index])
        })
    })
}
```
