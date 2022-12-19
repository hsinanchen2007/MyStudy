没什么好说的，笨办法，分析下标的规律，然后翻译成代码


```
/**
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */
var convert = function(s, numRows) {
    let newS="";
    if(numRows<2) return s;
    
    for(let i=0;i<numRows;i++){
        //j表示在字符串中的下标
        let j=i;
        if(i==0||i==numRows-1){
            while(j<s.length){
               newS+=s[j];
               j+=numRows*2-2
           }
        }else {
           while(j<s.length){
               newS+=s[j];
               j+=(numRows-i)*2-2;
               if(j<s.length){
                   newS+=s[j];
                   j+=i*2
                  }
           }
    
        }
    }
    return newS

};
```
