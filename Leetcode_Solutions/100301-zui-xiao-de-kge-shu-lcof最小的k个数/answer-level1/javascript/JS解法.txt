
## 一、普通排序(快速排序也可)

```javascript
 
var getLeastNumbers = function(arr, k) {
     arr.sort((a,b) => a-b)
     let result = []
     for(let i=0; i<k; i++){
         result.push(arr[i])
     }
     return result
}; 
```
时间复杂度：O(nlog(n))
空间复杂度：O(k)

## 二、选择排序的部分排序

```javascript

var getLeastNumbers = function(arr, k) {
    let result = []
    for(let i=0, min, len=arr.length; i<k; i++){
        min = arr[i];
        for(let j=i+1; j<len; j++){
            if(arr[j]<min){
                let c = min;
                min = arr[j];
                arr[j] = c;
            }
        }
        arr[i] = min;
        result.push(arr[i])
    }
    return result
};
```
时间复杂度：O(n*k)
空间复杂度：O(k)
