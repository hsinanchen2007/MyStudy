![dp.png](https://pic.leetcode-cn.com/ad4462c229f4d0ced82ccbbc7dacc43a744541c121476f26298d39c083975291-dp.png)

```
var maxJumps = function(arr, d) {
    const len = arr.length;
    const a = new Array(len).fill(0);
    const get = (i)=>{
        if(a[i]!==0) return a[i];
        let ans = 1;
        // 向左
        for(let j=i-1; j>=0 && arr[j]<arr[i] && i-j<=d; j--){
            ans = Math.max(ans, get(j)+1);
        }
        // 向右
        for(let j=i+1; j<a.length && arr[j]<arr[i] && j-i<=d; j++){
             ans = Math.max(ans, get(j)+1);
        }
        return a[i] = ans;
    }

    for(let i=0; i<a.length; i++){
        if(a[i]!==0) continue;
        get(i)
    }
    return Math.max.apply(null, a);
}
```

