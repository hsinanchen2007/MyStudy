### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] printNumbers(int n) {
        if(n<0)return new int[]{};
        int Size=(int)Math.pow(10,n)-1;
        int[] result=new int[Size];
        int i=0;
        while(i<Math.pow(10,n)-1){
            result[i]=i+1;
            i++;
        }
        return result;
    }
}
```