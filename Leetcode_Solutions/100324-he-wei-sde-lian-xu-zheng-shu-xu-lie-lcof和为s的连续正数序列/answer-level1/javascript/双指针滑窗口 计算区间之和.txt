
双指针滑窗口 找区间之和等于target的。 然后循环拼装区间之内的元素。
区间之和=首尾相加✖️个数➗2

```
var findContinuousSequence = function(target) {
    let current_sum = 0;
    let res = [];
    let left=1,right=2;
    while(right<target){
        current_sum = add(left,right);
        if(current_sum < target){
            right++;
        }else if(current_sum == target){
            res.push(change_arr(left,right));
            left++; right=left+1;
        }else{ //current_sum > target
            left++; right=left+1;
        }
    }
    
    function add(left,right){ // 计算和
        return (right+left)*(right-left+1)/2
    }
    
    function change_arr(left,right){ //拼装区间内数组
        let r_arr= [];
        for(let k=left;k<=right;k++){
            r_arr.push(k)
        }
        return r_arr
    }
    return res;
};
```
