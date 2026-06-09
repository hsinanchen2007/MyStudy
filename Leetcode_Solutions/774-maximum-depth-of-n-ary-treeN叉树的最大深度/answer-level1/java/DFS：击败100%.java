### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {

   int res = 0;

   private int helper(Node root, int depth){

       if(root == null){
           return 0;
       }

       res = Math.max(res,depth);

       for(int i = 0; i< root.children.size(); i++){

           helper(root.children.get(i), depth + 1);
       }

       return res;
   }

    public int maxDepth(Node root) {

        if(root == null){
            return res;
        }

        return helper(root, res + 1);
    }
}
```