给定一个整数数组，你需要验证它是否是一个二叉搜索树正确的先序遍历序列。

你可以假定该序列中的数都是不相同的。

参考以下这颗二叉搜索树：

     5
    / \
   2   6
  / \
 1   3
示例 1：

输入: [5,2,6,1,3]
输出: false
示例 2：

输入: [5,2,1,3,6]
输出: true

```c++
//time: o(n)
//space: o(1)
//https://www.cnblogs.com/grandyang/p/5327635.html
/*
 		  4
 	 2      6
 1	 3  5   7

  4, 2, 1, 3, 6, 5, 7

二叉搜索树左子树是递减的
s: 4, 2, 1
p = 3
min = INT_MIN


3是2的右子树

s: 4, 3
p = 6
min = 2


右子树的每个值都比左子树的值大
s:  6
p = 5
min = 4

s: 7 
p = 7
min = 6
return true;

*/
class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        stack<int> s;
        int min = INT_MIN;
        for(int i = 0; i < preorder.size(); i++){
            if(preorder[i] < min){
                return false;
            }
            while(!s.empty() && s.top() < preorder[i]){
                min = s.top();
                s.pop();
            }
            s.push(preorder[i]);
        }
        return true;
    }
};
//time:o(n)
//space:o(1)
//为了使空间复杂度为常量，我们不能使用 stack，所以直接修改 preorder，将 low 值存在 preorder 的特定位置即可，前提是不能影响当前的遍历
class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int min = INT_MIN;
        int i = -1;
        for(int p : preorder){
            if(p < min){
                return false;
            }
          	//example:
          	// i = 1
          	// p = 7
            // 6, 5, 7
            // 7, *, *, *代表不在意，随便他是多少
            while(i >=0 && p > preorder[i]){
                min = preorder[i--];
            }
            preorder[++i] = p;
        }
        return true;
    }
};
```

