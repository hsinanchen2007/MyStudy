![RSV{YQ44U6Z{ERVY~~U{_EE.png](https://pic.leetcode-cn.com/e80937ebe7725b2a054ffe99522dc22545949e8ea33a147d9092049831a565c2-RSV%7BYQ44U6Z%7BERVY~~U%7B_EE.png)
```
 var distanceBetweenBusStops = function(distance, start, destination) {
            if(start>destination){
                [start,destination] = [destination,start];
            } //如果开始站的位置大于结束站的位置下标，为了方便计算，交换两站下标。
            let arr0 = distance.slice(start,destination);  //剪切两站间的每站距离数组
            let disOne = arr0.reduce((a,b)=>a+b); //计算两点间的距离；
            let disTwo = distance.reduce((a,b)=>a+b)-disOne;//总距离减去disOne等于向反方向行驶的距离
            return Math.min(disOne,disTwo);//取两距离最小
    };  
```
