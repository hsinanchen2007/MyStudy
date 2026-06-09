### 解题思路
此处撰写解题思路

### 代码

```java

class Solution {
    public int depthSum(List<NestedInteger> nestedList) {
        int ret=depthSum(nestedList,1);  //用递归法做，递归函数中需要加上它的层数
        return ret;
    }

    public int depthSum(List<NestedInteger> nestedList,int point){
        //point指权重
        int ret=0;
        for(NestedInteger it:nestedList)
        {
            if(it.isInteger())
                ret+=it.getInteger()*point;
            else
                ret+=depthSum(it.getList(),point+1);
        }
        return ret;
    }
}
```