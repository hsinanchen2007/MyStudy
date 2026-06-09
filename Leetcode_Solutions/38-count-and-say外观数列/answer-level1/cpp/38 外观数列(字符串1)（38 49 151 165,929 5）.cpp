解题思路：一步步迭代，

```
class Solution {
public:
//中间有一个问题就是怎么找一个序列中连续的一段:比如111222345怎么把111这段读出来
    string countAndSay(int n) {
        string s="1";//上一个字符串内容
        
        for(int i=1;i<n;i++)//如果是正常递推的话，看递推多少次，定范围
        {
            string cur;//当前待求的字符串
            for(int j=0;j<s.size();j++)//遍历上一个字符串中每一个字符
            {
                int k=j;
                while(k<s.size()&&(s[k]==s[j]))//循环结束k就是指向第一个不是j的地址
                {
                    k++;
                }
                cur+=to_string(k-j)+s[j];
                j=k-1;//因为最后j有一个++操作，所以加之前应该等于k-1
                
            }
            s=cur;
        }
        return s;
    }
};
```
