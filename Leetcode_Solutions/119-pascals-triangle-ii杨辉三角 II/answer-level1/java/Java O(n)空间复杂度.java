### 解题思路
通过对杨辉三角的观察不难看出, 杨辉三角每行仅比上一行多一位, 当前行的size为k, 那么只有1~k-1是需要更新的.
如果想要使用O(n)的空间复杂度, 那就需要就地执行, 再根据规律, 如果先计算f‘(i)=f(i)+f(i-1), 那么f(i+1)=f(i+1)+f(i)中的f(i)就被更新了.
所以需要从后往前(从k-1到1), 递推执行.

### 代码

```java
class Solution {
    public List<Integer> getRow(int rowIndex) {
        List<Integer> result=new ArrayList<>();
        result.add(1);
        if(rowIndex==0) return result;
        for(int i=1;i<=rowIndex;i++){
            result.add(1);
            for(int j=result.size()-2;j>0;j--){
                result.set(j,result.get(j)+result.get(j-1));
            }
        }
        return result;
    }
}
```