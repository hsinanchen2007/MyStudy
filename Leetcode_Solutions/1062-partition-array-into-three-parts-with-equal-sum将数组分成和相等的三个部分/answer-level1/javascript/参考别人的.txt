欠了两天了
```
var canThreePartsEqualSum = function(A) {
    let sum = A.reduce((acc,cur)=>acc+cur) //sum数组之和
    let temp = 0   //temp累加
    let cnt = 0   //cnt计数
    for(let i=0;i<A.length;i++){
        temp += A[i] 
        if(temp == sum/3){  
            cnt++   
            temp = 0
        }
    }
    return (sum!=0 && cnt==3)||(sum==0 && cnt>2)
};

```
