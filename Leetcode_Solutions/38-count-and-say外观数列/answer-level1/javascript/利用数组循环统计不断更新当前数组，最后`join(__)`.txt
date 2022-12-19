题意：下一位读出上一位的值 第一个从`1`开始 ，下一个读上一个`1个1`表示为 `11` ,下一位读它 `2个1` ,表示`21` ,依次...

那就一步一步挨个获取，计算到`n`

```javascript []
/**
 * @param {number} n
 * @return {string}
 */
var countAndSay = function(n) {
    // 1  1
    // 2  11
    // 3  21
    // 4  1211
    // 5  111221
    // 6  312211
    // 7  13112221
    // 8  1113213211
    // 9  31231221
    // 10 13111213112211
    // 11 111331121113212221
    // 12 3123211231131211321
    // 13 
    if(n == 1){
       return "1";
       }
    if(n == 2){
       return "11";
       }
    let result = ["1","1"];               // 结果数组，保存计算后的值
    for(let i =3;i<n+1;i++){              // 这边为了比较 ，从 3 开始，
        let temp = [],                  // 临时数组，存储某段的值
            nums = 1;                  // 计数
        for(let j = 1,len = result.length;j<len;j++){   
            if(result[j-1] == result[j]){       // 计算相同的值
                nums++;
                
             }else{                           // 不同值，则加入临时值得数组中
                 temp.push(""+nums);
                 temp.push(result[j-1]);
                nums = 1;
             }
            if(j+1 == len){        // 最后一个结束  
                    temp.push(""+nums);
                    temp.push(result[j]);
                 }
        }
        result = temp;                // 将计算值复制为结果数组
    }
    return result.join("");
};
```