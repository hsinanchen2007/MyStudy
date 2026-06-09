### 解题思路
对于这道题，我们需要判断多个子串是否是回文子串，在判断的过程中会有重复的字串判断，所以为了，减少判断时间复杂度，我们从暴力递归，改造成动态规划的形态。
首先我们定义一个二维数组dp，行和列分别代表字符串s每个字符的下标,例如dp[j][i] 代表从下标为j到i之间的子串，是否为回文子串，如果是记录下为true，否则为false,
这样就可以把之前判断过的记录下来，当判断dp[j-1][i+1]的时候，当s[j-1]=s[i+1]时，我们只需要判断dp[j][i]是否为回文子串即可，因为dp[j][i]之前已经判断过，所以不用再进入j到i这个范围内判断j到i是否是回文子串。
我们再用本题中的例子具体演示一下，方便理解：
当i=1, j=0时，s[j]=b,s[i]=a,所以dp[0][1]=false;
当i=2,j=0时，s[j]=b,s[i]=b,这时候我们要判断s[0+1]=s[2-1]?显然相等，所以dp[j][i]=true;
当i=3,j=0时，s[j]=b,s[i]=a,不相等，j++,s[1]=a=s[3],同理此时判断s[1+1]=s[3-1]?显然相等。
总之就是让列表示的下标走在前面，然后用行表示的下标，判断列之前的每一字符的位置到它之间是否回文，其中判断的过程一定会有重复的判断，而这些重复的也一定是在之前的循环过程中被判断过，所以不用再进入子串的子串中进行判断。
### 代码

```cpp
class Solution {
public:
    string longestPalindrome(string s) {
    int length=s.length();
   if(length<=1)
   {
       return s;
   }
   vector<vector<int>>res (length,vector<int>(length,0));
    //先初始化二维数组（对角线）
   for(int i=0;i<length;i++)
    {
        res[i][i]=1;
    }
    int start=0;//记录最大回文子串的开始位置
    int maxlength=1;//记录最大回文子串的长度
    for(int i=1;i<length;i++)//两层for循环遍历每一个位置到另一个位置的情况
    {
        for(int j=0;j<i;j++)
        {
            if(s[i]==s[j])
            {
                if(i-j<3)//如果如果两个相等字符之间只有一个字符，那么一定回文
                {
                    res[j][i]=1;
                }
                else
                {
                    res[j][i]=res[j+1][i-1];
                }
            }
            if(res[j][i])//当j到i之间的子串回文时判断其长度是否最大，然后更改
            {
                if(i-j+1>maxlength)
                {
                    maxlength=i-j+1;
                    start=j;
                }
            }

        }
    }
    return s.substr(start,maxlength);
  }
};
```