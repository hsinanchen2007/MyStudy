### 解题思路
此处撰写解题思路
时间，内存击败100%的人，将z性数组分组，假设num为4，就以3分组，然后按行找规律。
### 代码

```cpp
class Solution {
public:
    string convert(string s, int numRows) {
    char str[1000];
	int cmp=0,j,flag;
	for(int i=0;i<numRows;i++)
		{
			j = i;
			flag = 0;
			if(j==0||j==numRows-1)
			{
				flag = 1;
			}
			while(j<s.length())
			{
				if(flag==1)
				{
					str[cmp++] = s[j];
                    if(numRows==1)  //边界情况
                    j+=1;
                    else
					j+=2*(numRows-1); //第一排和最后一排特殊处理
				}else
				{
					str[cmp++] = s[j];
					int kk = numRows-1 - j%(numRows-1)*2;  //这里是一个中心对称的计算 
					j+=numRows-1+kk;
				}
			}
		}
		str[cmp] = '\0';
        string str1 = str;
		return str1; 
    }
};
```