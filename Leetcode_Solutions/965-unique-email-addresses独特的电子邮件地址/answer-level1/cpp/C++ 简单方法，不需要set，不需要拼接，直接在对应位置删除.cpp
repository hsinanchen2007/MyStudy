执行用时 :32 ms, 在所有 C++ 提交中击败了93.13%的用户
内存消耗 :10.8 MB, 在所有 C++ 提交中击败了99.60%的用户
空间复杂度O(1)不需要辅助空间,时间复杂度O(n)
```
class Solution
{
public:
    int numUniqueEmails(vector<string> &emails)
    {
        int addr; //记录每个email@的下标
        for (int i = 0; i < emails.size(); i++)
        {
            for (int j = 0; j < emails[i].size(); j++)
            {
                if (emails[i][j] == '.') //如果遇到.,将.删掉
                {
                    emails[i].erase(j, 1); //erase的两个参数是第一个是删除的元素位置，第二个是删除几个元素
                    j--;                   //删除完后原来的位置就会被下一个元素取代，而循环过后j++,所以现在让j减一。
                }
                else if (emails[i][j] == '+') //将+到@的所有元素删除
                {
                    for (int m = j + 1; m < emails[i].size(); m++) //m从j的下一个位置开始向后遍历找@
                    {
                        if (emails[i][m] == '@')
                        {
                            addr = m; //addr为@在当前字符串中的下标
                            break;    //找到了@跳出
                        }
                    }
                    emails[i].erase(j, addr - j); //删除从+到@的所有元素
                    break;
                }
                else if (emails[i][j] == '@') //遇到@直接break，因为后面的字符串都不需要动
                {
                    break;
                }
            }
        }
        sort(emails.begin(), emails.end());                               //这一句必须要加，因为unique是在排序好的vector的基础上将重复元素放入vector尾
        emails.erase(unique(emails.begin(), emails.end()), emails.end()); //删除vector中的重复元素
        return emails.size();
    }
};
```
