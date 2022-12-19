介绍一种暴力递归方法。

```
class Solution {
public:
    int minSteps(int n) {
        int a=1,b=1;//a子节点，b父节点
        if(n==1)
        return 0;
        else{
            return tree(a,b,n);
        }
    }

    int tree(int a,int b,int n){
        if(a<n&&a==b){
            return tree(2*a,a,n)+1;//当子节点等于父节点时，说明上一次操作为复制，因此下一步操作只能为粘贴；
        }
        else if(a<n&&a>b){
            return min(tree(a,a,n),tree(2*a-b,a,n))+1;//当子节点小于父节点时，说明上一次操作为粘贴，因此下一步操作为复制和粘贴，取两个操作中后续有较少步骤的那一个；
        }
        else if(a==n){return 1;}//当子节点达到n，操作终止
        else {return 1000;}
    }
};