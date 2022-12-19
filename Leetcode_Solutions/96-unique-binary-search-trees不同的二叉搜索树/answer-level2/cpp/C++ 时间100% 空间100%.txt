用个数组记录之前的情况就快多了

首先 我们知道 `n==1` 与 `n==2` 返回的就是本身

在这个基础上进行计算

举例：
1 2 3

变成二叉搜索树无非就是谁做root节点的问题，当然1,2,3谁都可以

我们已经知道`n==1`与`n==2`的情况，保存在`vector<int> work`中，work[1]=1,work[2]=2

那个三个节点的1,2,3是多少中情况呢？很明显是1,2,3都做一次root节点
- 1、1为root节点，此时右边的2个节点是右子树，而2个节点作为一个树的情况我们已经知道了，直接查询work[2]=2
- 2、2为root节点，此时左右都是1个节点的子树，也就是work[1]*work[1];
- 3、1为root节点，此时左边的2个节点是左子树，同1为work[2]=2
因此work[3]=2+1+2=5

之后的同理迭代运算即可

```
class Solution {
public:
    int numTrees(int n) {
        
        if(n==1 || n==2) return n; //特殊情况
        vector<int> work={1,1,2};   //工作数组 其中work[0]=1表示当左右子树为空时的情况
        int index=3;
        while(index<=n)
        {
            int tmp=0;
            for(int i=1;i<=index;i++)
            //当一个点作为root节点时，此时应该有 左子树个数×右子树个数 即work[i-1]*work[index-i]
                tmp+=(work[i-1]*work[index-i]); 

            work.push_back(tmp);
            index++;
        }
        return work[n];
    }
};
```
![深度截图_选择区域_20200330145120.png](https://pic.leetcode-cn.com/2d7460410e529e37715454704fe0547954e6a76962cb465f4a321894daf9c3ba-%E6%B7%B1%E5%BA%A6%E6%88%AA%E5%9B%BE_%E9%80%89%E6%8B%A9%E5%8C%BA%E5%9F%9F_20200330145120.png)

