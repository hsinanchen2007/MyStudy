### 解题思路

### 代码

```java
class Solution {
    public int[] sumZero(int n) {
        List<Integer> ans=new ArrayList<Integer>();
        if(n%2!=0)
        {
            ans.add(0);
        }
        for(int i=0;i<n/2;i++)
        {
            ans.add(i+1);
            ans.add(-i-1);
        }
        //类型转换
        return ans.stream().mapToInt(Integer::valueOf).toArray();
    }
}
```