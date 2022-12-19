### 解题思路
1.有逗号在字符串中
2.数字可能大于9，即两位数。
3.一个字符串是先序二叉树序列，可以从下面两个角度任一个来判断。
1）自顶向下：每遇到一个数字增加两个新位置，要填充两个子节点，遇到一个#不增加新位置，不论遇到#还是数字都减少一个位置，初始位置为1.最后如果位置大于0个，或小于0个，都不是正确的序列。
2）自底向上：每遇到 _##,（_表示数字)，就说明_是叶子结点，叶子结点可以摘掉，把_##替换为#，一直替换直到只剩#就说明是正确的，如果字符串中已经没有_##但还不等于#，那么错误。这种替换用python比较方便。

### 代码

```cpp
class Solution {
public:
    bool isValidSerialization(string preorder) {
        int slot=1;
        for(int i=0;i<preorder.size();i++){
            if(preorder[i]==',')continue;
            if(--slot<0)return 0;
            if(preorder[i]=='#')continue;
            else{
                slot+=2;
                i+=1;
                while(i<preorder.size()){
                    if(preorder[i]>='0'&&preorder[i]<='9')i++;
                    else break;
                }
                i--;
            }
        }
        return slot==0;
        
    }
};
```