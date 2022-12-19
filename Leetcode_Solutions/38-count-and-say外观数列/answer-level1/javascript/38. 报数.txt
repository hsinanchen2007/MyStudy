```
var countAndSay = function(n) {
    let arr = ["1"];
    if(n == 1) return arr[n-1];
    for(let i = 1;i<n;i++){
        let strArr = arr[i-1].split('');
        let limt = strArr.length;
        let cur = 0;
        let str = '';
        while(cur<limt){
            let count = 1;
            while(strArr[cur] == strArr[cur+1]){
                  count++;cur++;
            }
            str+=count+''+strArr[cur];
            cur++;
        }
        arr[i] = str;
    }
    return arr[n-1];
};
```
