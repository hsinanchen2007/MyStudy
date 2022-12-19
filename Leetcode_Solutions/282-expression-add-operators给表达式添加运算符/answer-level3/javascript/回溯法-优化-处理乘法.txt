## 回溯偏暴力版(超时)
 * 问题的解是一组，即解用向量表示,因此用回溯法来解决，并且观察其特征应该是排列树(确定n个元素是满足某种性质的排列
 * 以下是第一版代码。无法通过所有测试用例，原因实则是暴力遍历了所有可能结果，复杂度过高.
 * 主要思路是通过最初用eval判断结果是否为target，但是每次eval运算耗费时间较长，优势是代码极其简单清晰，且不用单独处理乘法。
```javascript
/*
 * @param {string} num
 * @param {number} target
 * @return {string[]}
 */
const addOperators = (num, target)=>{
    let res=[],ans=[];
    const findRes=(num0,k)=>{
        if(num0.length<1) return;
        let flag=(num0.length>1&&num0[0]!=='0')||(num0.length===1);
        if(flag&&eval(`${res.slice(0,k).join('')}${num0}`)===target){
            res[k]=num0;
            ans.push(res.slice(0,k+1).join(''));
        }else{
            for(let i=0;i<num0.length;i++){
                res[k]=num0.slice(0, i + 1);
                res[k+1]='+';
                findRes(num0.slice(i + 1), k+2);
                res[k+1]='-';
                findRes(num0.slice(i + 1), k+2);
                res[k+1]='*';
                findRes(num0.slice(i + 1),k+2);
                if(num0[0]==='0') break;
            }
        }
    };
    findRes(num,0);
    return ans;
};
```
## 回溯优化版
 * 合理降低暴力遍历的复杂度，暂存每次计算的val
 * 优化方案中关键一步是如何处理像1-2*3*4*5这种情况，其若从1-2*3*4过渡需要：``1-2*3*4-(-2*3*4)+(-2*3*4*5)``
 * 但在暴力求解的方法中通过校验最后一位加上后是否满足target的方式不容易取得pre即``2*3*4``的值
 * 因此转而改变思路：通过判断最终结果是否符合条件，而像上面例子中暂存的结果如何判断呢，此时会非常容易(私以为本思路相对于官方思路更加清晰
```javascript
/**
 * @param num
 * @param target
 * @returns {number}
 */
const addOperators2 = (num, target)=>{
    let res=[],ans=[];
    const backTrack=(num0,val,pre,k)=>{
        if(num0.length<1){
            if(val===target){
                ans.push(res.slice(0,k).join(''));
            }
            return;
        }
        for(let i=0;i<num0.length;i++){
            if(k===0){
                res[k]=(num0.slice(0,i+1));
                backTrack(num0.slice(i+1),Number(res[k]),Number(res[k]),k+1);
            }else{
                res[k]=('+');
                res[k+1]=num0.slice(0,i+1);
                backTrack(num0.slice(i+1),val+Number(res[k+1]),Number(res[k+1]),k+2);
                res[k]=('-');
                res[k+1]=num0.slice(0,i+1);
                backTrack(num0.slice(i+1),val-Number(res[k+1]),-Number(res[k+1]),k+2);
                res[k]=('*');
                res[k+1]=num0.slice(0,i+1);
                backTrack(num0.slice(i+1),val-pre+pre*Number(res[k+1]),pre*Number(res[k+1]),k+2);
            }
            if(num0[0]==='0') break;
        }
    };
    backTrack(num,0,0,0);
    return ans;
};
```
