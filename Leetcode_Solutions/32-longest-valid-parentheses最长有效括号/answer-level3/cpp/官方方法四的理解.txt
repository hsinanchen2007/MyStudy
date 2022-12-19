#### 题目：
最长连续有效括号序列。
***
这题有很明显的策略，个人认为没必要动态规划。
#### 解法1：栈
记录配对成功的括号下标，统计连续的最大长度。一对配对的括号，其内部一定全都配对了。
#### 解法2：
只包含一个配对串的括号串有以下几种形态：  
1. ```(valid)```
2. ```))(valid)((```
3. ```))(valid)```
4. ```(((valid)```
5. ```(valid)((```
6. ```(valid)))```

任何一个给定的括号串一定是上面的组合，现在采取两种遍历方法，分别统计给定括号串中上述6种形态的长度。
1. 从左到右，统计1，2，3，5，6。  
原则：忽略首先碰到的```)```。  
```左括号数left<右括号数right```时，两数全部清0。  
```left==right```时，说明检测到一个有效的串，记录其长度，继续统计。  
```left>right```时，继续统计。
2. 从右到左，统计1，2，3，4，5。  
原则：忽略首先碰到的```(```。  
```左括号数left>右括号数right```时，两数全部清0。  
```left==right```时，说明检测到一个有效的串，记录其长度，继续统计。  
```left<right```时，继续统计。

两次遍历后取最大值即为答案。
```cpp
class Solution {
public:
    int longestValidParentheses(string s) {
        int ans=0, left=0, right=0;
        for(char x:s){
            if(x=='(') left++;
            else right++;
            if(left<right) left = right = 0;
            if(left==right && left+right>ans) ans = left + right;
        }
        left = right = 0;
        int n = s.size();
        for(int i=n-1; i>=0; i--){
            if(s[i]=='(') left++;
            else right++;
            if(left>right) left = right = 0;
            if(left==right && left+right>ans) ans = left + right;
        }
        return ans;
    }
};
```