### 解题思路
先找到划分左右子树的节点，然后递归。
注意终止条件是begin>=end!!!
### 代码

```cpp
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        if(postorder.size()==0) return true;
        return check(postorder,0,postorder.size()-1);   
    }
    bool check(vector<int>& postorder,int begin,int end)
    {
        if(begin>=end) return true;//要写大于！！因为end不断-1，最后剩两个的时候可能存在end-1<begin
        int a=begin;
        while(postorder[a]<postorder[end]) a++;//找到划分左右的点a
        a=a-1;//要-1！！！！！！！！
        for(int i=a+1;i<=end-1;i++)
        {
            if(postorder[i]<postorder[end]) return false;//右子树存在小于root的点
        }
       return check(postorder,begin,a)&&check(postorder,a+1,end-1);
    }
};
```