### 解题思路
![image.png](https://pic.leetcode-cn.com/e488c530d3701fabcabedf275180e4f546fafd9df370ee22964dc6410e0157f9-image.png)
贪心策略，从当前集合中，挑取使当前集合尽可能地扩大的节点，然后下一次从新加入的节点中重复。
即在当前可配送的范围内，将快递送到一个能将快递送得更远的站点。
### 代码

```java
class Solution {
    public int jump(int[] nums) {
        int endIndex=nums.length-1;
        int size=nums[0];//覆盖范围
        int count=0;
        int curIndex=0;
        int lastIndex=-1;
        while(curIndex!=endIndex){
            if(curIndex+nums[curIndex]>=endIndex){
                count++;
                break;
            }
            //否则使得当前集合尽可能扩大
            int maxNextIndex=0;
            int maxNext=0;
            //从上一个末尾出发，不重复遍历可以O（n)
            for(int i=lastIndex+1;i<=curIndex+nums[curIndex];i++){
                if(i+nums[i]>maxNext) {
                    maxNextIndex=i;
                    maxNext=i+nums[i];
                }
            }
            count++;
            lastIndex=curIndex+nums[curIndex];//记录边界
            curIndex=maxNextIndex;
        }
        return count;
    }
}
```