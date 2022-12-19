### 解题思路
题目有点长，意思其实比较简单，就是依次比较数组中每一个字符串的每一个字符是否是升序的，如果不是升序，结果加1，继续遍历，这里有两个长度，不要搞混淆了，一个是数组的长度，一个是数组里字符串的长度，我们只需遍历字符串的长度，然后遍历数组每一个元素，看相同位置（index）的字符是否升序排列

### 代码

```java
class Solution {
    public int minDeletionSize(String[] A) {
        if(A.length == 0) return 0;

        String s = A[0];
        int index = 0;
        int num = 0;
        //index表示字符串的索引
        while(index < s.length()){
            if(!helper(1, A, index)){
                num++;
            }
            index++;
        }
        return num;
        

    }
    
    private boolean helper(int i, String[] A, int index){
        if(i == A.length) return true;
        
        //这里依次比较A[1]与A[0]字符串在索引0是否是升序，如果是，再比较A[2]与A[1]在索引0上是否是升序
        if(A[i].charAt(index) >= A[i-1].charAt(index)){
           return helper(i+1, A, index);
        }
        return false;
        
    }
}
```