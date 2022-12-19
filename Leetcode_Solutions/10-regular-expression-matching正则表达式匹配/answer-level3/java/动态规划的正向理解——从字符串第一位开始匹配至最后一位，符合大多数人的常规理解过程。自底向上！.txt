### 解题思路
要实现正则匹配，**在模板可以分为两种情况，一种是字母或"."符号，另一种是"*"符号。**
因为下文代码采用自底向上的二维动态规划表的实现方式，所以我将结合二维动态表的方式进行介绍，记该表为ans[s.length()][p.length()]，字符串的第i位与模板的第j位比较结果存储在ans[i][j]中。

**第一种情况比较简单，其下可细分为：**
**1.1）字符串的第一位 与 模板第一位 的比较；
1.2）字符串的第一位 与 模板非第一位 的比较；
1.3）字符串非第一位 与 模板非第一位 的比较；**

在1.1情况中，实质上就是边界情况，模板第一位不可能是“*”，所以直接是ans[0][0] = s.charAt(0)==p.charAt(0) || p.charAt(0)=='.'；

在1.2情况中，又分为两种情况
1.2.1) 要进行比较的模板符号上一位是"\*"，有可能"\*"令前面一个符号匹配零次仍然可行，所以要检查j位前的所有奇数位是否都为“\*”（序号从0开始计算，所以是1,3,5...这些基数位），当j前的所有基数位均为“\*”时，证明第j位前的模板都是零次匹配都可以成立的，所以返回true
    1.2.2) 要进行比较的模板符号上一位不是"*"，证明j位前肯定有其他必须比配上的字符，所以返回false

在1.3情况中，当i与j匹配上了，那么s[0~i]与p[0~j]的匹配情况，就取决于s[0~i-1]与p[0~j-1]的匹配情况了。


**第二种情况，就是要比较的第j位是“\*”符号**
这种情况比较复杂，主要是该符号可能让**前面的那个元素匹配零次，一次，或者两次及以上**，我们无法提前知道该符号到底是发挥了多少次的作用，并且极有可能不同的作用次数导致同一条字符串匹配成功。如s="aaaa", p="a\*a\*",因此这里满足**动态规划**的重复子问题特征，可以尝试用动态规划实现（实际上，因为每个字符与模板的匹配情况都基于该字符之前的字符串与模板的匹配情况，因此也满足动态规划的最优子结构要求）。

状态ans[i][j]表示字符串为s[0~i]与模板p[0~j]是否匹配。因此具体来说，这种情况就适用细分为：

2.1）**\*作用零次，模板的最后一位（即第j个字符）变成第j-2个字符**。ans[i][j]就是ans[i][j-2]。因为模板中j-1和j位置上的字母被忽略。但是我们还是要判断以下这三种情况是否能成立一个，即最后一位字符匹配上：
    s.charAt(i)==p.charAt(j-2)
    p.charAt(j-2)=='.'
    p.charAt(j-2)=='\*'
    只有这三个情况成立一个，*才可以作用零次仍然与字符串匹配上。

2.2）**\*作用一次, 模板的最后一位变成第j-1个字符**，即ans[i][j]=ans[i][j-1]的情况，因为模板中j位置上的字母被忽略：

2.3）**\*作用两次**要先满足ans[i-1][j-1]的情况，即**ans[i][j]基于ans[i-1][j-1]的情况再判断第i位字符与第j位字符的匹配**。又因为j位实际上是表示第j-1位，所以要判断下列条件是否成立其中一个：
    s.charAt(i)==p.charAt(j-1)
    p.charAt(j-1)=='.'

2.4）**\*作用两次以上**时要先满足ans[i-1][j]的情况，即**ans[i][j]基于ans[i-1][j]的情况再判断第i位字符与第j位字符的匹配情况**, 又因为j位实际上是表示第j-1位，所以要判断下列条件是否成立其中一个：
    s.charAt(i)==p.charAt(j-1)
    p.charAt(j-1)=='.'

当然，当j-2<0时我们不需考虑2.1情况；当j-1<0时我们不需考虑2.2和2.3的情况；当i-1<0时我们不需考虑2.4和2.3的情况，因为不存在。
当以上情况全部都不满足时，ans[i][j]就会被判为false。

**小结：
ans[i][j]为true的情况包括：
1）s.charAt(i)==p.charAt(j) || p.charAt(j)=='.'
2）p.charAt(j-1)=='*' && for all j%2==0,p.charAt(j)='*'
3）p.charAt(j)=='\*' && j-2>=0 && ans[i][j-2] && (s.charAt(i)==p.charAt(j-2)||p.charAt(j-2)=='.'||p.charAt(j-2)=='*')
4）p.charAt(j)=='\*' && j-1>=0 && ans[i][j-1]
5）p.charAt(j)=='\*' && i-1>=0 && j-1>=0 && ans[i-1][j-1] && (s.charAt(i)==p.charAt(j-1)||p.charAt(j-1)=='.')
6）p.charAt(j)=='\*' && i-1>=0 && ans[i-1][j] && (s.charAt(i)==p.charAt(j-1)||p.charAt(j-1)=='.')**
除以上6种情况，ans[i][j]为false.



### 代码

```java
class Solution {
    public boolean isMatch(String s, String p) {
        //首先处理传入字符串s或p为空的情况
        //这时候的情况一共有A)s==null & p==null;B)s==null & p!=null;C)s!=null & p==null; 三种情况
        int strLen = s.length();
        int patLen = p.length();
        if(strLen==0){
            if(patLen==0) return true;//情况A：大家都为空，肯定就是true啦
            else if(patLen>0 && patLen%2==0){//情况B：如果p的偶数位都是*,意味着p是可以代表空字符串的，也是true。所以要遍历一下p的偶数位，这里patLen一定要是偶数哦。
                int j = patLen-1;
                while(j>0){
                    if(p.charAt(j)!='*') return false;
                    else if(j==1) return true;
                    j-=2;
                }
            }else return false;
        } 
        if(strLen>0 && patLen==0){//情况C：肯定为false
            return false;
        }
        boolean[][] ans = new boolean[strLen][patLen];//声明动态规划二维表
        for(int i=0;i<strLen;i++){
            for(int j=0;j<patLen;j++){
                if(s.charAt(i)==p.charAt(j) || p.charAt(j)=='.'){//
                    if(i>0 && j>0){
                        ans[i][j] = ans[i-1][j-1]; //非边界情况，即1.3情况
                    }else if(j==0 && i==0){//1.1情况
                        ans[i][j] = true;
                    }else if(j>=2){//1.2情况。这里j>=2是因为第一个有可能为真的就是j=2的情况，因为要基数位全为*
                    	if(j%2==0){
                    		int tempJ= j;
                        	while(tempJ>=2){
	                    		if(p.charAt(tempJ-1)!='*'){
	                    			ans[i][j] = false;
	                    			break;
	                    		}
	                    		tempJ-=2;
                        	}if(tempJ<2) ans[i][j]=true;
                    	}else ans[i][j] = p.charAt(j-1)=='*' && (s.charAt(i)==p.charAt(j-2)||p.charAt(j-2)=='.') && ans[i][j-2];
                    }else ans[i][j]=false;//除以上情况，在p.charAt(j)!='*'的前提下，其他情况都为false
                }else if(p.charAt(j)=='*'){
                    if(j-2>=0){
                        ans[i][j] = ans[i][j-2] && (s.charAt(i)==p.charAt(j-2)||p.charAt(j-2)=='.'||p.charAt(j-2)=='*');//2.1情况
                    } 
                    if(j-1>=0 && ans[i][j]!=true){
                        if(i-1>=0){
                            ans[i][j] = (ans[i-1][j] && (s.charAt(i)==p.charAt(j-1)||p.charAt(j-1)=='.')) 
                            || (ans[i-1][j-1] && (s.charAt(i)==p.charAt(j-1)||p.charAt(j-1)=='.')) 
                            || ans[i][j-1];//2.2，2.3和2.4的情况
                        }else ans[i][j] = ans[i][j-1];//2.2的情况
                    }
                }else ans[i][j] = false;//除以上情况外，都为false
                //System.out.println(ans[i][j]);             
            }
        }
        return ans[strLen-1][patLen-1];
    }
}
```