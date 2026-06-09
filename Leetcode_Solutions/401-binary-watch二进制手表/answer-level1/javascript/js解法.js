
参考之前的解法
```
/**
 * @param {number} num
 * @return {string[]}
 */
var readBinaryWatch = function(num) {
    let res=[]
     //计算二进制中1的个数
    let count1=( n)=> {
        let res = 0;
        while (n != 0) {
            n = n & (n - 1);
            res++;
        }
        return res;
    }
    //直接遍历  0:00 -> 12:00   每个时间有多少1
    for (let i = 0; i < 12; i++) {
        for (let j = 0; j < 60; j++) {
            if (count1(i) + count1(j) == num) {
                res.push(String(i)+":"+(j < 10 ? "0"+String(j) : String(j)));
            }
        }
    }
    return res;
    
};
```
js版的回溯算法

```
/**
 * @param {number} num
 * @return {string[]}
 */
var readBinaryWatch = function(num) {
    let res=[]
    
    const DFS=(num,pos,time)=>{
        if(num==0){
            let hour= time[0] + 2 * time[1] + 4 * time[2] + 8 * time[3];
            let minute = time[4] + 2 * time[5] + 4 * time[6] + 8 * time[7] + 16 * time[8] + 32 * time[9];
             if (hour < 12 && minute < 60) {
                 
                res.push(hour+":"+(minute < 10 ? "0"+minute : minute));
            }
            return;
        }
        
        for (let i = pos; i <= 10 - num; i++) {
            time[i]++;
            DFS(num-1, i + 1, time);
            time[i]--;
        }
        
    }
    
    DFS(num,0,new Array(10).fill(0))
    
    return res
    
};
```
