![image.png](https://pic.leetcode-cn.com/14980c10626d35f858574fcfcc2c3aae196f4359d951f44e7abc1c8496494ab8-image.png)

 public List<TreeNode> generateTrees(int n) {
      //1.采用递归回溯的方法，情况比较复杂，同时存在重复计算
        //2.动态规划，dp[i]代表1-i节点组成的二叉搜索树，需要根据情况改变数值，遍历二叉树改变数值
        //3.动态规划，dp[i][j]代表长度为i，起点为j（j<n-i）的树的集合
        //List<TreeNode>[][] dp=new List<TreeNode>[n+1][n+1];不能创建list的数组
        //二维动态规划
        if(n==0){
            List<TreeNode> ans=new ArrayList<>();
            return ans;
        }
        List<List<List<TreeNode>>> lslsls=new ArrayList<>();
        //初始化动态规划数组
        List<List<TreeNode>> lsls0=new ArrayList<>();
        for(int i=0;i<n+1;i++){
            List<TreeNode> ls0=new ArrayList<>();
            ls0.add(null);  
            lsls0.add(ls0);          
        }
        lslsls.add(lsls0);
        List<List<TreeNode>> lsls1=new ArrayList<>();
        for(int i=1;i<n+1;i++){
            List<TreeNode> ls1=new ArrayList<>();
            ls1.add(new TreeNode(i));  
            lsls1.add(ls1);          
        }
        lslsls.add(lsls1);
        //开始计算，直到长度为n
        for(int m=2;m<n+1;m++){
            //计算长度为m二叉树
            List<List<TreeNode>> lslsm=new ArrayList<>();
            for(int start=1;start<=n-m+1;start++){
                //计算范围起点为start的二叉树
                List<TreeNode> list=new ArrayList<>();
                for(int x=start;x<m+start;x++){
                    //计算根节点为x二叉树                   
                    List<TreeNode> templ=lslsls.get(x-start).get(start-1);//长度为x-1，起点为1
                    List<TreeNode> tempr=lslsls.get(m+start-x-1).get(x);//长度为n-x，起点为x+1
                    for(TreeNode lnode:templ){
                        for(TreeNode rnode:tempr){
                            TreeNode root=new TreeNode(x);
                            root.left=lnode;
                            root.right=rnode;                            
                            list.add(root);
                        }
                    }                    
                }
                lslsm.add(list);   
            }
            lslsls.add(lslsm);         
        }
        return lslsls.get(n).get(0);   
     }