/**
 * @param {string} s
 * @return {number}
 * 思路：
 * 1、js抓位置，该位置对比后一个位置的值，比后一个值大，之前用，比后一个值小，加上后一个值再进行运算
 * 2、1>undefind 是false,所以最后一位i的判断需要提前判断i+1是否存在
 *
 */
```

var romanToInt = function(s) {
    //先解构，
  let awe = [],
      newnum = 0;
    awe['I']=1;
    awe['V']=5;
    awe['X']=10;
    awe['L']=50;
    awe['C']=100;
    awe['D']=500;
    awe['M']=1000;

    for(var i=0;i<s.length;i++){
        //先判断最后一位的后一位是否存在
        if(!awe[s[i+1]]){
            newnum += awe[s[i]];
            break
        }
        //正常运算
        if(awe[s[i]]>=awe[s[i+1]]){
            newnum += awe[s[i]];
        }else{
            //此位小于后位，加上后位进行运算，记得i+1
            newnum = newnum + awe[s[i+1]] - awe[s[i]];
            i++;
        }
        
    }
    return newnum
};
```
