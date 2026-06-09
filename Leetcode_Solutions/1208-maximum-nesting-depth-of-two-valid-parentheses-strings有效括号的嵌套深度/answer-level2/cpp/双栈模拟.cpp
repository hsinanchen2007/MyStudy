### 解题思路
这道题可以看做是有效括号的改版。因为这里A,B都是有效括号序列，所以用两个栈模拟。
至于嵌套深度最小，用贪心的想法就可以了。
当A中'('的个数大于B时：下一个'('插入B中。
当A中'('的个数小于B时：下一个'('插入A中。
![image.png](https://pic.leetcode-cn.com/698aeb366573dd4deaf1816da49561efc21cfc5c717b78132cb95965c1bec17a-image.png)


### 代码

```cpp
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        stack<char> A, B;
        vector<int> ans(seq.size());
        for(int i = 0; i < (int)seq.size(); ++i){
            if(seq[i] == '('){
                if(A.size() <= B.size() ){
                    A.push('(');
                }
                else{
                    B.push('(');
                    ans[i] = 1;
                }
            }
            else{
                if(!A.empty() && A.top() == '('){
                    A.pop();
                }
                else{
                    B.pop();
                    ans[i] = 1;
                }
            }
        }
        return ans;
    }
};
```