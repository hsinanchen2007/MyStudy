300分钟里的解答方法：

```
class Solution {
    public boolean isMatch(String s, String p) {
        if(s==null || p==null){
            return false;
        }
        return isMatch(s,0,p,0);
        

    }

    public boolean isMatch(String s,int i,String p,int j){
        int m=s.length();
        int n=p.length();
        if(j==n){
            return i==m;//当j指针遍历完p字符串后，即可跳出递归；而若i指针也刚好遍历完，说明s和p完全匹配
        }
        //如果j指向的下一个字符是不是*号，或者j已经到了p串的末尾
        if(j==n-1 || p.charAt(j+1)!='*'){  
            //此时如果j指向的字符是.或者i和j指向的字符相等，i和j指针都往后移一位
            if(i<m && (p.charAt(j)=='.' || s.charAt(i)==p.charAt(j))){
                return isMatch(s,i+1,p,j+1);
            }
            return false;//这个要加
            
        }

        //如果j指针有下一位而且下一位是*号
        if(j<n-1 && p.charAt(j+1)=='*'){
            //while循环是整个递归的核心，i指向的字符必须要和j指向的字符匹配，其中j指向的可能是点匹配符
            //不断的将j指向的字符和它后面的*号作为一个整体，分别表示空字符串，一个j指向的字符、两个字符。。。。
            //如果其中一种情况能出现s和p匹配，则返回true

            //while循环里头不断执行i的自增，一旦进入while循环
            //就是不断的去尝试isMatch(s,i,p,i+2)，isMatch(s,i+1,p,i+2)，isMatch(s,i+2,p,i+2)....
            //一直到有一个匹配上了或者i到了s串的末尾，才退出循环
            while(i<m && (p.charAt(j)=='.' || s.charAt(i)==p.charAt(j))){
                if(isMatch(s,i,p,j+2)){
                    return true;//*号组合表示空字符串，如果匹配，返回true
                }
                i++;//若不匹配，则i++，表示用*号组合去匹配更长的字符串
            

            }
            
        }
        //如果j指针有下一位而且下一位是*号
        //但是i遍历完了s字符串，或者i和j指向的字符不相等，那么只能将*号组合匹配成空字符串
        if(p.charAt(j+1)=='*' && (i==m || s.charAt(i)!=p.charAt(j))){
            return isMatch(s,i,p,j+2);
        }
        return false;
    }
}
```
