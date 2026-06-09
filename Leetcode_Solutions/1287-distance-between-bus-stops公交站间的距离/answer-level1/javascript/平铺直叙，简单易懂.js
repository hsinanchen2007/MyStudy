### 解题思路

因为是个环，所以需要考虑正向和逆向。

1.算出总距离
2. 调整参数，先算正向
3. 总距离减正向得逆向
4. 取正逆最小者，即为解

### 代码

```javascript
var distanceBetweenBusStops = function (distance, start, destination) {
   //算出总数
  let total = distance.reduce((sum, cur) => sum + cur, 0)
  let forward = 0
   //调整参数，为了先算正向
  if (start > destination) { 
    [start,destination]=[destination,start]
  }
  //先算正向
  for (let i = start; i < destination; i++){
    forward+=distance[i]
  }
  //再算逆向
  let backword = total - forward
  
  return Math.min(forward,backword)
};

```