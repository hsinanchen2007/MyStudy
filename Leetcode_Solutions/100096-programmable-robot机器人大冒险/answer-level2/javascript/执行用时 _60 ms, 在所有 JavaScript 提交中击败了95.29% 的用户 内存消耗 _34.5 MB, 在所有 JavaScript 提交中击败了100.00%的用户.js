### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} command
 * @param {number[][]} obstacles
 * @param {number} x
 * @param {number} y
 * @return {boolean}
 */
var robot = function(command, obstacles, x, y) {
    var mapFa = {
        '0,0' : 1
    };
    let indX = 0;
    let indY = 0;
    for(var i = 0; i < command.length; i++){
        if(command[i] == 'U'){
          indY++;
        }
        if(command[i] == 'R'){
           indX++;
        }
        mapFa[[indX,indY]] = 1;
    }
    var ret_x = 0;
    var ret_y = 0;
    var cir = 0;
    cir = Math.min(Math.floor(x/indX),Math.floor(y/indY));
    ret_x = x - cir*indX;
    ret_y = y - cir*indY;
    if(!mapFa[[ret_x,ret_y]]){
        return false;
    }
    var obret_x = 0;
    var obret_y = 0;
    for(var j = 0; j < obstacles.length; j++){
        obret_x = obstacles[j][0];
        obret_y = obstacles[j][1];
        if(obret_x > x || obret_y > y){
            continue;
        }
        cir = Math.min(Math.floor(obret_x/indX),Math.floor(obret_y/indY));
        ret_x = obret_x - cir*indX;
        ret_y = obret_y - cir*indY;
        if(mapFa[[ret_x,ret_y]]){
          return false;
        }
    }
    return true;
};
```