列如    2     3      1      1     4
 pre    2  (2-1,3)(3-1,1)(2-1,1)(退出)  (a,b) a,b两者的最大值
没走一步,剩余量pre就减1,然后和当前的值比较,得出新的剩余量
``` 
  public boolean canJump(int[] nums) {
    	//只有1个或者0个
    	if(nums==null||nums.length<2)
    		return true;
    	//第一步就失败
    	if(nums[0]==0)
    		return false;
        int length=nums.length;
        //我们把pre作为遗留长度
        int pre=nums[0];
        //每一步可到达否?
        boolean flag[]=new boolean[length];
        //轮到处理元素的下标(未处理)
        int count=1;
        while(pre!=0&&count!=length) {//没有遗留并且没有到达最后一个
        	flag[count]=true;			//进来的剩余量pre总是大于0,走一步
        	pre=Math.max(pre-1,nums[count++]);	//更新遗留的步数
        }
        return flag[length-1];
}
```


```
