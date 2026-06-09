### 解题思路
利用桶的解决思路
1.先用Map将出现的频率统计好
2，再创建桶，放到数组中，桶在数组中的下标，就是数字出现的频率
3.遍历这些桶，最先进入数组的K个数，就是最大或者最小

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var topKFrequent = function(nums, k) {
    if(nums ==null){return null}
    let dict = new Map()
    //保存每个数出现的频率
    for(let v of nums){
        let t = dict.get(v)
        dict.set(v, t == undefined ? 1: ++t)
    }
    let arr =[] 
　   dict.forEach(function(value,a){
　　　　if(arr[dict.get(a)] == undefined){
         let tempArr = new Array()
         tempArr.push(a)
         arr[dict.get(a)] = tempArr
       }else{
          let c = arr[dict.get(a)]
          c.push(a)
      }　　
　　　});
    let result = []
    for(let i = arr.length -1; i > 0; i--){
        let t = arr[i]
        if(t != null){
          t.forEach((item,index,array)=>{
              if(result.length == k){
                  return result
              }
              result.push(item)
          })
        }
    }
   return result
};
```