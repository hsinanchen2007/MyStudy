对数组A进行排列 A_4^4 = 4 * 3 * 2 * 1，再将排列的二维数组按降序进行筛选返回结果
```js
var largestTimeFromDigits = function(A) {
    var res = [];
    function arrange(){
        var x = 0;
        for(var i=0;i<A.length;i++){
            var a = A[i];
            var temp1 = [...A];
            temp1.splice(temp1.indexOf(a), 1);
            for(var j=0;j<temp1.length;j++){
                var b = temp1[j];
                var temp2 = [...temp1];
                temp2.splice(temp2.indexOf(b), 1);
                for(var m=0;m<temp2.length;m++){
                    var c = temp2[m];
                    var temp3 = [...temp2];
                    temp3.splice(temp3.indexOf(c), 1);
                    var d = temp3[0];
                    res[x++] = [a,b,c,d];
                }
            }
        }
        return res;
    }
    arrange();
    res.sort((a,b)=>Number(b.join('')) - Number(a.join('')));
    var flag = true;
    while(flag){
        var tempArr = res.splice(0,1)[0];
        if(isValidTime(tempArr)){
            flag = false;
            tempArr.splice(2, 0, ':');
            return tempArr.join('');
        }
        if(res.length === 0){
            flag = false;
        }
    }
    return '';
    function isValidTime(arr){
        if(arr[0] > 2 || arr[0] === 2 && arr[1] > 3 ||
            arr[2] > 5) return false;
        return true;
    }
};
```