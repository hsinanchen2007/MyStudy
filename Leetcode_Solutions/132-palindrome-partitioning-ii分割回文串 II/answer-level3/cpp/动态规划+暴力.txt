**暴力法**
1. 就是把所有的子串都证明一遍
2. 采用一次遍历的暴力动态规划，额外需借助一个判断当前部分字符串是否是回文串的函数
3. i对应着s中的s.at(i)，遍历一次字符串
4. 举例子[abc]当遍历到c时
5. 先讨论"abc"是否是回文串，如果是的话即当前子字符串不用分割，即0，因为初始化就为0，所以可直接遍历下一个字符
6. dp.at(i)=i表明当前最多切割次数,如i=1则子字符串为"ab"两位，最多在中间切割一次
7. for从j=1开始，j表示子子字符串的左边，i为子字符串的右边
8. 检查[j]~[i]构成的子字符串是否为回文串，如果是dp.at(i)=min(dp.at(i),dp.at(j-1)+1);这里将讨论"bc""c"
9. dp.at(i)表明一直记录的结果
10. dp.at(j-1)+1表示倘若[j]~[i]构成的子字符串为回文串，那么只需要在[j-1]和[j]之间切多一次即可，然后加上dp.at(j-1)的结果
11. j一直自增到i这个位置即可跳出循环

```
class Solution {
public:
    int minCut(string s) {
        if (isPalindrome(s))
            return 0;
        int s_size=s.size();
        vector<int> dp(s_size,0);
        string temporary;
        for (int i=1;i<s_size;++i)
        {
            temporary=s.substr(0,i+1);
            if (isPalindrome(temporary))
                continue;
            dp.at(i)=i;
            for (int j=1;j<=i;++j)
            {
                temporary=s.substr(j,i-j+1);
                if (isPalindrome(temporary))
                    dp.at(i)=min(dp.at(i),dp.at(j-1)+1);
            }  
        }
        return dp.at(s_size-1);
    }
    bool isPalindrome(string& s) {
        int left=0,right=s.size()-1;
        while(left<=right)
            if (tolower(s.at(left))==tolower(s.at(right)))
            {
                ++left;
                --right;
            }
            else
                return false;
        return true;
    }
};
```

**优化**
这种方法就是把所有的子串都证明了一次是否是回文串，而string.substr(i,num)建立子串是很耗费时间和内存的，上面的暴力破解法内存占用了500MB，所以需要优化
1. 为了判断一个子串是否是回文串，我们换种思路  
2. 可以判断一个子串的两头字母是否相等，如果相等，倘若该子串截去左右两头的各一个字母后的新子串是回文串，那么该子串也是回文串  
3. 我们第一反应是递归，那可以递归自然就可以用动态规划来优化  
4. 通过记录小的子串是否是回文串，再通过判断两头是否相等，就可以判断出大的字符串（小的子串加了左右两头字符后）是否是回文串了

**动态规划**
1. 我们建立一个judge_palindrome[][]二维数组来记录子串是否是回文串
2. 行我们设为子串的左端，列设为子串的右端，即代表子串左端的行一定要小于等于代表子串右端的列，不然左端在右端的右边就没有意义
3. dp[]来存放最小切割次数
4. 然后结合优化的思想和暴力的思想就可以完成了

```
class Solution {
public:
    int minCut(string s) {
        int s_size=s.size();
        vector<int> dp(s_size);
        vector<vector<bool>> judge_palindrome(s_size,vector<bool>(s_size,false));
        dp.at(0)=0;
        for (int i=1;i<s_size;++i)
        {
            dp.at(i)=i;
            for (int j=0;j<=i;++j)
                //j+1>i-1这个条件是因为judge_palindrome[][]只有在j+1<=i-1才有意义，即代表子串左端的行一定要小于等于代表子串右端的列
                if (s.at(i)==s.at(j) && (j+1>i-1 || judge_palindrome.at(j+1).at(i-1)))
                    //因为j==0时dp.at(j-1)越界了所以分开写
                    if (j!=0)
                    {
                        dp.at(i)=min(dp.at(i),dp.at(j-1)+1);
                        judge_palindrome.at(j).at(i)=true;
                    }
                    //如果j==0,表明[0]~[i]构成的字符串为回文串，那么切割次数必定为0，但是不能就此break，因为你还是要找到所有的子串去更新子串是否是回文串
                    else
                    {
                        dp.at(i)=0;
                        judge_palindrome.at(j).at(i)=true;
                    }      
        }
        return dp.at(s_size-1);
    }
};
```

如果仍有不懂或好方法可以留言区交流
[个人leetcode刷题仓库](https://github.com/Zhenghao-Liu/LeetCode_problem-and-solution/)
如果觉得好可以给个星星


