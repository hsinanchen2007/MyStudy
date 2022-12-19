### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] maxDepthAfterSplit(String seq) {
if(seq.length() == 0) {return new int[0];}
int len = seq.length();
int depth = 0;
int [] res = new int[len];
for(int i=0;i<len;i++)
{
if(seq.charAt(i)=='(')
{
depth++;
res[i] = depth%2;
}
else
{
res[i] = depth%2;
depth--;
}
}
return res;

    }
}
```