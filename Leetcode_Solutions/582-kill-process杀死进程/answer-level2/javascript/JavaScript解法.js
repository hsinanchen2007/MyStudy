### 解题思路
map + 递归
时间有些慢，还请大佬给些优化的意见

### 代码

```javascript
/**
 * @param {number[]} pid
 * @param {number[]} ppid
 * @param {number} kill
 * @return {number[]}
 */
var killProcess = function(pid, ppid, kill) {
    var mp = new Map();
    for (let i=0;i<pid.length;i++){
        if (mp.has(ppid[i])){
            mp.set(ppid[i],mp.get(ppid[i]).concat([pid[i]]))
        }
        else{
            mp.set(ppid[i],[pid[i]])
        }
    }
    var arr=[];
    killPro(kill);
    if (arr.length===0){
        arr.push(kill)
        return arr
    }
    else return arr
    

    function killPro(k){
        if (mp.has(k)){
            if (arr.indexOf(k)===-1){
                arr.push(k)
            }
            for (let i=0;i<mp.get(k).length;i++){
                arr.push(mp.get(k)[i])
                killPro(mp.get(k)[i])
            }
        }
        else{
            return
        }
    }
};
```