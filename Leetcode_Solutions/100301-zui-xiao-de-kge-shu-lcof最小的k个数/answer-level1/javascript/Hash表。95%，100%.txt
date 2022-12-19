接着之前的题解。遇到个数问题，直接想办法套入hash
！坑点：如果用数组的话，那么前提是，数字不会太大（特指数组长度短，数字大）。
如果符合上述，时间不漂亮，可以弃坑了。。毕竟是用空间去换时间的。时间都不好看，那还是凉了。
```
/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number[]}
 */
var getLeastNumbers = function(arr, k) {
    if(k==0)return []
    if(k==arr.length) return arr
    let newres=[];
    let max= Math.max(...arr)
    let res=Array(max+1).fill(0);//创建大小相同的数组
    for (let i =0;i<=arr.length-1;i++){
        res[arr[i]]++;
    }
    for (let j =0 ;j<=res.length-1;j++){
        while(res[j]>0&&newres.length!==k){
            newres.push(j);
            res[j]--;
        }
    }
    return newres;
};
```
