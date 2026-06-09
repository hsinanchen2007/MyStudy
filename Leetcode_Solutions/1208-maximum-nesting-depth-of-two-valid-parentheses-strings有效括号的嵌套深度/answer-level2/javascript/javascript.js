1. 先计算`seq`每个位置`i`对应的深度`arr[i]`
2. 在`arr`中最大深度`max`
3. 取深度的一半`mid`，若某个点`arr[i]>mid`,那么将其分配给B，否则分配给A  

例如：最大深度为4，无论如何取值`max(deepth(A),deepth(B))`都不可能比2小了，那么将所有深度大于2的都分配给B，深度小于2的都分配给A，那么此时的`max(deepth(A),deepth(B))`最小并为：`2`

```javascript
var maxDepthAfterSplit = function(seq) {
    let deep=0;
    let arr=new Array(seq.length);
    let max=0;
    for(let i=0;i<seq.length;i++){
        if(seq[i]==="("){
            deep++;
        }
        arr[i]=deep;
        max=Math.max(max,deep)
        if(seq[i]===")"){
            deep--;
        }
    }
    let mid=max>>1;
    return arr.map(item=>item>mid?1:0);
};
```