### 解题思路
官方题解的动态规划是用左向右和右向左两次遍历，我这种方式是用了一次左向右，但通过循环来判断右边到左边的情况。

### 代码
![image.png](https://pic.leetcode-cn.com/dc94cc01851f6054224652fb4681a7d6d962122d6556203dcf079affc9bf2442-image.png)

```cpp
class Solution {
public:
    int longestValidParentheses(string s) {
        int length=s.size();
        int l_num=0,r_num=0;
        int temp=0,max_ans=0,flag_num=-1;
        int i=0;
        while(i<length)
        {
            if(s[i]=='(') {l_num=l_num+1;}
            if(s[i]==')') { r_num=r_num+1;}
            
            if(l_num==r_num) 
            {
            temp=(i-flag_num)/2;
            if(max_ans<=temp) max_ans=temp;
            }
            if(r_num>l_num) 
            {
                l_num=0;
                r_num=0;
                temp=0;
                flag_num=i;
            }
            if(l_num>r_num&&i==length-1)
            {
                if(flag_num+1==length-1) break;
                i=flag_num+1;
                flag_num=flag_num+1;
                l_num=0;
                r_num=0;
                temp=0;
            }
            i++;
        }
        return 2*max_ans;
    }};  
```