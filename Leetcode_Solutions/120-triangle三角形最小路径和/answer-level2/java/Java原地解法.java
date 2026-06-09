### 解题思路
java原地解法，自底向上，改进就是不用dp，用原来的trianlge列表存储就可以了，节省空间。

最后效率不高：？？？？？？？？？？？？
执行用时 :
13 ms, 在所有 Java 提交中击败了 6.10% 的用户
内存消耗 :
39.3 MB, 在所有 Java 提交中击败了 5.21% 的用户

不知为何，欢迎讨论改进

### 代码

```java
class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        //双层 for 自底向上遍历一次 triangle
        for(int i = triangle.size() - 2; i >= 0; i--){
            for(int j = 0; j < triangle.get(i).size(); j++){
                triangle.get(i).set(j, triangle.get(i).get(j) + Math.min(triangle.get(i + 1).get(j), triangle.get(i + 1).get(j + 1)));
            }
        }
        return triangle.get(0).get(0);
    }
}
```