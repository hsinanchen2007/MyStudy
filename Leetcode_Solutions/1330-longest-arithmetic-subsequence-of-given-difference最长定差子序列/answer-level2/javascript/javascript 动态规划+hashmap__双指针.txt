方法一：双指针
```
var longestSubsequence = function(arr, difference) {
 let max_len=1
 let isFind=false
 for(let left=0;left<arr.length;left++){
     let temp=1
     let mid=left
     do{
         isFind=false
         for(let right=mid+1;right<arr.length&&!isFind;right++){
           if(arr[right]-arr[mid]===difference){
               mid=right
               isFind=true
               temp++
               max_len=Math.max(max_len,temp)
           }
         }
     }while(mid<arr.length&&isFind)
          
 }
   
 return max_len
};
```

方法二：动态规划+hashmap
```
var longestSubsequence = function(arr, difference) {
    if(arr.length===0)return 0
    let hashmap=new Map()
    let ans=1
    for(let v of arr){
        if(!hashmap.has(v-difference)){
            hashmap.set(v,1)
        }else{
            let len=hashmap.get(v-difference)+1
            ans=Math.max(len,ans)
            hashmap.set(v,len)
        }
    }
    return ans
};
```
