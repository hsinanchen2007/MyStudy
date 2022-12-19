```
// 因为字符串足够长，不能转成数字做
var numSteps = function(s) {
    let arr = s.split('');
    let cnt = 0;
    while(!(arr.length === 1 && arr[0] === '1')){
        if(arr[arr.length-1]==='0'){
            arr.pop();
        }else{
            // 是否进位
            let is = true;
            arr[arr.length-1] = '0';
            for (let i = arr.length - 2; i >= 0; i--) {
                if(!is){
                    break;
                }else{
                    if (arr[i] === '1'){
                        is = true;
                        arr[i] = '0';
                    }else{
                        arr[i] = '1'
                        is = false;
                    }
                }
            }
            if (is){
                arr.unshift('1');
            }
        }
        cnt++
    }
    return cnt;
};
```

前端算法库：https://github.com/cunzaizhuyi/js-leetcode  