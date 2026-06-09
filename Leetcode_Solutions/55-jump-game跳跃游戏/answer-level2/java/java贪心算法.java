**思路一：贪心算法** NO.45跳跃游戏II的姊妹题，思路一样可以结合学习，题解参考[徒手挖地球二三周目](https://blog.csdn.net/qq_42758551/article/details/104562003)。

每次都在本次跳跃范围内找到下一跳最远的位置。如果最后最远的都为都不能到结尾，则false。

```java
public boolean canJump(int[] nums) {
    if (nums==null||nums.length==0)return true;
    //end当前跳跃范围，maxPosition记录当前跳跃范围内下一跳最远的位置
    int end=0,maxPosition=0;
    for (int i = 0; i < nums.length-1; i++) {
        //记录当前范围内下一跳最远的位置
        maxPosition=Math.max(maxPosition,nums[i]+i);
        //走到当前跳跃最远点
        if (i==end){
            //跳到最远的位置
            end=maxPosition;
        }
    }
    return end>=nums.length-1;
}
```

时间复杂度：O(n)


---

本人菜鸟，有错误请告知，感激不尽！

更多题解和学习记录博客:[博客](https://blog.csdn.net/qq_42758551)**、**[github](https://jerrymouse1998.github.io/) 