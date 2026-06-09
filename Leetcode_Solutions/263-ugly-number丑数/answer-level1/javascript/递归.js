
```javascript
const isUgly = (num)=>{
     if(num<=0) return false;
     if(num===1) return true;
    let obj={2:true,3:true,5:true};
    const helper=num0=>{
        if(obj[num0]) return true;
        if (num0%2===0){
            return helper(num0/2);
        }else if(num0%3===0){
            return helper(num0/3);
        }else if(num0%5===0){
            return helper(num0/5);
        }else{
            return false;
        }
    };
    return helper(num);
};
```