// 简要记录下思路，代码比较简单容易理解😂

// *为了能够满足最终输出的要求，构建根据列式索引为 KEY，value 为相同列式索引的元素构成List,所以中间存储过程可以通过构建 `TreeMap<Integer,List<int[]>>`，最终遍历输出*

// 这里使用*TreeMap*是为了满足根据列式索引的排序输出，为啥value 为List<int[]>?这里我是通过如此的数据结构来记录 depth 和 width，其实我们也可以自己构建对象来记录我们需要的状态。

// 1. 如何遍历的问题：
// - 借鉴中序遍历
// 2. 如何记录根据列式索引输出：
// - 根节点列式索引为width初始化为0，那么若存在左子节点的话则对应的列式索引为`width-1`，若存在右子节点则对应的列式索引为`width+1`，由此递归
// 3.  **如何保证根据深度较小的节点遍历的时候优先输出**：
// - 通过设置`depth`来记录层次，然后在最终遍历输出的时候保证深度越小的优先输出，如果少了此过程，在如下测试用例中![image.png](https://pic.leetcode-cn.com/f31ed27a4cad6bef352fd477437b646731bcad0c3bf42134594be5fa11e60dd9-image.png) 对于列式索引为1的时候输出会变为[2,8]，因为会优先遍历到2，然后再遍历到8。

// 综上所述，width 和 depth 是我需要重点围绕处理的，如何记录存储各位可以有自己的实现。
// 附上代码
// ```
import java.util.ArrayList;
import java.util.List;
import java.util.TreeMap;

public class LC314 {
    private List<List<Integer>> ans = new ArrayList<>();
    private TreeMap<Integer,List<int[]>> map =new TreeMap<>();

    public List<List<Integer>> verticalOrder(TreeNode root) {
        
        if(root == null) return ans;
        // 初始化 depth 和 width 分别为0；
        helper(root,0,0);
        for(List<int[]> item:map.values()){
            // 自定义排序规则，保证深度越小的元素优先输出,int[0]记录的是深度
            item.sort((a,b)->{
                return a[0]-b[0];
            });
            List<Integer> tmp = new ArrayList<>();
            
            for(int[] i:item){
                //int[1]记录的是节点值
                tmp.add(i[1]);
            }
            ans.add(tmp);
        }
        return ans;
        
    }

    private void helper(TreeNode root,int index,int depth){
        if(root != null){
            if(!map.containsKey(index)) map.put(index,new ArrayList<>());
            map.get(index).add(new int[]{depth, root.val});

            if(root.left != null){
                helper(root.left,index-1, depth+1);
            }
            if(root.right != null){
                helper(root.right,index+1, depth+1);
            }
        }
    }
}
// ```

