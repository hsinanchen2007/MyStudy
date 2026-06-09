### 解题思路
此处撰写解题思路
并查集算法:
用集合中的某个元素代表这个集合,该元素成为集合的代表元
一个集合内的所有元素组织成代表元的为根的树形结构
对于每一个元素parent[x]指向x在树形结构上的父亲节点,如果x是跟节点,则令parent[x]=x.
对于查找操作,加上需要确定x所在的集合,也就是确定集合的代表元,可以沿着parent[x]不断在树形结构中向上移动,知道到达根节点.
判断两个元素是否属于同一结合,只需要判断他们的代表元是否相同
压缩路径:
为了加快查找速度,查找时将x到根路径上的所有点的parent设为根节点,该优化方法叫压缩路径.
并查集的思路:[https://blog.csdn.net/liujian20150808/article/details/50848646](https://blog.csdn.net/liujian20150808/article/details/50848646)
合并相同行与列,所有石头在不同行不同列,那么移动0次
因此只需要找出通过同一行/同一列关系连接起来的集合数量，用总数减去集合总数就是move操作的次数。
### 代码

```java
class Solution {
    //并查集数组,因为题中给出0 <= stones[i][j] < 10000,[0,10000)表示x轴,[10000,20000)表示y轴
    private int[] parent = new int[20000];

    public int removeStones(int[][] stones) {
        int length=stones.length;
        //如果只有一个点不需要移动
        if(length<=1){
            return 0;
        }
        //初始化数组
        for(int i=0;i<parent.length;i++){
            parent[i]=i;
        }
        //建立关系
        for(int i=0;i<length;i++){
            //y轴,从10000开始计数,10000以后代表是y轴
            union(stones[i][0],stones[i][1]+10000);
        }
        //创建一个去重的set,set.size()就是有多少集合
        Set<Integer> set=new HashSet<>();
        for(int i=0;i<length;i++){
            //因为stones[i][j]与stones[i][0]在并查集中的parent[]中指向的值一致(因为相同x轴和y轴的在一个集合中)
            //所以直接使用stones[i][0]代替stones[i][j];
            set.add(findFather(stones[i][0]));
        }
        //数组长度-set.size()便是移动的次数
        return length-set.size();
    }
    //查找父亲
    private int findFather(int x) {
        int a=x;
        //如果x!=parent[x]说明x不是最高节点,当x=parent[x],说明x是最高节点
        while(x!=parent[x]){
            x=parent[x];
        }
        //压缩路径,把同一个顶级父节点下面的所有子节点直接都指向父节点,避免了不需要的查找
        while(a!=parent[a]){
            int temp=a;
            a=parent[a];
            parent[temp]=x;
        }
        return x;
    }
    //a代表x轴的坐标,b代表y轴坐标
    private void union(int a, int b) {
        //建立关系,同一个(a,b)确定一个点,所以在parent[]数组中指向的值一致
       int aFind=findFather(a),bFind=findFather(b);
        //如果在parent[]中不一致,需要进行复制进行联合起来
       if(aFind!=bFind){
          parent[aFind]=bFind; 
       }
    }
}
```