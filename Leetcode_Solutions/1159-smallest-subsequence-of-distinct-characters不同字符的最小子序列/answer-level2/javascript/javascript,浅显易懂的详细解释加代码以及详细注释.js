```javascript
var smallestSubsequence = function(text) {
    //构造字典顺序的所有要找的字符数组
    let arr = Array.from(new Set(text.split(""))).sort((a,b)=>a.charCodeAt()-b.charCodeAt());
    let ans = [];
    let i=0;
    while(arr.length>0){
        let c=arr[i];
        let searched = text.indexOf(c);
        let broken=false;
        // i+1之前的字符肯定能再c之后找到
        // 因为i+1之前的字符的后面无法找到c字符
        // 因此起始条件判断可以由i+1开始
        for(let j=i+1;j<arr.length;j++){
            if(text.indexOf(arr[j],searched+1)<0){
                i++;
                broken=true;
                break;
            }
        }
        if(!broken){
            //c字符已经找好了，无需再判断了
            arr.splice(i,1);
            //c字符对应索引之前的位置不需要再找了，截掉
            text=text.substr(searched+1);
            i=0;
            //找好的字符放到结果数组中
            ans.push(c);
        }
    }
    return ans.join("");
};
```

例如：`cdadabcc`    

1. 所有要找的字符按字典排序——`[a,b,c,d]`  
2. 找`a`的索引——`2`  
3. 判断在`2`位置之后是否存在其他所有字符：存在`b、c、d`——`true`  
4. 找到了第一个符合条件的字母——`a`  
5.`a`已经找到了从需要找的数组里面排除掉——`[a,b,c,d]`  => `[b,c,d]`  
6. 舍弃`2`位置以及其之前的字符——`cdadabcc` => `dabcc`  

-------

1. 找`b`的索引——`2`
2. 判断`2`位置之后是否存在其他所有字符,存在`c`：不存在`d`——`false`
3. 找`c`的索引——`3`
4. 判断`3`位置之后是否存在其他所有字符：不存在`b、d`——`false`
5. 找`d`的索引——`0`
6. 判断`0`位置之后是否存在其他所有字符：存在`b、c`——`true`
7. 找到了第二个符合条件的字母——`d`
8.`d`已经找到了从需要找的数组里面排除掉——`[b,c,d]`  => `[b,c]`
9. 舍弃`0`位置以及其之前的字符——`dabcc` => `abcc`

------

1. 找`c`的索引——`2`
2. 判断`2`位置之后是否存在其他所有字符：不存在`b`——`false`
3.找`b`的索引——`1`
4. 判断`2`位置之后是否存在其他所有字符,存在`c`——`true`
5. 找到了第三个符合条件的字母——`b`

------

1. 找到了最后一个符合条件的字母——`c`

-----
结果依次为：`a,d,b,c`