找规律，取巧了
1.二叉树的叶子节点始终比非叶子结点多一个
2.叶子节点记为1，非叶子节点记为-1，所有的节点的值加起来为1就说明可以组成完整的二叉树。
3.当节点累加的值为1且没有遍历完所有节点时，返回false

```
class Solution {
    public boolean isValidSerialization(String preorder) {
        if(preorder == null || preorder.length() == 0){
            return true;
        }
        String[] split = preorder.split(",");
        int sum = 0;
        for(int i = 0; i < split.length; ++i){
            sum += ("#".equals(split[i])) ? 1 : -1;
            if(sum == 1 && i < split.length - 1){
                return false;
            }
        }
        return sum == 1;
    }
}
```
