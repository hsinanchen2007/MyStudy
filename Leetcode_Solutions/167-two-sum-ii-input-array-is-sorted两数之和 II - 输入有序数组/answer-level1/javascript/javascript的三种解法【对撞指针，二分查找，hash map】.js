解法一：二分查找
```
var twoSum=function(numbers,target){
    for(let i=0;i<numbers.length;i++){
        let other=target-numbers[i]
        let res=binarySearch(numbers,other)
        if(res!=-1&&i!=res){
            return i<res?[i+1,res+1]:[res+1,i+1]
        }
    }
    return []
}
const binarySearch = function(numbers, target) {
    let high=numbers.length
    let low=0
    while(low<=high){
        let mid=parseInt((low+high)/2)
        if(numbers[mid]===target){
           return mid
        }else if(numbers[mid]<target){
            low=mid+1
        }else{
            high=mid-1
        }
    }
    return -1
};
```

解法二：对撞指针【目测最佳】
```
var twoSum = function(numbers, target) {
    let len=numbers.length
    if(len<2) return []
    //对撞指针
    let left=0;
    let right=len-1
    while(left<right){
        if(numbers[left]+numbers[right]===target){
            return [left+1,right+1]
        }
        else if(numbers[left]+numbers[right]<target){
            left++
        }else{
            right--
        }
       
    }
    return []
};
```
解法三：哈希表
var twoSum=function(numbers,target){
    let hashmap=new Map()
    for(let item in numbers){
        hashmap.set(numbers[item],item)
    }
    for(let i=0;i<numbers.length;i++){
        if(hashmap.has(target-numbers[i])){
            return [i+1,parseInt(hashmap.get(target-numbers[i]))+1]
        }
    }
    return []
};