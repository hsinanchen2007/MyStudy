### 解题思路
双指针法参考自剑指offer，思路见图
![image.png](https://pic.leetcode-cn.com/0be4fffc24ca7aa6c3631f3eab4181368d2848489920409595ac8b7b76f50887-image.png)


### 代码

```cpp
/*双指针法*/
class Solution {
public:
	string replaceSpace(string s) {
		if (s.size()==0)//特判
		{
			return "";
		}
		int len1 = s.size();
		int count = 0;
		for (int i = 0; i < len1; i++)
		{
			if (s[i]==' ')
			{
				count++;
			}
		}
		int p1 = len1-1, p2 = len1 + count * 2-1;//p1指向原始字符串的最后一个字符，p2指向新字符串的最后一个字符
		string temp(count * 2, ' ');
		s += temp;
		while (p1!=p2)//两者未相遇
		{
			if (s[p1]==' ')//为空格
			{
				p1--;//p1先移动一位
				for (int i=0;i<3;i++)//p2移动3三位，并增加字符串%20
				{
					if (i==0)
					{
						s[p2--] = '0';
					}
					else if(i==1)
					{
						s[p2--] = '2';
					}
					else 
					{
						s[p2--] = '%';
					}
					
				}
			}
			else {//不为空格，则后移
				s[p2--] = s[p1--];
			}
		}
		return s;
	}
};


/*利用find,replace函数,写法简单，思路清晰*/
class Solution {
public:
	string replaceSpace(string s) {
		string::size_type pos;
		while (true)
		{
			if ((pos=s.find(" "))!=string::npos)//find每次找到出现的第一个空格，如果能找到空格，则将其替换
			s.replace(pos, 1, "%20");
			else break;
			
		}
		return s;
	}
};
```