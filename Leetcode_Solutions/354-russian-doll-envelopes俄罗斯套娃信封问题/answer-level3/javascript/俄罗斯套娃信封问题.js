```
var maxEnvelopes = function(envelopes) {
    if(!envelopes.length) return 0;
    let count = [];
    count[0] = new Array(envelopes.length).fill(1);
    count[1] = new Array(envelopes.length).fill(1);
    for(let i = 0;i<2;i++){
        let arr = envelopes.map((o)=>o);
        arr.sort((a,b)=>a[i]-b[i]);
        console.log(i,arr);
        for(let j = 1;j<arr.length;j++){
            for(let k = 0;k<j;k++){
                //dp[i] = Math.max(dp[i], nums[i] > nums[j] ? dp[j] + 1 : 1)
                count[i][j] = Math.max(count[i][j],arr[j][0] > arr[k][0] && arr[j][1] > arr[k][1] ?count[i][k] + 1 : 1);
            }
        }
    }
    console.log(count);
    return Math.max(...count[0],...count[1]);
};
```

这个就利用求最长上升子序列多包裹一层循环就可以简单的实现效果了