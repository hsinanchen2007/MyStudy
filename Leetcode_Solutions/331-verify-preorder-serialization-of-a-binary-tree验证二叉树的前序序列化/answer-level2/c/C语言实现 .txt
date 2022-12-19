# C语言实现
基本思想
- 根据先序二叉树和中序/后序的不同 先序遍历先访问根节点 中序和后续先访问叶节点

考虑特殊情况——例如序列的部分是已经是满二叉树了 还有节点
```c
bool isValidSerialization(char * preorder){
/*基本思想：根据先序二叉树和中序/后序的不同 先序遍历先访问根节点 中序和后续先访问叶节点*/
    int n = strlen(preorder);

    int degree = 1;//根节点出度-入度 为2 比正常节点出度-入度 多1
    for (int i = 0; i < n; i++){
        if (degree ==0){
            return false;
        }
        if(preorder[i] == ',')
            continue;
        if (preorder[i] == '#')//遇到叶节点度数减一
            degree -= 1;
        //遇到非叶节点度数加一
        else{
            while(i < n && preorder[i] != ',')//处理节点编号为多位数字的情况
                i++;
            degree += 1;
        }
    }

    return (degree == 0);
}
```
