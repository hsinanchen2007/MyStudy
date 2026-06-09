思路是，转成字符串然后从高到底转化成需要的字符拼起来

```
/**
 * @param {number} num
 * @return {string}
 */
var intToRoman = function(num) {

    let  arr=[["I","V"],["X","L"],["C","D"],["M"],]
    let str=num+"";
    let  re=""
    
    for(let i=0;i<str.length;i++){
        let len=str.length-i-1;
        str[i]=parseInt(str[i])
        if( 0<str[i]&&str[i]<4){
            for(let j=0;j<str[i];j++){
                    re+=arr[len][0]
            }
      
        }else if(str[i]==4){
            re+=arr[len][0]+arr[len][1]
      
        }else if(4<str[i]&&str[i]<9){
             re+=arr[len][1]
            for(let j=5;j<str[i];j++){
                re+=arr[len][0]
            }     
        }else if(str[i]==9){
              re+=arr[len][0]+arr[len+1][0]
        }
        
    }
    return  re
    
};
```
