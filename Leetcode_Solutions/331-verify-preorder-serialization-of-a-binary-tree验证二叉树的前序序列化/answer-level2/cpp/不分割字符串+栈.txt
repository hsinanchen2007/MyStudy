### 解题思路
![image.png](https://pic.leetcode-cn.com/e81ebac103c4d85ec82ba9bf31536188a733bb83adbaaea126c930db0a5226c3-image.png)

用flag==1标记子树未遍历结束，flag==0子树遍历结束
当弹出栈内元素（根）代表要遍历左右子树--默认遍历了左子树，置flag=1
当遍历右子树为空结点且flag=1置flag=0表示子树遍历结束



### 代码

```cpp
class Solution {
public:
    bool isValidSerialization(string preorder) {
        int n = preorder.length();
        stack<int> s;
        //flag用于标记子树是否遍历完成
        int flag=1;
        for(int i=0;i<n;i++){
            //字符串未结束，但已经遍历完前序序列
            if(flag==0) return false;
            //如果为非空结点，则push
            if(preorder[i]!='#'){
                while(i<n && preorder[i]!=','){
                    i++;
                }
                //push(1)标记push结点
                s.push(1);
            }
            else{
                i++;//去掉逗号
                //遍历完某颗子树，置flag=0
                if(flag) flag=0;
                //左子树为空，弹出根
                if(!s.empty()) {
                    s.pop();
                    flag=1;
                }
                
            }
        }
        if((s.empty())&&(!flag)) return true;
        else return false;    
    }
    
    
};
```