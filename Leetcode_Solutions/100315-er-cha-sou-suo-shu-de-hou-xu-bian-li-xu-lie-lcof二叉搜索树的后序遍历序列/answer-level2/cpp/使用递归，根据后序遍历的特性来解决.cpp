### 解题思路
因为是二分搜索
然后后序遍历是左右根，所以左边是小于根的，根是小于右的
所以根据这点来判断是否为后序遍历
### 代码

```cpp
class Solution {
private:
    bool helper(vector<int>& postorder,int l,int r){
        if(l >= r)
            return true;
        int m = l;
        while(postorder[m] < postorder[r])
            m++;
        for(int i = m ; i <= r ; i++){
            if(postorder[i] < postorder[r])
                return false;
        }
        return helper(postorder,l,m-1) && helper(postorder,m,r-1);

    }
public:
    bool verifyPostorder(vector<int>& postorder) {
        if(postorder.size() == 0)
            return true;
        return helper(postorder,0,postorder.size() - 1);
    }
};
```