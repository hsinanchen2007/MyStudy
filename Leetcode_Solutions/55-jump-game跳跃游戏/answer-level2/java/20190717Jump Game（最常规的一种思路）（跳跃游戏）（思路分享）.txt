# **一、解题思路：**
怎么寻找下一个位置呢？
题目给出我们在第一个位置，问我们能否走到最后一个位置。我第一眼看到题目，我能想到的就是我该如何去寻找我的下一个位置。

### **下一个位置必须能够让我们走得更远！**


# **二、算法实现及思路解析**（效率也不低，2 小时前	通过	3 ms	42.9 MB	Java）

```
    public static boolean canJump(int[] nums) {
        int i = 0,j = -1;
    	while(i<nums.length-1 && i!=j)//两个停止情况:走到最后一个位置了;遇到走不过去的“0”了;
    	{
    		j = i;
    		i = search(i,nums[i],nums);//走到下一个位置
    	}
    	
    	return i>=nums.length-1?true:false;//判断
    }
	
    //用下面这个函数去寻找我的下一个位置
    public static int search(int i,int j,int[] num)//i为我所在的位置，j为我所能走的距离。
    {
	int t  = 0;
	if(i + j <  num.length - 1)
	{
		t = i + j;//到不了的话，就用t记录下能到达的最远位置，然后一个个去比较，看哪个合适。
	}
	else//如果能够达到最后一个位置，或者再往后，那么想都不用想，直接返回最后一个位置。
	{
		return num.length - 1;
	}
	
	for(int k = i + 1; k <= i + j && k <= num.length - 1; k++)//从我所在位置的下一个位置开始走
	{
	//一般我们更想走得更远，会选最远的那个位置，除非中间有一个位置，能够使我走得比最远还要远。
//这样的位置必须满足两个条件。1、使我走得比最远还远。2、在可能存在多个这样的点中，它是最强大的那一个。
	//用t去记录最强的那一个，初始化t为最后一个。
		if(k + num[k] >= i + j && k + num[k]>=num[t] + t)
		{
			t = k;
		}
	}	
		return t;	//简而言之，我们每一次选择距离与潜在距离最远的那一个。
    }
```



# **三、跳跃游戏II**

加个计数器“cut”并返回即可，效率也不低。（2 小时前	通过	1 ms	37.6 MB	Java）
```
    public static int jump(int[] nums) {
        int i = 0,j = -1,cut = 0;
    	while(i<nums.length-1 && i!=j)//两个停止情况:走到最后一个位置了。遇到走不过去的“0”了。
    	{
    		j = i;
    		i = search(i,nums[i],nums);//走到下一个位置
    		cut++;
    	}
    	
    	return cut;//判断
    }
```


感 谢 遇 见 ！