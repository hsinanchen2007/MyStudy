### 解题思路
java递归转换分子分母，原来根本不用考虑约分，坑啊。。。

### 代码

```java
class Solution {
    public int[] fraction(int[] cont) {
        
        if(cont.length==1){
            return new int[]{cont[0],1};
        }else{
            return getResult(cont,cont.length-1,1,cont[cont.length-1]);
        }
    }
    private static int[] getResult(int[] cont,int index,int m,int d){
        m = cont[index-1]*d+m;
        if(index==1){
                return new int[]{m,d};
            
        }else{
            return getResult(cont,index-1,d,m);
        }
    }
}
```