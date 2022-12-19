执行结果：
执行用时 :2 ms, 在所有 Java 提交中击败了92.46% 的用户
内存消耗 :35.8 MB, 在所有 Java 提交中击败了40.23%的用户

感觉是很好的思路了，不知道为啥子不能超过100

思路：我用了两个栈来实现，一个栈里面是当代节点，一个栈里面放下一代节点
栈上面的节点先出栈，也就是先访问，访问完把子节点放到子代栈里面。
假设在第5行的时候是从左往右遍历的，那么第五行最左边的节点在当代栈的最上面，第一个访问
访问完它之后把它的左子节点压在子代栈的最下面，那么它的左子节点在访问第6行的时候就是最后一个访问的了，
从而实现锯齿形遍历。
细节：从左往右遍历时，是先放左子节点再放右子节点。从右往左遍历时，是先放右子节点。因为他们是交替进行的，我选择用一个布尔值来标记遍历方向。

```
    //首先要明确锯齿形遍历的要求  父亲第一个遍历的  那么他儿子应该是最后一个遍历的，
        // 这个用栈来实现应该比较更顺手  先进后出
        boolean flag=true;// true表示改行是从左往右遍历的   那么他的儿子辈应该是从右往左遍历
        List<List<Integer>> res=new ArrayList<>();
        if (root==null)return res;//空树
        Stack<TreeNode> corr=new Stack<>();
        Stack<TreeNode> sons=new Stack<>();
        corr.add(root);
        List<Integer> tmp=new ArrayList<>();
        while (true){
            while (!corr.isEmpty()){//当前栈还有节点
                TreeNode pop = corr.pop();
                if (flag){//从左往右遍历  此时把左儿子压在最下面
                    tmp.add(pop.val);//提取当前节点的值
                    if(pop.left!=null)sons.push(pop.left);
                    if(pop.right!=null)sons.push(pop.right);
                }
                else {//否则  把右儿子压在栈最下面
                    tmp.add(pop.val);
                    if(pop.right!=null)sons.push(pop.right);
                    if(pop.left!=null)sons.push(pop.left);
                }
            }
            if (sons.isEmpty()){//断子绝孙没有后代了  应该退出
                res.add(tmp);//不管怎么样  把当代的所有值加到结果集
                break;
            }else {//否则  子代称为当前代
                //  并且调整方向  把上一代结果存起来并指向新列表
                Stack<TreeNode> exchange=sons;
                sons=corr;
                corr=exchange;
                flag=(flag)?false:true;
                res.add(tmp);
                tmp=new ArrayList<>();
            }
        }
        return res;
```
