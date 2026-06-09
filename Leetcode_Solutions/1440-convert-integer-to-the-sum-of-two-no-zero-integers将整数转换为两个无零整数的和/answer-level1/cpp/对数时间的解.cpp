哎呀不好意思，这儿是比赛的时候写的代码，比较匆忙所以。。没怎么注释。。。
因为时间问题无法细致地剖析其中细节。
大体的思路就是把n一位一位地压入两个栈（用的int来代替）然后再从栈中取出即可。
![llll.png](https://pic.leetcode-cn.com/c752cded2e1d1ac268cb2655e2246cec519db047ad58988d47aa869bcb380ecd-llll.png)

```
class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
    int A=0,B=0;
	int temp=0,tem = 0;
    tem++;
    n--;
	while(n>0)     //从个位开始处理  每次都保证push进AB的数字不含0  且他们颠倒后的数字之和为n
	{
		if(n%10)
		{
			temp = temp*10;
			temp += n %10;
			n = n / 10;
            if(n>0) {
                n--;
                tem*=10;
                tem++;
            }
		}
        else
		{
		    n--;
            tem++;
            temp = temp*10;
		    temp += n %10;
		    n = n / 10;
            if(n>0) {
                n--;
                tem*=10;
                tem++;
            }
		}
	}
	//最后再将AB两个数颠倒回来
	while(temp)   
	{
		B*=10;
		B+=temp%10;
		temp /=10;
	}
    while(tem)
    {
            A*=10;
            A+=tem%10;
            tem /=10;
    }
        
		return {A,B};
    }
};
```
