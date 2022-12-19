![image.png](https://pic.leetcode-cn.com/825af3b727f38934068739c70e46f22c4e1c610f1b7d2a13c30c72827dfd3a4f-image.png)
### 解题思路
最后一步已知的情况下，每一行依次退步找到上一行的节点

### 代码

```java
class Solution {
    List<Integer> pathList = new LinkedList<>();
    public List<Integer> pathInZigZagTree(int label) {
        int head = 1;
        int row = 1;
        while(head*2<=label){
            head*=2;
            row++;
        }
        fillPathInList(row,head,label);
        return pathList;
    }
    private void fillPathInList(int row,int head,int temp){
        if(row==1){
            pathList.add(1);
            return;
        }
        int newTemp;
        int index = (temp-head)/2+1;
        newTemp = head-index;
        fillPathInList(row-1,head/2,newTemp);
        pathList.add(temp);
    }
}
```