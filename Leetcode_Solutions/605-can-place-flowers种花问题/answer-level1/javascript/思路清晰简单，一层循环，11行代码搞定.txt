count 代表 0的个数

有2种情况：

1、全为0时： Math.floor((count+1)/2);

2、有1存在时，可分成3个部分：
    首个1前:
            Math.floor(count/2);  
    中间:
            Math.floor((count-1)/2); 
    结尾: 
            Math.floor(count/2);
```javascript []
var canPlaceFlowers = function(flowerbed, n) {
    let count = 1, sum = 0;
    for(val of flowerbed){
        if(val==1){
            if(count>1) sum += Math.floor((count-1)/2);
            count = 0;
        }else{
            count++;
        }
    }
    if(count>1) sum += Math.floor(count/2);
    return sum>=n
};
```
									
代码解释：
count 初始值为 1，遍历到当前值为0时，count++

1、全为0时：因为count 初始值为 1，遍历后的 count 就是 ( 0的个数 )+1

2、首次遍历到当前值为1， 且 count>1 时，首个1前的 count 为 ( 0的个数 )+1，所以count需要-1；
   然后重置 count初始值为 0，为计算中间准备

3、遍历到当前值为1， 且 count>1 时，中间的 count 为 ( 0的个数 )，所以count需要-1；

4、因为在遍历结尾时， count初始值为0，for循环结束后，结尾的 count 为 ( 0的个数 )。