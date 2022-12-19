/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/9/19
 *
 * 解题思路: 记住一点 中序遍历BST 的结果是一个升序的序列 因此 寻找中序就是寻找最大的相等子序列  1 2 3 4 4 4 5 5 6 7  众数是 4 4 4
 *
 */
```
public class leetcode501 {


    ArrayList<Integer> res = new ArrayList<>();
    //当前存在的众数的数量
    Integer zs_num = 0;
    //当前方统计的相同值节点的值
    Integer cur = null;
    //当前方统计的相同值节点的数量
    Integer cur_num= 0;


    public int[] findMode(TreeNode root) {
        if(root == null){
            return new int[]{};
        }

        order(root);

        //最后判定是否需要更新众数
        if(cur_num > zs_num){
            res.clear();
            res.add(cur);
        }else if(cur_num == zs_num){
            res.add(cur);
        }

        //to array
        int[] r = new int[res.size()];
        for(int i = 0;i < res.size();i++){
            r[i] = res.get(i);
        }
        return r;
    }

    /**
     * 先序遍历BST的结果是 升序的序列
     * @param root
     */
    public void order(TreeNode root){
        if(root == null){
            return;
        }

        order(root.left);

        //如果当前是第一个节点
        if(cur == null){
            cur = root.val;
            cur_num = 1;
        }else if(root.val != cur){ //如果val变化，就要查看当前值是不是众数
            if(cur_num > zs_num){
                res.clear();
                res.add(cur);
                zs_num = cur_num;
            }else if(cur_num == zs_num){ //如果当前数的数量 == 已经存储众数的数量 再次加入
                res.add(cur);
            }
            //更新cur 缓存
            cur = root.val;
            cur_num = 1;
        }else{//当前root值 == cur 继续递归
            cur = root.val;
            cur_num++;
        }

        order(root.right);
    }

    public static void main(String[] args) {
        TreeNode a = new TreeNode(1);
        TreeNode b = new TreeNode(2);
//        TreeNode c = new TreeNode(2);

        a.right = b;
//        b.left = c;

        leetcode501 leetcode501 = new leetcode501();
        leetcode501.findMode(a);

    }
}
```