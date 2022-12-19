### 解题思路
随机一个数，放到最后边，然后将小的放到最前面几个，递归完，再把最后一个放到一堆小的后边
查看这个值的index是不是和target一样，一样返回，不一样继续找

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
let arr;
let target;
var findKthLargest = function(nums, k) {
    arr = nums
    target = arr.length - k 

    let l = 0;
    let r = nums.length -1
    let v = radom(l, r)
  return v
};


var radom = function(l ,r){

    if(l ==r){return arr[l]}
    let randomValue = parseInt(Math.random()*(r -l),10)+l
    let tempIndex = quickSelect(l, r,randomValue)
    if(target == tempIndex){
       return arr[tempIndex]
    }else if(target > tempIndex){
        l = tempIndex +1
    }else if(target < tempIndex){
        r = tempIndex -1
    }
    return radom(l ,r)
}

var quickSelect = function(l ,r,a){

    if(l == r) {return arr[l]}
    let t = arr[a]
    let j = l;
    swap(a, r)

    for(let i = l; i<= r; i++){
        if(arr[i] < t){
            swap(i, j)
            j++
        }
    }
    swap(j,r)

  return j
}

var swap = function(a,b){
    let temp = arr[a]
    arr[a] = arr[b]
    arr[b] = temp 
}
```