
例子：cbacdcbc，答案是cb**acd**c**b**c

核心思路：当我们访问到第i个字符的时候，比如说cb的b时
1：它的前一个值重复，比它大就删除
2：当访问到acdc的c时，之前c已经定下来了，就直接跳过（你会发现需要这样一个visited数组去存放这个bool值）

c，可以
cb，b判断出c重复了，且bc比cb好，所以删除了c
ba，a判断出b重复了，且ab比ba好，所以删除了b
ac，可以
acd，可以
acdc，c判断出之前的c已经定好了，所以跳过
acdb，b判断出d不重复了，不能删
acdbc，c判断出之前c已经定好了，所以跳过
acdb，结束

```
class Solution {
public:
	string removeDuplicateLetters(string s) {
        vector<int> nums(128,0);
        vector<bool> visited(128, false);
        
        for(char c:s)
            nums[c] ++;
        string result = "0";
        
        for(char c:s)
        {
            nums[c] --;
            if(visited[c])
                continue;
            while( result.back() > c && nums[result.back()])
            {
                visited[result.back()] = false;
                result.pop_back();
            }
            result += c;
            visited[c] = true;
            
        }
        return result.substr(1);

	}
};
```
