**官方题解的非暴力法，是真的真的想不到哇，动态规划整了半天的方程整不出，想了一种比较通俗易懂的方法。**

利用一个初始化为全0的数组list，记录下有效括号对出现的位置下表

利用“有多少个有效括号对”的思路遍历字符串，利用堆栈存储左括号的下标，当遇到右括号弹出，将对应左右括号的在数组list中对应下标的值置为1.

**例如（（））））  对应的list内容 应该为 1 1 1 1 1 1**

**例如（））（（）））对应的list内容  应该为 1 1 0 1 1 1 1 0**

问题转化为，**求只含有01的数组中全为一的最长字串**  一次数组遍历即可实现
代码如下，时间复杂度O（n）
```
class Solution {
    public int longestValidParentheses(String s) {
        if(s.length()==0) return 0;
        Stack<Integer> stack=new Stack<>();
        int[] list =new int[s.length()];
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)=='(')
                stack.push(i);
            else{
                if(stack.empty())
                    continue;
                else
                    list[stack.pop()]=1;list[i]=1;
            }
        }
       int ans=0;
        for(int i=0;i<list.length;i++){
            if(list[i]!=0){
                int j=i+1;
                while(j<s.length()&&list[j]!=0){
                    j++;
                }
                if(j-i>ans) ans=j-i;
                i=j;
            }
        }
        return ans;
    }
}
```
