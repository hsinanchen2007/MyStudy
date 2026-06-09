### 解题思路


### 代码

```javascript
/**
 * @param {number} target
 * @return {number[][]}
 */
var findContinuousSequence = function(target) {
    var i=1,j=2;
    var arr=[];
    
    while(i<j){
        var sum=(i+j)*(j-i+1)/2;
        if(sum<target){
            j++;
            sum += j;
        }else if(sum>target){
            i++;
            sum -= i;
        }else{
            var temp=[];
            for(var m=i;m<=j;m++){
                temp.push(m);
            }
            arr.push(temp);
            i++;
            j++;
        }
    }
    return arr;
};
```