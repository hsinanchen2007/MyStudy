### 解题思路
此处撰写解题思路
```
最大： k*longer
最小： k*shorter
从小到大： 0-k 1-(k-1) ... k-0   :总共k+1 个
      0-k: 0个short+k个longer
      。。。。。

当k=0  返回为空
当shorter==longer  数量只有一个，且为k*longer
```




### 代码

```java
class Solution {
    public int[] divingBoard(int shorter, int longer, int k) {
        if(k==0) return new int[]{};
        if(shorter==longer) return new int[]{k*longer};
        int[] rs=new int[k+1];
        for(int i=0;i<=k;i++){
            rs[i]=i*longer+shorter*(k-i);
        }
        return rs;
    }
}
```