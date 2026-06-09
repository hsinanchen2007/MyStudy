### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] maxDepthAfterSplit(String seq) {
            int[] result=new int[seq.length()];
            boolean stack=false;
            for(int i=0;i<seq.length();i++)
            {
                if(seq.charAt(i)=='(')
                {
                    stack=!stack;
                    if(stack==true)
                        result[i]=0;
                    else
                        result[i]=1;                 
                }
                else
                {
                    if(stack==true)
                        result[i]=0;
                    else
                        result[i]=1;
                    stack=!stack;
                }
            }
            return result;
    }
}
```