![1.png](https://pic.leetcode-cn.com/1b9ab279c3b882cd59490de17cff66457ad03164cc44675bf4261de100fae9ed-1.png)

根据liweiwei1419画的树形图，先创建树，然后去重


### 代码
```java
class Solution {


    private List<List<Integer>> res = new ArrayList<>();
    private int[] candidates;
    private int len;

    public List<List<Integer>> combinationSum(int[] candidates, int target) {

        int len = candidates.length;
        if (len == 0) {
            return res;
        }


        Arrays.sort(candidates);
        this.len = len;
        this.candidates = candidates;

        TreeNode root = new TreeNode(target, 0);

        //创建树
        buildTree(candidates, root);

        //去重
        List<List<Integer>> lists = new ArrayList<>();
        Set set = new HashSet();
        for (List<Integer> tmp : res) {
            Collections.sort(tmp);
            String key = "";
            for (Integer diff : tmp) {
                key += diff;
            }
            if (!set.contains(key)) {
                lists.add(tmp);
            }

            set.add(key);

        }


        return lists;

    }


    public void buildTree(int[] candidates, TreeNode node) {

        for (int i = 0; i < len; i++) {

            int num = node.num - candidates[i];

            TreeNode child = new TreeNode(num, candidates[i]);

            child.diffs=new ArrayList<>(node.diffs);
            child.diffs.add(candidates[i]);

            node.children.add(child);

            if(num==0){
                res.add(child.diffs);
            }else if (num > 0) {
                buildTree(candidates, child);
            } else {
                break;
            }

        }

    }

    public static void main(String[] args) {

        int[] nums = new int[]{2, 3, 6, 7};
//        int[] nums = new int[]{2,5,2,1,2};

        new Solution().combinationSum(nums, 7);

    }
}

class TreeNode {
    Integer num;//节点值
    Integer diff;//枝叶数字，节点之间的差值
    List<TreeNode> children=new ArrayList<>();//子节点
    List<Integer> diffs=new ArrayList<>();//包括上一层所有节点的diff,爷爷 父亲 儿子

    TreeNode(int num, int diff) {
        this.num = num;
        this.diff = diff;
    }
}