### 解题思路
首先按照题目的思路来。顺时针旋转，遍历到第一行，把第一行的内容加入result,最后一行的内容倒序加入result，其他取数组的最后一个，去除以上已经加入过数组的元素后，然后在处理左侧边，
遍历数组，加入第一个元素到result，移除第一个元素，一轮已经完成。剩下的工作就是递归了。注意特殊的情况，可能会出现侧边数组移除后为空，固要在遍历之前先判断是不是为空，否则return result。
### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var spiralOrder = function(matrix) {
  let bianli=(arr,result) => {
    for(let i=0,len=arr.length;i<len;i++){
       if(!arr[i].length){
            return result;
        }
      if(i===0){
        //说明第一排元素
        result=result.concat(arr[i]);
      }else if(i===len-1){
        result=result.concat(arr[i].reverse());
      }else{
          result.push(arr[i].pop());
      }
  }
    arr.shift();
    arr.pop();
  for(let i=arr.length-1;i>=0;i--){
      if(arr[i].length){
      //shift 删除第一个元素并返回删除的值
      result.push(arr[i].shift());
      }else{
          return result;
      }
  }
  //如果数组还有，就递归处理
  if(arr.length){
     return bianli(arr,result);
  }else{
      return result;
   }
  }
  return bianli(matrix,[]);
};
```