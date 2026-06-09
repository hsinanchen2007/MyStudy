
class Solution {
    List<Integer> a=new ArrayList();
    public List<Integer> postorder(Node root) {
        if(root==null)
            return a;
        if(root.children!=null)
        {
            for(int i=0;i<root.children.size();i++)
            {
                Node first=root.children.get(i);
                postorder(first);
            }
        }
        a.add(root.val);
        return a;
    }
}

一个小白,见笑了
