### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] anagramMappings(int[] A, int[] B) {
        //哈希表法：用哈希表存下B数组中元素的值和它的索引
        Map<Integer,Integer> map=new HashMap<>();
        for(int i=0;i<B.length;i++)
            map.put(B[i],i);
        int [] res=new int[A.length];
        for(int i=0;i<A.length;i++)
            res[i]=map.get(A[i]);
        return res;
    }
}
```