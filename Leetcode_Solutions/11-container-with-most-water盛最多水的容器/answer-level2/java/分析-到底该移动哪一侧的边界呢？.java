**输入：[1,8,6,2,5,4,8,3,7]**

![image.png](https://pic.leetcode-cn.com/fd986cf5de9847353c0c58112b528dd3dbd7df201ec4e9c93b56873c4db2f514-image.png)

阅读题目不难发现答案是由两个边界决定的，因此如果我们可以穷举所有的边界组合也就可以计算出最后的答案。
### 解题思路
如何穷举所有的边界组合？
- 对于给定一个数组，我们都可以确定一个最大范围的边界：0~length-1。
- 对于0~length-1这个范围可以计算一个储水面积。基于此范围可以每次固定一个边界然后移动另一个边界。

**代码如下**

```java
class Solution {
    public int maxArea(int[] height) {
            return dfs(height,0,height.length-1);
    }
    
    public int dfs(int[] arr,int i,int j){
        if(i>=j){
            return 0;
        }

        int current=Math.min(arr[i],arr[j])*(j-i);
        int maybe = Math.max(dfs(arr,i+1,j),dfs(arr,i,j-1));
        return Math.max(current,maybe);
    }

}
```
最后提交：超时了，对于比较大的case话很容易超时。因此需要优化，不能穷举所有的可能，需要有条理的移动。

### 解题思路
穷举所有的边界范围超时，那如何有条理的缩小范围呢？(**贪心策略**)
分析：
- 当计算1（start）与7（end）之后，很明显需要将start右移，这样会增加边界值会使结果正向靠近。
- 此时8（start）与7（end）计算为49之后，如何移动呢？
```
容易陷入沉思：start向右边走8变为6减少2，但是7变为3时减少了4，而且最小边界也由原来的7变为了3。  
直觉告诉应该将8移动为6（start++）？思考错误在哪里呢？我们考虑降低了多少其实是没有意义的，  
需要结合原来的基数一起考虑，例如：1万千减少1万与1000减1而言，还是前者大！！！！
此时换种思路理解，到底应该移动谁呢？
移动小的。为什么呢？反向思考:
如果我们移动大的边界BIGGER（另一个边界叫SMALLER），那么在之后遇见一个大于等于该BIGGER边界的值的话，此时SMALLER便成为了瓶颈，  
所以每次都移动小的值，小的值变的更小的话跳过即可，如果遇见大的值，就需要计算跟之前的存储面积做一下比较，  
大则替换，小则跳过。
```


### 代码

```java
class Solution {
    public int maxArea(int[] height) {
        int start = 0,end = height.length-1;
        int maxV =0;
        while(start<end){
            maxV =Math.max(maxV,Math.min(height[start],height[end])*(end-start));
            if(height[start]>height[end])
                end--;
            else 
                start++;
        }

        return maxV;
    }
    
 

}
```