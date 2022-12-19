```
var queensAttacktheKing = function(queens, king) {
  //从king出发
  let dx=[0,0,1,-1,1,-1,1,-1]//8个方向
  let dy=[1,-1,0,0,1,-1,-1,1]
  let res=[]
  for(let i=0;i<dx.length;i++){
      let x=king[0]
      let y=king[1]
      while(true){
          x+=dx[i]
          y+=dy[i]
          if(x<0||x>=8||y<0||y>=8)break
          let isOk=false
          for(let j=0;j<queens.length;j++){
              if(queens[j][0]===x&&queens[j][1]===y){
                  isOk=true
                  break
              }
          }
          if(isOk){
              res.push([x,y])
              break
          }
      }
  }
    return res
};
```
