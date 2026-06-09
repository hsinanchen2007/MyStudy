### 解题思路
先判断连续的两个字母是否是特例，如果是则跳出循环，从两个字母后继续比较，如果不是则一个一个字母叠加，注意此时必须比较到length-2,否则会造成数组越界。最后一个字母单独判断

### 代码

```java
class Solution {
    public int romanToInt(String s) {
        
		char [] array = s.toCharArray();
		int length = array.length;
		int i=0,sum=0;
		//长度问题如何解决
		for(i=0;i<length-1;i++ )
		{
			
				
				if(array[i]=='I'&&array[i+1]=='V')
				{
					i++;
					sum+=4;
					continue;
				}
				if(array[i]=='I'&&array[i+1]=='X')
				{
					i++;
					sum+=9;
					continue;
				}
				if(array[i]=='X'&&array[i+1]=='L')
				{
					i++;
					sum+=40;
					continue;
				}
				if(array[i]=='X'&&array[i+1]=='C')
				{
					i++;
					sum+=90;
					continue;
				}
				if(array[i]=='C'&&array[i+1]=='D')
				{
					i++;
					sum+=400;
					continue;
				}
				if(array[i]=='C'&&array[i+1]=='M')
				{
					i++;
					sum+=900;
					continue;
				}
			
				
				if(array[i]=='I')
				{
					sum+=1;
				}
				if(array[i]=='V')
				{
					sum+=5;
				}
				if(array[i]=='X')
				{
					sum+=10;
				}
				if(array[i]=='L')
				{
					sum+=50;
				}
				if(array[i]=='C')
				{
					sum+=100;
				}
				if(array[i]=='D')
				{
					sum+=500;
				}
				if(array[i]=='M')
				{
					sum+=1000;
				}
				
		}
		if(i==length)
		{
			return sum;
		}
		else {
			if(array[i]=='I')
			{
				sum+=1;
			}
			if(array[i]=='V')
			{
				sum+=5;
			}
			if(array[i]=='X')
			{
				sum+=10;
			}
			if(array[i]=='L')
			{
				sum+=50;
			}
			if(array[i]=='C')
			{
				sum+=100;
			}
			if(array[i]=='D')
			{
				sum+=500;
			}
			if(array[i]=='M')
			{
				sum+=1000;
			}
			return sum;
		}
    }
}
```