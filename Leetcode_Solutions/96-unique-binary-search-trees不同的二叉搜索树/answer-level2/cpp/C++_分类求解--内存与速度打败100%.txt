最后一个节点为n;
假设有kind(n)种类型：
可以分为：
1) n为根节点；
2) n为x节点的右子树；其中x 属于<1, n-1>

x及其以前的节点造型数为kind(x), <x+1, n-1> 节点造型数为kind<n-1-x>
kind(n) = sum(kind(x)*kind(n-1-x))  

```
class Solution {
public:
    int numTrees(int n) {
        //二叉搜索树，左子树比根节点小，右子树比根节点大
        //新加的最大数只能成为某个数的右节点，或者成为第一个节点
        //最大数为n, 成为第一个节点f(n-1)
        //紧挨n-1节点：f(n-1)
        //紧挨1~n-2节点中的一个，f(x)*f(n-1-x)
        //f(n) = 2*f(n-1)+sum(f(x)*f(n-1-x))   <1~n-2>
        //f(n) = f(n-1)+sum(f(x)*f(n-1-x))    <1~n-1>
        //f(n) = sum(f(x)*f(n-1-x))  <0~n-1>
        //访问空间越界
        vector<int> kind(n+1);
        if(n == 0){
            return 1;
        }
        if(n == 1){
            return 1;
        }
        if(n == 2){
            return 2;
        }
        kind[0] = 1;
        kind[1] = 1;
        kind[2] = 2;
        for(int i = 3; i<n+1; i++){
            kind[i] = 0;
            for(int j = 0; j<i; j++){
                kind[i] = kind[i] + kind[j]*kind[i-1-j];
            }

        }
        return kind[n];
        
    }
};
```

