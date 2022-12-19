```
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public List<TreeNode> generateTrees(int n) {
        return generateTrees(1,n);
    }

   private List<TreeNode> generateTrees(int start, int end)
  {
    if(start>end){
      return new ArrayList<TreeNode>();
    }
    if(start == end){
      List<TreeNode> temperesult = new ArrayList<>();
      temperesult.add(new TreeNode(start));
      return temperesult;
    }

    List<TreeNode> result = new ArrayList<>();
    for(int i=start;i<=end;i++){
      List<TreeNode> left = generateTrees(start,i-1);
      List<TreeNode> right = generateTrees(i+1,end);
      if(left.size()>0&&right.size()>0){
        for(int j=0;j<left.size();j++){
          for(int l = 0;l<right.size();l++){
            TreeNode temp = new TreeNode(i);
            temp.left = left.get(j);
            temp.right = right.get(l);
            result.add(temp);
          }
        }
      }
      if(left.size()==0){
        for(int l = 0;l<right.size();l++){
          TreeNode temp = new TreeNode(i);
          temp.right = right.get(l);
          result.add(temp);
        }
      }
      if(right.size()==0){
        for(int j=0;j<left.size();j++){
          TreeNode temp = new TreeNode(i);
          temp.left = left.get(j);
          result.add(temp);
        }
      }
    }
    
    return result;
  }
    }
```
