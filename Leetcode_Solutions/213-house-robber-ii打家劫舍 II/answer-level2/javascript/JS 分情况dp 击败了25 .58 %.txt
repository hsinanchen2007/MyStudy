第一种想法就是根据题目1，对第一家是否进行偷盗进行分情况讨论，如果进行偷盗，则不计算最后一家，否则常规计算。    
执行用时 : 88 ms, 在House Robber II的JavaScript提交中击败了79.07% 的用户    
内存消耗 : 33.4 MB, 在House Robber II的JavaScript提交中击败了83.87% 的用户   
这个运行时间影响情况挺多的，有时候多console了一个变量或者变量声明的位置都有影响
```
// 就是对第一家是否偷盗进行一个判断，然后两种情况分别进行dp
/**
 * @param {number[]} nums
 * @return {number}
 */
var rob = function(nums) {
    let l = nums.length;
    if(!nums||l==0)
    {return 0}
    if(l==1||l==2){
        return Math.max(...nums)
    }
    //偷第一家的情况
    temp1 = new Array(l).fill(0),
        temp2 = new Array(l).fill(0);
    temp1[0]=nums[0]
    temp1[1]=Math.max(nums[0],nums[1]);
    //不偷第一家的情况
    temp2[1]=nums[1];
    // console.log(temp1,temp2)
    for(let i = 2;i<l;i++)
        {
            temp2[i]=Math.max(temp2[i-1],temp2[i-2]+nums[i])
        }
    for(let i = 2;i<l-1;i++)
        {
           temp1[i]=Math.max(temp1[i-1],temp1[i-2]+nums[i])
        }
    // console.log(temp1,temp2)
    return Math.max(temp1[l-2],temp2[l-1])
};
```