### 解题思路
![图片1.png](https://pic.leetcode-cn.com/b34db520be08240733259e75de99ce723d4e5c6757b17e6d35ddb594172c2633-%E5%9B%BE%E7%89%871.png)
注意特殊情况，一个value被多个key匹配，
我这里的解决办法是专门引入一个map记录一下不同value的出现次数
若value 的出现次数大于1，就false
实例为：当为"abba"  "dog dog dog dog"时的判断

字符串拆分也是一个比较基础的考验，建议像我一样的新手一定要自己写一遍，当然也有更优的解法！

### 代码

```cpp
class Solution {
private:

    //拆分字符串
    vector<string> SplitStr(string str)
    {
        vector<string> returnVec;
        //双指针，滑动窗口
        int left = 0;
        int right=1;

        while(str[right]!='\0') //到了末尾
        {
            if(str[right]==' ')//到了空格
            {
                //substr这个接口的两个参数是（起点，长度）
                returnVec.push_back(str.substr(left, right-left));
                //窗口右移
                left = right+1;
                right = left;
            }
            right++;
        }
        returnVec.push_back(str.substr(left, right-left));
        return returnVec;
    }
public:
    bool wordPattern(string pattern, string str) {
        vector<string> splitStr = SplitStr(str);
        //如果长度不符合，直接返回false
        if(pattern.size()!= splitStr.size())
            return false;        
        map<char,string> record; //存字符和字符串的键值对
        map<string,int> valueTimes; //记录不同的值出现的次数
        for(int i=0;i<pattern.size();i++)
        {
            //第一次设置，存入map
		if (record.find(pattern[i]) == record.end())
		{
			//这之前还要判断一下是否value重复
            //当为"abba"  "dog dog dog dog"时的判断
			if (valueTimes[splitStr[i]] == 0)
			{
				valueTimes[splitStr[i]]++;
				//存入键值对
				record[pattern[i]] = splitStr[i];
			}
			else
				return false;
		    }		
            //如果map里面有值，但是不匹配，说明不符合
            else if(record[pattern[i]]!=splitStr[i])
                return false;            
        }
        return true;
    }
};
```