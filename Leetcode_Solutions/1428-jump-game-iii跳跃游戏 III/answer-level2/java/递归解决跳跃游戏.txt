### 解题思路
其实可以做个归类，最先开始做的图的dfs，对递归有个大致的概念，能照着模板画瓢，然后是通过看书，递归针对的是有子问题解的一类问题，通过不断的寻找子问题解，来找到问题的解，有递推也有回溯，然后根据边界条件返回结果；
对于这道题，我们可以假设解为一个二叉树，节点为每个数组元素，左子树是坐标（i-arr[i]），右子树为（i+arr[i]），超出数组的下标为null节点，所以问题变成了从start根节点寻找0节点，所以以dfs的递归解法去做即可，我这里是先左后右，思路差不多就是这样

### 代码

```java
class Solution {
    public boolean canReach(int[] arr, int start) {
        boolean result=isZero(arr,start,new ArrayList<>());
        return result;
    }
    public boolean isZero(int[] arr,int i,List<Integer> seen){
        if(arr[i]==0){
            return true;
        } 
        seen.add(i);
        // 左枝结果
        boolean resultAdd=false;
        // 右枝结果
        boolean resultDelete=false;
        if((i+arr[i]<=arr.length-1)&&!seen.contains(i+arr[i])){
            resultAdd=isZero(arr,i+arr[i],seen);
        }
        if(resultAdd){
            return true;
        }
        if((i-arr[i]>=0)&&!seen.contains(i-arr[i])){
            resultDelete=isZero(arr,i-arr[i],seen);
        }
        if(resultDelete){
            return true;
        }
        return false;
    }
}
```