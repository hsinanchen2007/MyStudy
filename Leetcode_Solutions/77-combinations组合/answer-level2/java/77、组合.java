### 解题思路
以n=4,k=3为例：
![新建 Microsoft Visio Drawing.png](https://pic.leetcode-cn.com/4d1338858c5e7616834e4906be7a409689d7ecfeb4fce2e192f19e8627571ff1-%E6%96%B0%E5%BB%BA%20Microsoft%20Visio%20Drawing.png)
剪枝：
1、记录上一节点的数据，向下连接时，要从比上一节点大的数开始；
2、剩余数字的个数<k时，同样无需继续计算。

### 代码

```java
class Solution {
    private List<List<Integer>> res = new LinkedList<>();
    public List<List<Integer>> combine(int n, int k) {
        LinkedList<Integer> track = new LinkedList<>();
        backtrace(n, k, track, 1);
        return res;    
    }
    public void backtrace(int n, int k, LinkedList track, int index){
        if(track.size() == k){
            res.add(new LinkedList(track));
            return;
        }
        /*
        for(int i = index; i <= n; i ++)：不考虑剩余数字个数的情况
        for(int i = index; i <= n - k + 1; i ++)：n-k+1是一个定值，不能取到连接过程中所有值
        */
        for(int i = index; i <= n - k + track.size() + 1; i ++){
            track.add(i);
            backtrace(n, k, track, i + 1);
            track.removeLast();
        }
    }
}
```