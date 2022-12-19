- 使用并查集
    + 使用并查集的难点在于"并"，而不在于"查"，并就是什么两个集合能够合并，很显然对于此题是当两个值是相连的时候可以"并"，比如nums[i]=10,nums[j]=11就可以合并
    + 就是在遍历数组的时候，比如遍历到i的时候，"查" nums[i]-1 是否在集合中，如果在就合"并"

**2020.3.21更新
以上解释都是在你已经了解UnionFind并查集这个数据结构的基础上，如果了解并查集可以跳过下面直接看Code.**

### 下面简单介绍下并查集：

### UnionFindSet的用途
UnionFindSet的主要用途在于：将两个集合进行合并

#### leetcode中的题目：
- #128.最长连续序列  48.2%   困难
- #130.被围绕的区域  39.7%   中等
- #200.岛屿数量    47.6%   中等
- #547.朋友圈 55.5%   中等
- #721.账户合并    32.5%   中等
- #839.相似字符串组  31.9%   困难

通过上面几个题目，字面意思都和集合有关系，**比如连续、集合合并、区域**等

### 集合介绍
并查集的UML图如下

![UnionFindUml.png](https://pic.leetcode-cn.com/c9ec84285c2aee292db41f58994b4ffff6fe34aa88332a246a3693571053a100-UnionFindUml.png)

#### 并查集有三个属性分别是：
+ max:int ： 记录并查集集合的节点数目
+ fatherMap:HashMap<Integer,Integer> ：记录节点node和father节点的对应关系，第一个Integer是当前节点，第二个Integer是其父亲节点
+ sizeMap:HashMap<Integer,Integer> ：记录节点node和节点node所在集合的size关系

#### UnionFind的初始化及注意点
初始化max=1,处理nums中只有一个元素的情况下，默认为1, 每个节点以自己作为父节点

![UnionFindSet.png](https://pic.leetcode-cn.com/2eeb7e1face1c290ce63428fba638bfafc47472381416cb177b2eaf9842d1820-UnionFindSet.png)


#### 如何判断两个节点是否在一个集合中
当两个节点的father节点相同时，两个节点在同一个集合中。


#### 本题代码实现

```
class Solution {
    public int longestConsecutive(int[] nums) {
        if(nums==null||nums.length==0) return 0;
        
        UnionFind uf = new UnionFind(nums);
        for(int i=0;i<nums.length;i++){
            if(uf.fatherMap.containsKey(nums[i]-1)){
                uf.union(nums[i]-1,nums[i]);
            }
        }
        return uf.max;
    }
    public class UnionFind{
        int max;
        HashMap<Integer,Integer> fatherMap;
        HashMap<Integer,Integer> sizeMap;
        
        public UnionFind(int[] nums){
            max = 1;//处理nums中只有一个元素的情况下，默认为1
            fatherMap = new HashMap<>();
            sizeMap = new HashMap<>();
            
            for(int val: nums){
                fatherMap.put(val,val);
                sizeMap.put(val,1);
            }
        }
        
        public int findFather(int val){
            int father = fatherMap.get(val);
            if(father != val){
                father = findFather(father);
            }
            fatherMap.put(val,father);
            return father;
        }
        
        public void union(int a,int b){
            int aFather = findFather(a);
            int bFather = findFather(b);
            if(aFather != bFather){
               int  aSize = sizeMap.get(aFather);
               int  bSize = sizeMap.get(bFather);
                if(aSize<=bSize){
                    fatherMap.put(aFather,bFather);
                    sizeMap.put(bFather,aSize+bSize);
                }else{
                     fatherMap.put(bFather,aFather);
                    sizeMap.put(aFather,aSize+bSize);
                }
                max = Math.max(max,aSize + bSize);
            }
        }
    }
}
```
