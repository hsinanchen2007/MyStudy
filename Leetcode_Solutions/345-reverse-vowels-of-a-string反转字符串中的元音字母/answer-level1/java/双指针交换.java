算法思想为：设定第一个指针start指向数组的初始位置，第二个指针end指向数组的结束位置。先让start进行循环遍历，找寻到从数组开始的第一个元音字符，然后在让第二个指针end寻找最后一个元音字符，在对这两个字符进行替换。（类似的算法思想也可以用于实现快速排序）
```
public String reverseVowels(String s) {
		StringBuilder s1 = new StringBuilder(s);
		int start = 0;
		int end = s1.length()-1;
		while(start <= end)
		{
			while(start <=end)   //寻找start位置上的元音字符
			{
				char charflag = s1.charAt(start);		
				if(charflag == 'a' || charflag == 'e' || charflag == 'i' || charflag == 'o' || charflag == 'u' ||charflag == 'A' || charflag == 'E' || charflag == 'I' || charflag == 'O' || charflag == 'U'  ) 
					break;
				start+=1;
			}
			while(end >=start)  //寻找end位置上的元音字符
			{
				char charflag2 = s1.charAt(end);
				if(charflag2 == 'a' || charflag2 == 'e' || charflag2 == 'i' || charflag2 == 'o' || charflag2 == 'u' ||charflag2 == 'A' || charflag2 == 'E' || charflag2 == 'I' || charflag2 == 'O' || charflag2 == 'U'  ) 
					break;
				end--;
			}
			//互换
			if(start < end)
			{
				char temp = s1.charAt(start);
				s1.setCharAt(start, s1.charAt(end));
				s1.setCharAt(end, temp);
			}
			
			start+=1;
			end-=1;
		}
	    return s1.toString();
	}
```