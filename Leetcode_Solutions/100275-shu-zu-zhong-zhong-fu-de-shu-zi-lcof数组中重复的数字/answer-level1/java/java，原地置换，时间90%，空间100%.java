![image.png](https://pic.leetcode-cn.com/712e07a93092ad2d0e453f6d22ec9abae647f6f2b43222a341041747c74ca757-image.png)


**把对应元素下标取反，作为标记**，就是核心思想。
题目说了，数字范围都在0~n-1的范围内，所以不用担心越界。

但是对于0，我们处理起来有点麻烦，因为我们判断重复数据的条件：
**该下标对应的元素值为负数**，证明已标记过，就完成了查找了。

但对于0，我们取反是没有意义的。但如果你要额外去判断它，又会比较麻烦。
所以我们可以先预处理：**把所有元素值都加一**，这样我们的值就对应 1~n，取反也顺利得多了。

然后我们再修改一下判断条件：
 int mark = Math.abs(nums[i])-1;  
 if(nums[mark]<0)，就等价回我们第i位对应i了。

代码如下：
```
public int findRepeatNumber(int[] nums) {
        for(int i=0;i<nums.length;i++){
           nums[i]++;  //预处理，避开对于0的判断
        }

        for(int i=0;i<nums.length;i++){
            int mark = Math.abs(nums[i])-1;   //注意此处是先对值取绝对值再-1，而不是-1再取绝对值
            if(nums[mark]<0){     //若该位值已为负数，证明已被标记过
                return mark;      //即该位就是重复元素
            }else{
                nums[mark] *=-1;    //标记它
            }
        }
        return -1;   
    }
```

时间复杂度O（n）
空间复杂度O（1）
