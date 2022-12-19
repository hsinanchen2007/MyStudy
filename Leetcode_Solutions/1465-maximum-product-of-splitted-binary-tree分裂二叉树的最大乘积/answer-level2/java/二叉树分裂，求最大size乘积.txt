```java
/*
import java.util.*;
class Solution {
    public ArrayList<Long> sizeList = new ArrayList<>();
    public long process(TreeNode root){
        long size = 0;
        if(root == null){
            return 0;
        }
        size = root.val +process(root.left)+process(root.right);
        sizeList.add(size);
        return size;
    }
    public int maxProduct(TreeNode root) {
        long sumSize = process(root);
        long max = 0;
        long tmp = 0;
        for(long size : sizeList){
            tmp = size * (sumSize - size);
            max = Math.max(max, tmp);
        }
        return (int)(max % (1e9 + 7));
    }
}
*/
//改进，maxProduct算法，利用均值不等式减少求最大成绩的操作
import java.util.*;
class Solution {
    public ArrayList<Long> sizeList = new ArrayList<>();
    public long process(TreeNode root){
        long size = 0;
        if(root == null){
            return 0;
        }
        size = root.val +process(root.left)+process(root.right);
        sizeList.add(size);
        return size;
    }
    public long differ(long sumSize, long size){
        long diff = sumSize - 2* size;
        return (diff > 0) ? diff:-diff;
    }
    public int maxProduct(TreeNode root) {
        long sumSize = process(root);
        int tmp = 0;
        for(int i=0; i < sizeList.size();i++){
            if(differ(sumSize,sizeList.get(i))-differ(sumSize,sizeList.get(tmp)) < 0){
                tmp = i;
            }
        }
        long max = (long)(sizeList.get(tmp) * (sumSize - sizeList.get(tmp)));
        return (int)(max % (1e9 + 7));
    }
}
```
