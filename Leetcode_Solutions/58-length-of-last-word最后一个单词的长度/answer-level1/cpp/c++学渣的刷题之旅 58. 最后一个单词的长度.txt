```c++
class Solution {
public:
    int lengthOfLastWord(string s) {
        int result=0;
        if(s.size()==0)
            return 0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]!=' ')
                result++;
            else if(result==0)
                continue;
            else
                return result;
        }
        return result;
    }
};
```

这道题提交结果让我太惊讶了
![image.png](https://pic.leetcode-cn.com/33175520bc56ed1f2da50b3f0d94935f857b96f697c465e84ded25ca6cac7933-image.png)

emm解题思路大抵就是从string的最后开始遍历，碰到空格就返回。但是有一种情况特殊，eg：“a ”，即string的末尾是空格。这时只需要用result来判断就好了，因为单词长度至少要大于等于1。


