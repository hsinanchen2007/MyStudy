要点：
使用二进制映射数组元素出现的情况，1为出现，0为不出现，如 nums = [1,2,3]
000 => []
001 => [3]
010 => [2]
011 => [2,3]
100 => [1]
101 => [1,3]
110 => [1,2]
111 => [1,2,3]
```
var subsets = function(nums) {
    if(nums.length===0) return []
    let arr=[];
    let strMax=Array(nums.length).fill(1).join('');//得到满1的二进制数
    let len=parseInt(strMax,2);//循环次数为该二进制数对应的十进制
    let fill='000000000000000000000000000000000000000';  //二进制补0
    for(let i=0;i<len+1;i++){
        let str=(fill+i.toString(2)).slice(-nums.length); //二进制补0后裁剪
        let item=[];
        for(let j=0;j<nums.length;j++){  //循环二进制字符串，为1则计入数组
            if(str[j]==1){
                item.push(nums[j])
            }
        }
        arr.push(item)
    }
    return arr;
};
```
