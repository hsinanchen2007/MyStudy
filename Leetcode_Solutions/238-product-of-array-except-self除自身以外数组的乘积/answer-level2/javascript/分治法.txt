- __基本思路__：将数组分成两个部分，左半部分的元素依次乘上右半部分所有元素之积，以此类推，右半部分的元素依次乘上左半部分所有元素之积，即得到答案。

- __分治法的使用__：将数组不断对半划分，直到单个元素，然后再两两进行上述基本思路的操作，最终得到答案。

```
var productExceptSelf = function(nums) {
    if(nums.length == 0) return nums;
    let res = new Array(nums.length);           //用来保存结果的数组
    res.fill(1);
    
    let merge = (mul1, mul2, l, r, mid)=>{     //左右两个部分的数组相互作积，并返回当前区域数组的积
        for(let i = l; i <= mid; i++){
            res[i] = res[i]*mul2;
        }
        for(let j = mid+1; j <= r; j++){
            res[j] = res[j]*mul1;
        }
        return mul1*mul2;
    }
    
    let partation = (l, r)=>{                  //划分数组，返回当前区域数组的积
        if(l == r){
            return nums[l];
        }
        let mid = Math.floor((l+r)/2);
        return merge(partation(l, mid), partation(mid+1, r), l, r, mid);     //递归调用划分函数
    }
    
    partation(0, nums.length-1);
    
    return res;
};
```