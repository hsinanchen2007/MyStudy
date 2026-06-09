![a.png](https://pic.leetcode-cn.com/2e2258b1fde841906b00aafe38a752d405fdd311f29100eb73b7dc5f7773134c-a.png)

就是将内层数组元素的高度提高到初始数组的最高高度，然后遍历内层的数组元素的上下左右的元素的高度，算出当前元素的最高高度，用while循环遍历，当一个循环内的所有元素的高度都不会变化，则认为已经结束，计算增加的高度及储水量。
```
/**
 * @param {number[][]} heightMap
 * @return {number}
 */
var trapRainWater = function(heightMap) {
    if(heightMap.length<3){
        return 0;
    }
    else if(heightMap[0].length<3){
        return 0;
    }
    var max_height = 0;
    var newArr = new Array();
    for(var i=0;i<heightMap.length;i++){
        newArr[i]=new Array(); 
        for(var j=0;j<heightMap[i].length;j++){
            newArr[i][j]=heightMap[i][j];
            //找出最大值
            if(heightMap[i][j]>max_height){
                max_height = heightMap[i][j];
            }
            if(i>0&&j>0&&i<heightMap.length-1&&j<heightMap[i].length-1){
                if(max_height>heightMap[i][j]){
                    newArr[i][j]=max_height;
                }

            }
        }
    }


    var num_temp =1;
    var count=0;
    while(num_temp!=0){
        num_temp=0;
        for(var i=1;i<newArr.length-1;i++){
            for(var j=1;j<newArr[i].length-1;j++){
                count++;
                var height = newArr[i][j];
                var height1= heightMap[i][j];
                if(height ==height1){
                    continue;
                }
                var up = newArr[i-1][j];
                var down = newArr[i+1][j];
                var left = newArr[i][j-1];
                var right = newArr[i][j+1];
                if(height>up){
                    if(up<heightMap[i][j]){
                        height=heightMap[i][j];
                    }
                    else{
                        height = up;
                    }
                    num_temp++;
                }
                if(height>down){
                    if(down<heightMap[i][j]){
                        height=heightMap[i][j];
                    }
                    else{
                        height = down;
                    }
                    num_temp++;
                }
                if(height>left){
                    if(left<heightMap[i][j]){
                        height=heightMap[i][j];
                    }
                    else{
                        height = left;
                    }
                    num_temp++;
                }
                if(height>right){
                    if(right<heightMap[i][j]){
                        height=heightMap[i][j];
                    }
                    else{
                        height = right;
                    }
                    num_temp++;
                }
                    newArr[i][j]=height;
            }
        }
    }
    console.log("次数："+count);
    var num=0;
    for(var i=0;i<heightMap.length;i++){
        for(var j=0;j<heightMap[i].length;j++){
            num += newArr[i][j]-heightMap[i][j];
        }
    }
    return num;
};
```

