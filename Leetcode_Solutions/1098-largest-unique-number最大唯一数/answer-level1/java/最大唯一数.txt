### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int largestUniqueNumber(int[] A) {
        //以空间换时间法
        int [] helper=new int[1001];
        for(int i:A){
            helper[i]++;
        }
        for(int i=helper.length-1;i>=0;i--){
            if(helper[i]==1)
                return i;
        }
        return -1;
    }
}
```