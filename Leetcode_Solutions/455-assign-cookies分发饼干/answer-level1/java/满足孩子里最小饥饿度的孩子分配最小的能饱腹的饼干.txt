### 解题思路
因为饥饿度最小的孩子最容易吃饱，所以先满足了这个孩子之后，我们再采取同样的策略，考虑剩下孩子里饥饿度最小的孩子，直到没有满足条件的饼干存在。
简而言之，这里的贪心策略是，给剩余孩子里最小饥饿度的孩子分配最小的能饱腹的饼干。 至于具体实现，因为我们需要获得大小关系，一个便捷的方法就是把孩子和饼干分别排序。 这样我们就可以从饥饿度最小的孩子和大小最小的饼干出发，计算有多少个对子可以满足条件。

### 代码

```java
class Solution {
    public int findContentChildren(int[] children, int[] cookies) {
        Arrays.sort(children);
        Arrays.sort(cookies);
        int child=0,cookie=0;
        while(child<children.length && cookie<cookies.length){
            if(children[child]<=cookies[cookie]) child++;
            cookie++;    
        }   
        return child;
    }
}
```