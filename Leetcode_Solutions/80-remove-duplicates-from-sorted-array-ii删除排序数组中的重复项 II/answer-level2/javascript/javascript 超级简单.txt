和26删除重复元素解法类似，
26题如果a[i] a[j]两个一样，则进入下一个循环j++
我们再这题中需要额外判断一下a[i]和a[i-1],如果不一样，则可以把a[j]换到a[i+1]上，这是此题唯一区别
```javascript
var removeDuplicates = function(arr) {
    if(arr.length< 3) return arr.length  //注意边界条件
    let i=1  //注意边界条件
    for(let j=2;j<arr.length;j++){  //注意边界条件
        if(arr[j]!==arr[i]){
            arr[i+1] = arr[j]
            i++
        }else{       //和26的唯一区别
           if(arr[i]!==arr[i-1]){
                arr[i+1] = arr[j]
                i++
            }
        }
    }
    return i+1
};
```