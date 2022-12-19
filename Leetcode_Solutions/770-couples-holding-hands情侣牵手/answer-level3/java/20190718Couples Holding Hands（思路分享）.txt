# **一、解题思路：**

其实我们最想要的也许就是“0,2,4,7,9,6,5,8,3,1”中的“0,2,3,1”这种只用**换一次位置就能使两对一起成立**的关系。

 但其实，无论哪一种都可以通过**固定偶数位的元素，偶数位下一个元素换成相配的**去实现。

也因此，可能不明不白就AC了，我自己都不懂，它懂了。

这里有张图可以看一下：

![0062a4b905cdd6374f988778404530e.jpg](https://pic.leetcode-cn.com/1624826c03820dcb6708310e5845d0fc62a49abfb4a8076511a1904b79879fbf-0062a4b905cdd6374f988778404530e.jpg)


# 二、算法实现及思路解析:

```
public int search(int i,int[] row)//传入row的下标i
{
	for(int k = 0; k < row.length; k++)//遍历搜寻与row[i]相对应的数
	{
		if(row[i]%2==1)//当row[i]是奇数
		{
			if(row[k]==row[i]-1)//那么与之相对应的便是“它-1”,即我们要搜寻的那个数
			{
				return k;//返回对应元素的下标
			}
		}
		else//当row[i]是偶数
		{
			if(row[k]==row[i]+1)//那么与之相对应的便是“它+1”,即我们要搜寻的那个数
			{
				return k;//返回对应元素的下标
			}
		}
	}
	
	return -1;
}

public int minSwapsCouples(int[] row) {
	int cut = 0;//计数器
	
	for(int i = 0; i < row.length; i+=2)//固定偶数位，为每个尚未配对的偶数位寻找对应的元素
	{
		if(row[i]%2==1 && row[i]-1==row[i+1] || row[i]%2==0 && row[i]+1==row[i+1])
		{
			continue;//配对的话，就跳过当前这一个偶数位，到下一个偶数位。
		}
		else//不配对的话，就要先用search函数找到对应元素的下标，然后进行交换。
		{
			int t = search(i,row);
				
			int temp = row[i+1];
			row[i+1] = row[t];
			row[t] = temp;
			cut ++;  			//计数器+1
		}
	}
	return cut;
}
```

我看到别人的“打表做法”了，用一个数组去记录各个数字的所在的下标，然后不断更新这张表，以减少寻找的时间。好厉害O(∩_∩)O~

感 谢 遇 见 ！