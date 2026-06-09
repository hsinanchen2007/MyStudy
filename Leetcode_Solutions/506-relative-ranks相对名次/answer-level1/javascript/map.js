### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {string[]}
 */
var findRelativeRanks = function(nums) {
    var map1=new Map()
    var num2=nums.slice(0);//注意这里复制数组的方法，不能直接num2=nums，否则会改变原数组
    num2.sort((a,b)=>b-a);
    var arr=["Gold Medal", "Silver Medal", "Bronze Medal"]
    for(var i=0;i<num2.length;i++){
        if(i==0){
            map1.set(num2[i],arr[0]);
        }
        if(i==1){
            map1.set(num2[i],arr[1]);
        }
        if(i==2){
            map1.set(num2[i],arr[2]);
        }
        if(i>2){
            map1.set(num2[i],(i+1).toString());
        }
    }
    var arr=[];
    for(var i=0;i<nums.length;i++){
        arr.push(map1.get(nums[i]))
    }
    return arr;
};
```