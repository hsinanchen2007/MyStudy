**一、解题思路：**

 1、为了寻求一般解，我先代入了几组数据，试图寻找求解规律。
	下图为当k=1，k=2，k=3时，移除哪k个数能使剩下的值最小。
![image.png](https://pic.leetcode-cn.com/c7faff9e76b866a56a14d09ede113b9c1dc5f837e117e57f943c2e2c968158d0-image.png)

2、（运气不错）我们**从左往右比较，当 [i]>[i+1] 那就说明这个数（[i]）需要移除**，这就是我们想要的规律。

3、当然，还有不可忽视的临界情况。

**二、算法实现及思路解析（先看有注释的部分）：**

```
       	char[] str = num.toCharArray();//首先，我们将num转化成字符数组
    	int length = num.length();	//用length去记录移除k个数后返回字符串的长度。
	//也许你会有疑问“返回的字符串长度不就是 num.length - k 吗？”
    	
    	if(k==0)
    	{
    		return num;
    	}
    	
    	if(k==num.length())
    	{
    		return "0";
    	}
    	
    	while(k!=0)//核心部分,删除k个数，理论上循环k次。
    	{
    		int i;
    		int flag = 1;
    		for(i = 0; i < str.length - 1; i++)//从左往右
    		{
    			if((int)str[i]>(int)str[i+1])//左边比右边大
    			{
    				for(int t = i; t < str.length - 1; t++)
    				{//这个循环代表，删除数组中的一个元素。
    					str[t] = str[t+1];
    				}
    				flag = 0;
    				length--;//删除之后，返回的长度-1，k-1，跳出for循环
    				k--;
    				break;
    			}
    		}
			if(flag == 1 && k!=0)//如果找了一圈没有任何移除，即flag为1，但k有余量时
			{			
				length--;	//那说明最后一个>=倒数第二个		
				k--;	//所以length--，k--.（length--相当于删除了。。。往下看）
			}
    	}
    	
    	boolean cut = true;
    	while(cut)
    	{
    		cut = false;
    		if(str[0]=='0'&&length!=1)
    		{
    			cut = true;
    			for(int t = 0; t < str.length - 1 ; t++)
    			{
    				str[t] = str[t+1];
    			}
    			length--;
    		}
    		
    	}
    	 	
    	char[] pre = new char[length];//建立一个新数组,去记录0到length-1
    	for(int i = 0; i < length; i++)//这也就是为什么上面length--相当于删除的原因了
    	{	
    		pre[i] = str[i];
    	}

	return String.valueOf(pre);//返回这个新的数组
```
**三、临界情况分析：**

```
    	if(k==0)//k为0就是什么都不删除
    	{
    		return num;
    	}

	
	```
	示例3：
	输入: num = "10", k = 2
	输出: "0"
	解释: 从原数字移除所有的数字，剩余为空就是0。
	```
    	if(k==num.length())//正如示例:3所示，当刚好删除完的时候，不是返回“空”，而是“0”;
    	{
    		return "0";
    	}
    	
	```
	示例 2 :

	输入: num = "10200", k = 1
	输出: "200"
	解释: 移掉首位的 1 剩下的数字为 200. 注意输出不能有任何前导零。
	```
	boolean cut = true;//正如示例2所示，不能有任何的前缀0.
	while(cut)
	{
		cut = false;//如果接下来没有发生前缀为0，也就不必再判断前缀是否为0.
		if(str[0]=='0'&&length!=1)//第二个条件针对“num=10，k=1”这类情况。
		{
			cut = true;//但如果发生了前缀为0，那么我们还需要再次循环。例如（num=700200003，k=2这类情况.
			for(int t = 0; t < str.length - 1 ; t++)
			{
				str[t] = str[t+1];
			}
			length--;
		}	
	}
```
##### **感 谢 遇 见 ！**