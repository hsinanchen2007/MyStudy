var getNoZeroIntegers = function(n) {
    let arr=[];
    if(n===1){
        return arr;
    }else if(n===2){
        arr=[1,1]
    }else{
        for(let i=1;i<n;){
            if(String(n-i).indexOf('0')!==-1||String(i).indexOf('0')!==-1){
                i++
            }else{
                arr=[i,n-i];
                break
            }
        }
    }
    return arr;
};
![image.png](https://pic.leetcode-cn.com/08bf7691067d0fbc19aa4c41333146ddb737be89bc8221c0653539b51803cf49-image.png)
