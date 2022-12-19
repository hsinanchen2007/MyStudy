### 解题思路
1.二叉排序树的定义，对于当前节点root，左边都比他小，右边的都比他大；
2.先序遍历，根->左子->右子
由这两个特性决定了一个正确的二叉排序树的先序序列应该满足**局部递减，总体递增**
遍历过程如下：
![未命名文件.png](https://pic.leetcode-cn.com/87be14ea93359c3c7c628c4e9b750088e18480e915abb4c4225c7e482cd18e04-%E6%9C%AA%E5%91%BD%E5%90%8D%E6%96%87%E4%BB%B6.png)





### 代码

```cpp
class Solution {
public:
    stack<int> s;
    int last_root=0;
    bool verifyPreorder(vector<int>& preorder) {
        if(preorder.size()==0) return true;
        s.push(preorder[0]);
        for(int i=1;i<preorder.size();i++){
            //cout<<last_root<<endl;
            if(preorder[i]<preorder[i-1]){
                if(preorder[i]<last_root) return false;
                s.push(preorder[i]);
            }
            else{
                while(!s.empty()&&s.top()<preorder[i]){
                    last_root=s.top();
                    s.pop();
                }
                //此时last_root->right=preorder[i],所以以preorder[i]为根继续的局部递减序列一定都比last_root大
                s.push(preorder[i]);
            }
        }
        //对于最后面一直递减的情况处理尾巴
//        while(!s.empty()&&s.top()<preorder[i]){

//        }
        return true;
    }
};
```