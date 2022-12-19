### 解题思路
就是按照题意解答，标识一个轮数d,当循环结束后轮数+1，分得糖果数在原来基础上 (n*d + i);直到糖果分完，返回。

### 代码

```javascript
/**
 * @param {number} candies
 * @param {number} num_people
 * @return {number[]}
 */
var distributeCandies = function(candies, num_people) {
    var len = num_people;
    var sum = candies;
    var arr = [];
    var d = 0;
    var cont = 0;
    for(var i = 1;i<=len;i++){
        var have = arr[i-1] || 0;
         arr[i-1] = (arr[i-1] || i ) + (d === 0 ? 0 : (len*d + i)) ;
         sum-=arr[i-1]-have;
         if(sum<0){
             arr[i-1] = sum  + arr[i-1]
            
         }
         if(sum<=0){
             var nowLen = arr.length;
             if(nowLen<num_people){
                 arr.length = num_people;
                 arr.fill(0,nowLen,num_people);
             }
             return arr;
         }
         
         if(i === len && sum > 0 ){
             d++
             i = 0
         }
    }
    return arr;
};
```