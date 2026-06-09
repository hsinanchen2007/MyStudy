### 解题思路
和官方题解的思路一致，JavaScript版实现

简单来说就是从数组末尾开始遍历，找到第一个左边比右边小的数a
将a与遍历过程中找到满足比a大但同时又是这些数中最小的那个数 交换 记录位置k
将 k之后的数字升序排列
如果没有找到a
直接升序排列整个数组
完事儿

中间写乱了，最后代码有点乱七八糟的，求轻喷

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var nextPermutation = function(nums) {
     if (nums.length===1){
        return nums;
    }
    var k=0;
    var tmp,c,d;
    var count=0;
    var flag=0;
    var min=Infinity;
    var mina=nums.length-1;
    var a=nums.length-1;
    var b=nums.length-2;

    while(b>=0){
        if (nums[b]<nums[a]){
            k=b
            c=b;
            flag=1;
            break
        }
        a--
        b--
    }
    for (let i=nums.length-1;i>c;i--){
        if (nums[i]>nums[k]){
            if (nums[i]<min){
                min=Math.min(min,nums[i])
                d=i;
            }
        }
    }
    if (c!==undefined){
        tmp=nums[k];
        nums[k]=nums[d];
        nums[d]=tmp;
    }
    

    for (let i=nums.length;i>k+1;i--){
        for (let j=i;j>k;j--){
            if (nums[j]>nums[i]){
                tmp=nums[j];
                nums[j]=nums[i];
                nums[i]=tmp;
            }
        }
    }
    if (flag===0){
        nums.sort((a,b)=>(a-b))
        return nums;
    }
   
    return nums
    
};


```