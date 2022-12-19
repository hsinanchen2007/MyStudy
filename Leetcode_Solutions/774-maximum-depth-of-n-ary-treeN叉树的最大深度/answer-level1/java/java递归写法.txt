```
public int maxDepth(Node root) {
        if(root==null){
            return 0;
        }else{
            int maxDep=0;
            for(Node node:root.children){
                int currDep=maxDepth(node);
                maxDep=currDep>maxDep?currDep:maxDep;
                //注意不要将上面两行代码简化为下面的写法,否则会超时，因为执行了两次maxDepth(node)
                //maxDep=maxDepth(node)>maxDep?maxDepth(node):maxDep
            }
            return maxDep+1;
        }
    }
```
