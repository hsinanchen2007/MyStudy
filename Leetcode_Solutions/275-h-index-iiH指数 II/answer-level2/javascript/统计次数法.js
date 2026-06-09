```javascript
/**
 * 反而比leetcode-274 更加简单了
 * 时间复杂度:O(n)
 * 空间复杂度:O(1)
 * @param {number[]} citations
 * @return {number}
 */
const hIndex = citations=>{
    let res=0;
    for(let i=0;i<citations.length;i++){
        if(citations[i]>=citations.length-i){
            res++;
        }
    }
    return res;
};
/**
 * 计数排序
 * 时间复杂度:O(n)
 * 空间复杂度:O(n)
 * @param citations
 */
const hIndex1=citations=>{
    let temp=new Array(citations.length+1).fill(0);
    for(let i=0;i<citations.length;i++){
        if(citations[i]>citations.length-1){
            temp[citations.length]++;
        }else{
            temp[citations[i]]++;
        }
    }
    let sum=0;
    for(let i=citations.length;i>=0;i--){
        sum+=temp[i];
        if(sum>=i){
            return i;
        }
    }
};
```
