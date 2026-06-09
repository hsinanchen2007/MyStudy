### 解题思路
回溯法
### 代码

```java
class Solution {
    public boolean isUgly(int num) {
        if(num==0)
            return false;
        if(num==1)
            return true;
        int[] tmp={2,3,5};
        boolean res=false;
        for(int i=0;i<tmp.length;i++){
            if(num%tmp[i]!=0)
                continue;
            res|=isUgly(num/tmp[i]);
        }
        return res;
    }
}
```