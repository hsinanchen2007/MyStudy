执行用时 :
76 ms, 在所有 JavaScript 提交中击败了90.62%的用户
内存消耗 :34.2 MB, 在所有 JavaScript 提交中击败了91.22%的用户
以map结构做存储，map映射的每个value做一次循环，判断前后是否相等，相等数量+1，不相等将当前的个数和值添加到临时变量中，循环结束将临时变量添加到map中，最后判断map中是否有对应的key
```
const countAndSay_2=(n)=>{
    let str = '';
    let tempMap= new Map([
        [1,'1']
    ])
    for(let key of tempMap.keys()){
        const tempObj = tempMap.get(key);
        let target = tempObj[0];
        let count =1;
        for(let i =0;i<tempObj.length;i++){
            if(tempObj[i+1]!=target){
                str += `${count}${target}`;
                count=1;
                target = tempObj[i+1];
            }else{
                count++;
            }
        }
        let num_index = parseInt(key);
        tempMap.set(num_index+1,str);
        str='';
        if(tempMap.has(n)){
            return tempMap.get(n);
        }
    }
}
```