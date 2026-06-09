### 解题思路
假设输入是 abcba
从左到右依次递增长度寻找最长回文子串
字符串：{需要计算的子串}->{最长回文子串}
a：{a}->{a}
ab:{a的结果,b,ab}->{a}(a和b的长度一样，记录a就行了)
abc:{ab的结果,abc,bc}->{a}
abcb:{abc的结果,bcb,cb,b}->{bcb}
abcba:{abcb的结果,abcba,bcba,cba,ba,a}->{abcba}


### 代码

```java
class Solution {
    public String longestPalindrome(String s) {
        if(s.length()==0){
            return "";
        }
        //记录最长回文子串的数组
        String[] r=new String[s.length()];
        //把输入分割成数组
        String[] str=s.split("");
        //第一个的最长回文子串是自身
        r[0]=str[0];
        for(int i=1;i<str.length;i++){
            r[i]=r[i-1];
            //循环找出最长回文子串，j从第几个开始截，k截到第几个
            for(int j=0,k=i+1;j<k&&k>=1;j++){
                //剪枝，卡掉一部分没必要的运算
                if(k-j<r[i-1].length()){
                    break;
                }
                if(isPalindrome(str,j,k)){
                    //前一个最长回文子串的长度小于新的回文子串时，更新r[i]
                    if(r[i].length()<s.substring(j,k).length()){
                        r[i]=s.substring(j,k);
                    }
                }
            }
        }
        return max(r);
    }

    //判断是否是回文
    public boolean isPalindrome(String[] s,int n,int m){
        for(int i=n,j=m-1;i<j;i++,j--){
            if(!s[i].equals(s[j])){
                return false;
            }
        }
        return true;
    }

    //返回数组中最长的串
    public String max(String[] s){
        String max="";
        for(int i=0;i<s.length;i++){
            if(max.length()<s[i].length()){
                max=s[i];
            }
        }
        return max;
    }
}
```