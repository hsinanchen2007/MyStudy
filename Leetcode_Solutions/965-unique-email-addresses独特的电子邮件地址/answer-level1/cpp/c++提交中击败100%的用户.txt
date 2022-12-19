### 解题思路
![微信图片_20200302011600.png](https://pic.leetcode-cn.com/dcdcc8c6d79a9867a0bc7156fab8359fdf48a731249f924732e71cfa7296e4f6-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200302011600.png)
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        for(int i = 0; i<emails.size(); i++)
        {
            for(int j = 0; j<emails[i].size(); j++)
            {
                if(emails[i][j] != '@')
                {
                    if(emails[i][j] == '.') //在'@'前，遇到'.'就删除
                        emails[i].erase(emails[i].begin() + j); 
                    else if(emails[i][j] == '+')  //在'@'前，遇到'+'就删除从'+'到'@'之前的所有元素
                    {
                        emails[i].erase(emails[i].begin()+j, 
                        emails[i].begin()+emails[i].find('@'));
                        j--;
                    }
                }
                else //遇到'@'就跳出循环 遍历数组中的第二个字符串元素
                    break;
            }
        }

        sort(emails.begin(), emails.end());  //先排序  再删除相邻相等的元素  只保留一个
        vector<string>::iterator it = unique(emails.begin(), emails.end());
        emails.erase(it, emails.end());
        return emails.size();  //返回的就是数组中不同email的个数
    }
};
```