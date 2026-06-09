嵌套深度最小 就是要尽量的把嵌套拆开  就是说如果原来字符串中括号存在嵌套 我们就把这个嵌套结构分别扔到A，B中
于是 我们遍历一遍字符串 
如果seq[i]==seq[i-1]就是说当前是两个相同的半括号，因此我们要给他们分配不同的AB
如果seq[i]!=seq[i-1]就是说当前是一对有效括号 我们可以给他们分配到一个A中 

题目给定的一定是有效括号的组合， 所以不用担心最后会存在单只括号出现


```
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {

        if(seq.size()==0)
            return {};
        int n=seq.size();
        vector<int> answer(n,0);
         
        for(int i=1;i<n;i++){
            if(seq[i]!=seq[i-1])
                answer[i]=answer[i-1];
            else
                answer[i]=!answer[i-1];

        }
            return answer;
    }
};
```
