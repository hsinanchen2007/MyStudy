### 解题思路
效率不高，但是是一种比较容易理解的方法。
 * 1。要找到字典序靠前的且能囊括所有出现的字母的那个最初索引位置
 * 2。进行递归实现对剩下的字母进行检查出最靠前的那个字母
 * 3。重复过程2

### 代码

```javascript
const removeDuplicateLetters = (s)=>{
    const helper=s=>{
        if(s.length===1) return [s];
        if(s.length===0) return [];
        let s0=s.split('');
        s=s.split('');
        s0=[...new Set(s0.sort())];
        let min=0,flag=true;
        for(let i=0;i<s0.length-1;i++){
            flag=true;
            let idx=s.indexOf(s0[i]);
            // console.info('===>',idx,s0[i],s.slice(idx));
            for(let j=0;j<s0.length;j++){
                if(s.slice(idx).indexOf(s0[j])===-1){
                    flag=false;
                    break;
                }
            }
            if(flag){
                min=idx;
                break;
            }
        }
        // console.info(min,flag);
        if(!flag) min=s.indexOf(s0[s0.length-1]);
        let temp=s[min];
        s=s.slice(min+1);
        for(let i=0;i<s.length;i++){
            if(s[i]===temp){
                s.splice(i,1);
                i--;
            }
        }
        // console.info(temp,s,s0);
        return [temp].concat(helper(s.join('')));
    };
    return helper(s).join('');

};
```