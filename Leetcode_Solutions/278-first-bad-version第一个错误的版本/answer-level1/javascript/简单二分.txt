```
var solution = function(isBadVersion) {
    /**
     * @param {integer} n Total versions
     * @return {integer} The first bad version
     */
    return function(n) {
        //调用isBadVersion接口   其实可以近似看成是一个升序序列
        let l = 1;
        let r = n;
        while(l<r){
            let mid = l+Math.floor((r-l)/2);   //防止溢出
            if(isBadVersion(mid)==false){
                l=mid+1;
            } else {
                r=mid;
            }
        }
        return l;
    };
};
```
