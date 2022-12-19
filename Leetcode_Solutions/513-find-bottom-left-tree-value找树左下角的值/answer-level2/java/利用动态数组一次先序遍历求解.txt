![111.png](https://pic.leetcode-cn.com/b784fb41809268d18b0e1c10e71bc8ccdb473bf2e3f893aaeed3230397c21c3e-111.png)

```
import java.util.ArrayList;
//突然发现没有必要用HashMap,直接用ArrayList即可
class Solution {
    public int findBottomLeftValue(TreeNode root) {
        ArrayList<Integer> al = new ArrayList<Integer>();
        //利用ArrayList存储每一层最左边的节点
        addElement(al,root,0);
        int len = al.size();
        int result = al.get(len-1);
        return result;
    }
    
    public void addElement(ArrayList<Integer> al,TreeNode root,int i){
        if(root == null){
            return;
        }
        if(al.size() <= i){//如果数组大小小于层数，说明当前层还没有存入节点
            al.add(root.val);//添加
        }
        addElement(al,root.left,i+1);//遍历左子树
        addElement(al,root.right,i+1);//遍历右子树
    }
}
```


![111.png](https://pic.leetcode-cn.com/0a9aa3c4fc09172e75ed6c4ca5bb3d4457ed4d8c625abda6b93df26e5aaafd41-111.png)
（原答案）解题思路：
利用树的中序遍历，实参中保留层数
HashMap用来存储每一层最左边的值
最后遍历HashMap找到最深层最左边的树即可
```
import java.util.HashMap;

class Solution {
    public int findBottomLeftValue(TreeNode root) {
        HashMap<Integer,Integer> hm = new HashMap<Integer,Integer>();
        //利用HashMap存储每一层最左边的节点
        addElement(hm,root,0);
        int result = 0;
        for(int i=0;i<10000;i++){
            if(hm.containsKey(i)){
                result = hm.get(i);
            }else{
                break;
            }
        }
        return result;
    }
    
    public void addElement(HashMap<Integer,Integer> hm,TreeNode root,int i){
        if(root == null){
            return;
        }
        if(hm.containsKey(i) != true){//如果不存在，说明是最左边的节点
            hm.put(i,root.val);//添加
        }
        addElement(hm,root.left,i+1);//遍历左子树
        addElement(hm,root.right,i+1);//遍历右子树
    }
}
```
菜狗解析，不懂就问，有问题call我
