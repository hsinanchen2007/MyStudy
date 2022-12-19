### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} num
 * @return {number}
 */
var numberOfSteps  = function(num) {
    let step=0;
    while(num!=0){
        if(num%2==0){
            step++;
            num=num/2
        }else{
            num--;
            step++;
        }
    }
    return step
};
```