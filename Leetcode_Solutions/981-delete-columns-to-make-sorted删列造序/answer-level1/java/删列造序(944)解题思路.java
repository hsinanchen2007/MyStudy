### 解题思路
我们检查每个字符串的每一列是否是有序的。如果它无序，则将答案增加 1

### 代码

```java
class Solution {
    public int minDeletionSize(String[] A) {
        int res = 0;
        int strlen = A[0].length();
        for(int i = 0 ; i < strlen ; i++)
        {
            for(int j = 0 ; j < A.length -1 ; j++)
            {
                if(A[j].charAt(i) > A[j+1].charAt(i)) //代表着顺序不对
                {
                    res++;
                    break;
                }
            }
        }
        return res;
    }
}
```