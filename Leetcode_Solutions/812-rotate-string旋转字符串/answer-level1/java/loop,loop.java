### 解题思路
为什么可以跳过len个？利用反证法，假设len内的位置可以复用，那么必定满足循环结构。而第len+1个则是破坏了这个结构，故而len内的数据都是被破坏的

### 代码

```java
class Solution {
    public boolean rotateString(String A, String B) {
        //loop操作即可
        if(A == null || B == null)
            return false;
        if(A.length() != B.length())
            return false;
        //return (A+A).contains(B);
        //为什么可以跳过len个？利用反证法，假设len内的位置可以复用，那么必定满足循环结构。而第len+1个则是破坏了这个结构，故而len内的数据都是被破坏的
        char[] a = A.toCharArray();
        char[] b = B.toCharArray();
        for(int i=0;i <a.length;){
            int len = loop(a,b,i);
            if(len == a.length){
                return true;
            }else if(len > 0){
                i += len;
            }else{
                i++;
            }
        }
            
        return A.length() == 0;
    }
    
    public int loop(char[] a,char[] b,int s){
        int count = 0;
        for(int i=0;i<a.length;i++){
            if(b[i] == a[(s+i)%a.length]){
                count++;
            }else{
                return count;
            }
        }
        return count;
    }
}
```