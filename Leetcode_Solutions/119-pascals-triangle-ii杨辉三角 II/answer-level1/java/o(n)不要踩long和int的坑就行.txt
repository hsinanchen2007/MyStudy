### 解题思路
知道杨辉三角的规律就可以实现o(n)的时间复杂度。
第`row`行有`row+1`个数，首尾是`1`，第`i`个数的值为：
`row[i]=(row+1-i)*pre/i;`其中`pre`是第`i-1`个数。
这里注意，当`row>=30`时，如果直接用int型运算的话，就会超范围，注意先用long计算，再将结果转换为int就可以了。

### 代码

```java
class Solution {
    public List<Integer> getRow(int rowIndex) {
        List<Integer> anslist=new ArrayList<>();
    
        anslist.add(1);
        for(int i=1;i<=rowIndex;i++)
        {
            long pre=anslist.get(i-1);
            long temp=(rowIndex+1-i)*pre;
            int multi=(int)(temp/i);
            anslist.add(multi);
        }
        return anslist;
    }
}
```