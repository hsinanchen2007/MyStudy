- 把所有数加起来和为sum，总的字符串降序排序，然后sum%3，看余数
- 等于0，直接返回
- 等于1，优先删除1个`1 or 4 or 7`，没有的话，删除`2,5,8`中最小的2个
- 等于2，优先删除1个`2 or 5 or 8`，没有的话，删除`1,4,7`中最小的2个
```cpp
class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
    	int count[10] = {0}, i, sum = 0, time;
    	string ans;	
    	for(i = 0; i < digits.size(); ++i)
    	{
    		count[digits[i]]++;//计数
    		sum += digits[i];//总和
    		ans += digits[i]+'0';//字符串
    	}
    	sort(ans.begin(), ans.end(),[](char& a, char& b){return a > b;});
		if(sum%3 == 1)
    	{
    		i = ans.size()-1;
    		if(count[1]!=0||count[4]!=0||count[7]!=0)
    		{
    			for( ; i>=0; --i)
	    		{
	    			if(ans[i]=='1'||ans[i]=='4'||ans[i]=='7')
	    			{
	    				ans.erase(ans.begin()+i);
	    				break;
	    			}
	    		}
    		}
    		else
    		{	
    			time = 2;
    			for( ; i>=0; --i)
    			{
    				if(ans[i]=='2'||ans[i]=='5'||ans[i]=='8')
	    			{
	    				ans.erase(ans.begin()+i);
	    				time--;
	    				if(time == 0)
	    					break;
	    			}
    			}
    		}
    	}
    	else if(sum%3 == 2)
    	{
    		i = ans.size()-1;
    		if(count[2]!=0||count[5]!=0||count[8]!=0)
    		{
    			for( ; i>=0; --i)
	    		{
	    			if(ans[i]=='2'||ans[i]=='5'||ans[i]=='8')
	    			{
	    				ans.erase(ans.begin()+i);
	    				break;
	    			}
	    		}
    		}
    		else
    		{	
    			time = 2;
    			for( ; i>=0; --i)
    			{
    				if(ans[i]=='1'||ans[i]=='4'||ans[i]=='7')
	    			{
	    				ans.erase(ans.begin()+i);
	    				time--;
	    				if(time == 0)
	    					break;
	    			}
    			}
    		}
		}
		if(ans != "" && ans[0]=='0')
			return "0";
		return ans;
	}
};
```