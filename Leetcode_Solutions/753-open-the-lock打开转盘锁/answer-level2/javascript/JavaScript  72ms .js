```
/**
 * @param {string[]} deadends
 * @param {string} target
 * @return {number}
 */
var openLock = function(deadends, target) {
    if(target==null || target=="0000") return -1
    let start="0000"
    if(deadends.includes(target)||deadends.includes(start)) return -1
    let queue=[]
    let visited=new Set(deadends)
    let step=0
    queue.push(start)
    visited.add(start)
    while(queue.length>0){
        for(let i=queue.length; i>0; i--){
            let cur=queue.shift();
            if(target===cur){ // 找到了目标返回步骤数
                return step;
            }
            // console.log(queue)
            let nexts=getNexts(cur);
            for(let str of nexts){
                if(!deadends.includes(str) && !visited.has(str)){
                   visited.add(str)
                    queue.push(str);
                }
            }
        }
        step++;
    }  
    return -1  
};

function getNexts(cur){
    let list=[];
    for(let i=0; i<4; i++){
        let curArr=cur.split('');
        let modChar=Number(cur.charAt(i));
        curArr[i]=modChar=='0'?'9':(modChar-1)
        list.push(curArr.join(''));
        curArr[i]=modChar=='9'?'0':(modChar+1);
        list.push(curArr.join(''));
    }
    return list;
}
  

```
