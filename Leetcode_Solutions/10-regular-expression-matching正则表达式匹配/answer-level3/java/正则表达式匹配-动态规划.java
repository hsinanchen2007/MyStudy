### 解题思路
1.漏写了判断条件 -> 
2.题目看错 -> 
3.初始化错误——list[i][0]从上到下错误 -> 
4.初始化错误——list[i][0]从下到上错误 -> 
5.初始化错误——从上到下正确，但list[p.length()][0]忘记判断 -> 
6.执行错误——当p为空串时不可对p.charAt(p.length()-1)判断 ->
7.正确 -> 
8.提交

### 代码

```java
class Solution {
    public boolean isMatch(String s, String p) {
        boolean[][] list = new boolean[p.length()+1][s.length()+1];
        list[0][0]=true;
        for(int i=1;i<s.length()+1;i++)
            list[0][i]=false;
        if(p.length()>0)
            if(p.charAt(p.length()-1)=='*')
                list[p.length()][0]=true;
            else
                list[p.length()][0]=false;
        for(int i=1;i<p.length();i++)
        {
            if(p.charAt(i-1)=='*'||p.charAt(i)=='*')
                list[i][0]=true;
            else
            {
                for(int j=i;j<=p.length();j++)
                    list[j][0]=false;
                break;
            }               
        }
        
        for(int i=1;i<p.length()+1;i++)
        {
            for(int j=1;j<s.length()+1;j++)
            {
                if(p.charAt(i-1)=='*')
                {
                    if(i==1)
                        list[i][j]=false;
                    else
                    {
                        int k=i-1;
                        while(p.charAt(k-1)=='*'&&k>1)
                            k--;
                        if((list[i][j-1]==true&&(p.charAt(k-1)=='.'||p.charAt(k-1)==s.charAt(j-1)))||list[k-1][j]==true||list[i-1][j]==true)//要有多个相等，必先有一个相等，第一个相等后，后面的再加一个相等
                            list[i][j]=true;
                        else
                            list[i][j]=false;
                    }
                }
                else
                {
                    if(p.charAt(i-1)=='.')
                        list[i][j]=list[i-1][j-1];
                    else
                        list[i][j]=list[i-1][j-1]&&p.charAt(i-1)==s.charAt(j-1);
                }
            }
        }
        return list[p.length()][s.length()];
    }
}
```