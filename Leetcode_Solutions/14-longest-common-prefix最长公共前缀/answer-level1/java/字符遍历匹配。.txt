### 解题思路
首先求出数组中的最短字符串长度resultMaxLength，也就是公共前缀的最大长度。以resultMaxLength作为下标形成第一层循环，遍历数组为第二层循环，按照字符来遍历匹配，成功加入result，失败直接跳出外层循环。

执行用时 :1 ms, 在所有 Java 提交中击败了84.00%的用户
内存消耗 :37.7 MB, 在所有 Java 提交中击败了27.99%的用户
### 代码

```java
class Solution {
    public String longestCommonPrefix(String[] strs) {
        if(strs.length==0){
            return "";
        }else{
            StringBuilder result =new StringBuilder();
        int resultMaxLength = strs[0].length();
        for(int i =0;i<strs.length;i++){
            int temp= strs[i].length();
            if(temp<resultMaxLength){
                resultMaxLength=temp;
            }
        }
        labelA:
        for(int i =0;i<resultMaxLength;i++){
            char firstChar = strs[0].charAt(i);
            for(int j=1;j<strs.length;j++){
                char secondChar = strs[j].charAt(i);
                if(firstChar!=secondChar){
                    break labelA;
                }
            }
            result.append(firstChar);
        }
        return result.toString();
        }
    }
}
```