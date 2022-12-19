![Annotation 2019-11-24 165155.jpg](https://pic.leetcode-cn.com/0bf90db70e9f32fa0aa1864b5c0d48766081044e57af68e70ff43e5ef4009e74-Annotation%202019-11-24%20165155.jpg)
```
var permuteUnique = function(nums) {
    nums.sort((a,b)=>a-b)
    console.log(nums)
    var result=[],used=[]
    callBack(nums,[],result,used,0)
    return result;

};
function callBack(nums,temp,result,used,depth){
    if(depth==nums.length){
        result.push(temp.slice());
        return;
    }else{
        depth++
    }
    for(var i=0,cursor=1;i<nums.length;){
        if(nums[cursor]==nums[i]){
            cursor++;
        }
        else{
             if(!used[i]){
                used[i]=true;
                temp.push(nums[i]);
                arguments.callee(nums,temp,result,used,depth);
                temp.pop();
                used[i]=false;
                i=cursor;
                cursor++
        }else{
            i++;
        }
        }
    }
}

```

