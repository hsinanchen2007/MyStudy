### 解题思路

我真是太菜了，大佬们凑合看看吧

### 代码

```cpp
class Solution {
public:
    int reverse(int x) {
		vector<int>	a;
		if(x<=(pow(2,31)-1)&&x>=pow(-2,31))
		{}
		else
		return 0;
        if(x==0)
        return 0;
        if(x==pow(-2,31))
        x=x+1;
		bool signal;
		if(x<0)
		{
		signal=false;
		x=abs(x);
		}
		else
		signal=true;
		while(x/10!=0||x%10!=0)
		{
			a.push_back(x%10);
			x=x/10;
		}
		long int b=0,i=1;
		auto it=a.end();
		for(it--;it>=a.begin();it--)
		{
			b+=(*it)*i;
			i*=10;
		}
        i=i/10;it++;
        if(x==pow(-2,31))
        b=b+i;
        if(b>(pow(2,31)-1))
        return 0;
        if(signal==false)
		return 0-b;
        else
        return b;
    }
};
```