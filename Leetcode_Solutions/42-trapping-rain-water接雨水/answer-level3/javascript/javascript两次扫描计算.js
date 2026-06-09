```
var trap = function(height) {
    //sum=总数，h每次的刻度线，s每次未多刻度线累积的数,max最大刻度线
    let sum = 0,h = 0,s = 0,max = Math.max(...height);
    for(let i=0,j=height.length;i<j;i++){
        let x = height[i];
        if(x >= h){
            h = x,sum += s,s = 0;
            //重点这里遇到最大刻度直接退出循环，是为了防止有多个最大刻度，重复计算
            if(x === max) break;
        }else{
            s += h - x;
        }
    }
    //反过来计算一遍
    h = 0,s = 0;
    for(let i=height.length-1;i>=0;i--){
        let x = height[i];
        if(x >= h){
            h = x,sum += s,s = 0;
        }else{
            s += h - x;
        }
    }
    return sum
};
```
