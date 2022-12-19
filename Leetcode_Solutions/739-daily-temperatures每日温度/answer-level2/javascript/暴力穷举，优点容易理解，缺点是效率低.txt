### 解题思路
//直接暴力穷举：
//设置两个指针，一个指针指向当前元素，另一个指针向后遍历数组，
//直到找到元素比当前元素大的，它们的索引差就是当前元素对应的值
//最后一个元素对应的值肯定为0，所以直接在数组末尾push一个0

### 代码

```javascript
/**
 * @param {number[]} T
 * @return {number[]}
 */
var dailyTemperatures = function(T) {
    var Tem = [];
    for(var i=0; i<T.length; i++){
        for(var j=i+1; j<T.length; j++){
            if(T[i] < T[j]){
                Tem[i] = j - i;
                break;
            } else {
                Tem[i] = 0;
            }
        }
    }
    Tem.push(0);
    return Tem;
};
```