### 解题思路
判断两个数组哪个长，长的截成比短的+1的长度，填充进去即可

### 代码

```javascript
/**
 * @param {number} A
 * @param {number} B
 * @return {string}
 */
var strWithout3a3b = function(A, B) {

   function fill(letter,length){
     let arr=[];
     for(let i=0;i<length;i++){
       arr.push(letter);
     }
     return arr;
   }
  // 上限max=(min+1)*2
    var max=(A>=B)?A:B;
    var min=(A<=B)?A:B;

    if(A>B){
      var maxVal="a", minVal="b";
    }else{
      var maxVal="b", minVal="a";
    }

    //空格数
    var box=min+1;
    //每个空放一个时还剩几个max
    var beside=max-box;
    // 先做两个一组的数组
    var arr=fill((maxVal+maxVal),beside)
    // 再造一个数的数组
    if(max>2 && beside>0){
        var arr2=fill(maxVal,(max-beside*2))
        Array.prototype.push.apply(arr,arr2)
    }else{
      arr=fill(maxVal,max)
    }

    
    
    var arr3=(new Array(min)).fill(minVal)
    
    var str ="";
    for(let i=0;i<arr3.length;i++){
      str+=arr[i]+arr3[i];
    }
    if(arr.length>arr3.length){
      str+=arr[arr.length-1]
    }

    return str
};
```