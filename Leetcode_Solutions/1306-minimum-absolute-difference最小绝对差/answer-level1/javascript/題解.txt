### 解题思路
先將arr中元素升序排序，排完序後跑迴圈取出arr[i]與arr[i+1]相減並取得絕對值並將此組數值存入res，
在重複此過程比較此絕對值是否比之前小，比之前小就清空res並將此組數值存入，跟之前一樣將此組數值存入即可

### 代码

```javascript
/**
 * @param {number[]} arr
 * @return {number[][]}
 */
var minimumAbsDifference = function(arr) {
    let res=[];
    arr.sort((a,b)=>a-b);
    for(let i=0;i<arr.length-1;i++){
        if(res.length==0){
            res.push([arr[i],arr[i+1]])
        }else{
            let fristAbsDifference=Math.abs(res[0][0]-res[0][1]);
            let minimumAbs= Math.abs(arr[i]-arr[i+1]);
            if(minimumAbs==fristAbsDifference){
                res.push([arr[i],arr[i+1]])
            }else if(minimumAbs<fristAbsDifference){
                res=[];
                res.push([arr[i],arr[i+1]])
            }
        }
    }
    return res;
};
```