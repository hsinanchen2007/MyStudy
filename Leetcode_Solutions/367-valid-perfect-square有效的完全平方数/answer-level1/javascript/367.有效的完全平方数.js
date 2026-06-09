## 暴力破解
```
var isPerfectSquare = function(num) {
    if(num == 1) return true;
    for(let i = 1,len = num/2;i<=len;i++){
        if(i*i == num){
           return true;
        }
    }
    return false;
};
```

## 二分法
```
var isPerfectSquare = function(num) {
    if(num == 1) return true;
    let left = 1,right = num;
    while(left <= right){
        let mid = parseInt((left+right)/2);
        let temp = mid*mid;
        if(temp == num){
             return true;
        }else if(temp > num){
             right = mid-1;
        }else{
            left = mid+1;
        }
    }
    return false;
};
```
## 牛顿迭代
```
var isPerfectSquare = function(num) {
    if(num == 1) return true;
    let cur = parseInt(num/2);
    while(!(cur*cur<=num&&(cur+1)*(cur+1)>num)){
        cur = parseInt(cur-(cur*cur-num)/(2*cur))
    }
    return cur*cur == num;
};
```
## 数理
```
var isPerfectSquare = function(num) {
        let i = 1;
        while(num > 0) {
            num -= i;
            i += 2;
        }
        return num == 0;
}
```
