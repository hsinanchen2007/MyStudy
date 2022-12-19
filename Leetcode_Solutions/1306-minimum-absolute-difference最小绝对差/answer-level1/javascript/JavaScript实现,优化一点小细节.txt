![WechatIMG17046.jpeg](https://pic.leetcode-cn.com/ac6d3435325a8abb3a231e6b1cf5daed4a78c053032bec64f45bca9657bf1c20-WechatIMG17046.jpeg)



此题解决起来比较简单,主要应关注如何减少计算量
* 一开始就进行从大到小排序,减少最后数组翻转操作
* 反向pop出结果项,减少循环次数.


```
var minimumAbsDifference = function(arr) {
    var sortArr = arr.sort(function(a,b){
        return  b - a; //从大到小排列
    })
    var res = [];
    var minValue = Number.MAX_VALUE;
    var i;
    for(i = 1;i<sortArr.length;i++){
        if(sortArr[i-1]-sortArr[i]<=minValue){
            minValue = sortArr[i-1]-sortArr[i] 
            res.push([sortArr[i] ,sortArr[i-1]]) // 把绝对值最小的若干项存在数组末尾
        }
    }
    var popRes = [];
    var arrData = res.pop();
    minValue = Number.MAX_VALUE;
    while(1){
        if(arrData && (arrData[1] - arrData[0])<=minValue){
            popRes.push(arrData)//pop出若干项,作为结果输出
            minValue = arrData[1]-arrData[0]
            arrData = res.pop();
        }else{
            break;
        }
    }
    return popRes;        
};
```
