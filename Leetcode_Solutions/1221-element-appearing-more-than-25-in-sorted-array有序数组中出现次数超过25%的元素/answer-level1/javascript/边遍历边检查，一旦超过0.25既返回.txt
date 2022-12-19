### 解题思路
1. 遍历数组，遇到重复的元素就把变量累加1，然后检查是否占比超越％25，是的话返回
2. 遇到不一样的就重设累加器为1

### 代码

```javascript
/**
 * @param {number[]} arr
 * @return {number}
 */
var findSpecialInteger = function(arr) {
    let count = 0, current;
    const l = arr.length;
    for(let ele of arr){
        if(ele == current){
            count++;
            if(count/l>0.25)return ele;
        }else{
            count=1;
            current=ele;
            if(count/l>0.25)return ele;
        }
    }
    throw Error('WTF HAVE YOU FED ME!!!')
};
```