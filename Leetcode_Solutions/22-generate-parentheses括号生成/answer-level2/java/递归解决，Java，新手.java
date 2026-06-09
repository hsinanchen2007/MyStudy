开始没什么思路，想着暴力解决，直接列出所有解法，然后筛选有效的，能得到结果，提交时候超时了。

然后想着优化下，由于每个都有个左右括号，所以列出所有解的时候，只有（+所有组合+）  ，切割字符串的时候为1的情况还卡了下，这样也有结果，还是超时。

感觉思路不对了，就想法，想用递归解决。但是f(n)和f(n-1)的情况没啥关系啊，就看着前面的答案总结规律，终于发现的关系

f(n)=f(1)+f(n-1)=f(2)+f(n-2)=...=f(n-1)+f(n)

然后把所有等号的加起来就行了。
结果有两个问题，一个是有重复的，这个简单，加入list的时候判断下就行。
另一个是f(n)的情况自己考虑错了，以为只有一个((((...))))情况呢，最后想了下，应该是（+f(n-1)+)才对。
所以就有了答案。

可以通过，但是时间复杂度和空间复杂度都挺高。
```
 public static List<String> generateParenthesis(int n) {
        List<String> ans=new ArrayList<>();
        if (n==1){
            String temp="()";
            ans.add(temp);
            return ans;
        }
        //fn
        List<String> strN=generateParenthesis(n-1);
        for (String s:strN
             ) {
            ans.add("("+s+")");
        }
        //f1+fn-1=f2+fn-2=f3+fn-3=fn-1+f1
        for (int i = 1; i <n ; i++) {
            List<String> list1=generateParenthesis(i);
            List<String> list2=generateParenthesis(n-i);
            for (String s1:list1
                 ) {
                for (String s2:list2
                     ) {
                    if (!ans.contains(s1+s2))
                        ans.add(s1+s2);
                }
            }
        }
        return ans;
    }
```
