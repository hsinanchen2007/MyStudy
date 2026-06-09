```
var robot = function(command, obstacles, x, y) {
  let list = command.split('')
  let xc = 0, yc = 0;
  let pathList = [[0,0]]  // 路线坐标
  let obj = {
    '[0,0]': -1
  }
  // 循环获取到第一次路线坐标 
  for(let i = 0; i<list.length;i++){
    if(list[i] === 'R'){
      xc++
    }else{
      yc++
    }
    pathList.push([xc,yc])
    obj[JSON.stringify([xc,yc])] = i
  }
  console.log(pathList)  // [[0,0],[0,1],[1,1],[2,1]]
  // 根据路线坐标判断能否能到达终点 
  // 先用终点x轴坐标值对第一次路线最后一个坐标x轴值取余,得到对应第一次路线的x坐标值,
  // y坐标
  let end = pathList.slice(-1)[0]
  let xl = +end[0]
  let yl = +end[1]
  let terminus = [x % xl, y - (parseInt(x / xl) * yl)] // 得到缩放后的终点 x y坐标
  if (!(JSON.stringify(terminus) in obj)) { //判断终点是否在运动轨迹上
    return false
  }
  return obstacles.every(item=>{
    let f = item[0]
    let s = item[1]
    if(f <= x && s <= y){  // 判断障碍物是否在终点之前
      let barrier = [f % xl, s - (parseInt(f/xl) * yl)] // 得到障碍物缩放后的 x y坐标
      if (JSON.stringify(barrier) in obj) { // 判断障碍物是否在运动轨迹上
        console.log('碰撞')
        return false
      }else{
        return true
      }
    }
    return true
  })
};
```

