### 解题思路
1、依据题意，遍历字符较少的对象最佳
2、使用indexOf 进行检索查找
3、第一次遍历下标从0开始，且第二个字符之后的查找索引开始位置为第一次结果后移一位

### 代码

```java
class Solution {
    public boolean isSubsequence(String s, String t) {
        int i = -1;
        for(char c : s.toCharArray()){
           i =  t.indexOf(c,i+1);
            System.out.println(i);
           if(i == -1){
                return  false;
           }
        }
        return true;
    }
}
```