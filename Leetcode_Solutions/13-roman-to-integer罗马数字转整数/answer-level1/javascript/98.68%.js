暴力暴力
```
/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function(s) {
    let res = 0,arr=s.split("").reverse();
    for(let i =0;i<arr.length;){
        let a = arr[i];
        if(a=="I"){
            res+=1
            i++;
        }
        if(a=="V"){
            if(arr[i+1]=="I"){
                res+=4
                i+=2
            }else{
                res+=5
                i++
            }
        }
        if(a=="X"){
            if(arr[i+1]=="I"){
                res+=9
                i+=2
            }else{
                res+=10
                i++
            }
        }
        if(a=="L"){
            if(arr[i+1]=="X"){
                res+=40
                i+=2
            }else{
                res+=50
                i++
            }
        }
        if(a=="C"){
            if(arr[i+1]=="X"){
                res+=90
                i+=2
            }else{
                res+=100
                i++
            }
        }
        if(a=="D"){
            if(arr[i+1]=="C"){
                res+=400
                i+=2
            }else{
                res+=500
                i++
            }
        }
        if(a=="M"){
            if(arr[i+1]=="C"){
                res+=900
                i+=2
            }else{
                res+=1000
                i++
            }
        }
    }
    return res
};
```

