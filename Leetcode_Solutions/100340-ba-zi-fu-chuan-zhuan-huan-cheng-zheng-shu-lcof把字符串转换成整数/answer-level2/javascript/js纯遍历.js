### 解题思路
纯遍历

### 代码

```javascript
/**
 * @param {string} str
 * @return {number}
 */
var strToInt = function(str) {
    var res=0;
    // var str=[str];
    var k=0;
    var fu=false;
    for(let i of str){
        if(i==" "){
            k++;
        }else{
            break;
        }
    }
    var temp=str[k];
    if(temp<'0' ||temp>'9'){
        if(temp=='+') k++;
        else if(temp=='-'){
            fu=true;
            k++;
        }else return 0;
    }
    for(let i=k;i<str.length; i++){
        if(str[i]>'9'||str[i]<'0'){
            break;
        }
        
        res= res*10+(str[i]-'0');
        console.log(str[i],res);
    }
    if(fu) res=res*(-1);
    if(res>Math.pow(2,31)-1){
            res=Math.pow(2,31)-1;
    }else if(res<-Math.pow(2,31)){
            res=-Math.pow(2,31)
        }
    return res;

};
```