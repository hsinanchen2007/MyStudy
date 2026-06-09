思路：如果我们可以从i点到达j点，那么到达j点这个问题就可以分解为如何到达i点，这样就实现了问题的分解

代码如下：
```
public boolean canJump(int[] nums) {
    if (nums.length==1){
        return true;
    }
    return goBack(nums,nums.length-1);
}
public boolean goBack(int[] nums,int length){
    for (int i = length-1; i >=-1 ; i--) {
        //这个是最后取不到结果，迭代终止
        if (i==-1){
            return false;
        }
        if (i+nums[i]>=length){
            //取到结果，迭代终止
            if(i==0){
                return true;
            }
            return goBack(nums,i);
        }
    }
    return false;
}
```

