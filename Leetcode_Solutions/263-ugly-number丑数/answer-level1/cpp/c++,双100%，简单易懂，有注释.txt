### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isUgly(int num) 
    {
        if(num == 0 ) return false;
        while(num%2 == 0 || num%3 == 0 || num%5 == 0)   
		//判断该数时候能被2 3 5整除，能整除说明还不是最小值（该值不等于1）
		//如果不能整除就不成立，该数不是丑数
		//如果整除到最后num=1，就是丑数。
		{
			if(num%2 == 0)
				num = num/2;
			else if(num%3 == 0)
				num = num/3;
			else if(num%5 == 0)
				num = num/5;
		}
		if(num == 1)
			return true;
		else
			return false;

    }
};
```