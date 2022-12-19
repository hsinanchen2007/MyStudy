### 解题思路
 * obj对象 collect S
 * 查找出出现次数最多的字母
 * 剩下的字母依次按照空隙进行插入,重复此过程
 * 易错点1：未插满的空隙应该按顺序继续插入，否则会出现有空隙的case：'vvvlo'
 * 时间复杂度：
 * 空间复杂度：O(n)

### 代码

```javascript
const reorganizeString = S=>{
    let obj={},res='';
    for(let i=0;i<S.length;i++){
        if(obj[S[i]]>=0){
            obj[S[i]]++;
        }else{
            obj[S[i]]=1;
        }
    }
    // console.info(obj);
    const find=nums=>{
        let keys=Object.keys(obj);
        for(let i=0;i<keys.length;i++){
            if(obj[keys[i]]===nums){
                delete(obj[keys[i]]);
                return keys[i];
            }
        }
    };
    let temp=Object.values(obj).sort((a,b)=>a-b);
    // console.info(temp);
    let max=temp.pop();
    // 至少应该填满空格
    if(max-1>temp.reduce((sum,item)=>sum+item,0)){
        return '';
    }else{
        let i=1;
        res=find(max).repeat(max);
        res=res.split('');
        while(temp.length>0){
            let temp0=temp.pop();
            let a=find(temp0);
            // console.info('a',a,i);
            while(temp0>0){
                res.splice(i,0,a);
                i+=2;
                temp0--;
                if(i>res.length){
                    i=1;
                }
            }
        }
        res=res.join('');
        return res;
    }
};
```