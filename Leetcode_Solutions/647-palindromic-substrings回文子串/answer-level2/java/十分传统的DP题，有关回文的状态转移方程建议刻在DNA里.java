### 解题思路
![QQ截图20200324151741.png](https://pic.leetcode-cn.com/806466beea144b5686c12763b5ab63f068681638d6ff4aa6335b7901a809adca-QQ%E6%88%AA%E5%9B%BE20200324151741.png)

没有优化，按照最经典的方式做出的

设b[i][j]表示字符串s[i...j]是否是回文，统计二维表b的上半三角里元素值为true的个数即可

状态转移方程：
**b[i][j]**=
{
**true**...........if i==j//主对角线上单个字符的情况

**true**...........if j-i==1&&s[i][j]   or **false**..........if j-i==1&&s[i]!=s[j]//相邻两个字符的情况，相同即回文


**b[i+1][j-1]&&s[i]==s[j]**...........j-i>=2//只有两端字符相同且抛去两端后剩下的字符串也是回文的情况下，整体才是回文


}

建议和5.最长回文子串放一起做，加强印象

### 代码

```java
class Solution {
    public int countSubstrings(String s) {
        if(s.length()==0) return 0;
        if(s.length()==1) return 1;
        int sum=0;//s里回文子串的个数
        int n=s.length();//字符串长度
        sum+=n;//对角线上的先加上
        boolean [][]count_palindrome=new boolean[n][n];//从下标0处开始使用
        for(int i=0;i<n;i++) count_palindrome[i][i]=true;

        //填表方向与矩阵连乘积问题相同，只是针对每一个当前问题，用到的已解决子问题的位置不同
        for(int r=2;r<=n;r++){//待检查字符串长度
            for(int i=0;i<n-r+1;i++){
                int j=i+r-1;
                if(r==2){//俩字符
                    if(s.charAt(i)==s.charAt(j)){count_palindrome[i][j]=true; sum+=1;}
                    else count_palindrome[i][j]=false;
                }else{//r>=3
                    count_palindrome[i][j]=count_palindrome[i+1][j-1]&&(s.charAt(i)==s.charAt(j));//状态转移方程
                    if(count_palindrome[i][j]) sum+=1;
                }
                
            }

        }

        return sum;

    }
}
```