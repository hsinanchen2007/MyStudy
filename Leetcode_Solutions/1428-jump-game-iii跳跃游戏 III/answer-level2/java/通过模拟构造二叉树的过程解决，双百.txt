![a.png](https://pic.leetcode-cn.com/e7de6ff05088028532bf6f59a7e11af1655e53126479d580fd639476c2b3467e-a.png)


### 解题思路
从题目要求，每到一个索引可以有两种选择，很容易想到就是构造二叉树的过程。在构造过程中，如果遇到值为0的索引就是找到了。如果输入无解的话，在构造过程中会出现重复的索引，在第一次出现重复索引的时候停止构造二叉树就可以了。

关键部分都有注释。

### 代码

```java
class Solution {
    //保存出现过的数组索引
    private Set<Integer> indexes=new HashSet();
    private boolean can = false;

    public boolean canReach(int[] arr, int start) {
        if(arr==null||start>arr.length-1){
            return false;
        }
        buildTree(arr,start);
        return this.can;
    }

    private void buildTree(int[] arr,int index){
        if(this.can){//如果已经找到了值为0的索引，立即停止构造，否则后面可能会覆盖真实的结果
            return;
        }
        if(arr[index]==0){//找到了值为0的索引
            this.can=true;
            return;
        }
        if(this.indexes.contains(index)){//出现了重复索引
            this.can=false;
            return;
        }
        this.indexes.add(index);
        int left = index-arr[index];
        int right = index+arr[index];
        if(left>=0){
            buildTree(arr,left);
        }
        if(right< arr.length){
            buildTree(arr,right);
        }
    }
}
```