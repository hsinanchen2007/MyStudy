### 解题思路


### 代码

```java
class Solution {
    public List<List<Integer>> groupThePeople(int[] groupSizes) {
        List<List<Integer>> result=new ArrayList<>();               //结果链表
        HashMap<Integer,Integer> sizeAndCount=new HashMap<>();      //一共有多少个人的组尺寸是相同的
        HashMap<Integer,List<Integer> >sizeAndIndex=new HashMap<>(); //组尺寸相同的人的索引
        List list;

        //遍历一遍groupSizes,找出每个尺寸的组的总人数，以及每个尺寸的组的所有人的索引
        for(int i=0;i<groupSizes.length;i++)
        {
            sizeAndCount.put(groupSizes[i],sizeAndCount.getOrDefault(groupSizes[i],0)+1);
            list=sizeAndIndex.getOrDefault(groupSizes[i],new ArrayList<Integer>());
            list.add(i);
            sizeAndIndex.put(groupSizes[i],list);
        }

        //根据每个组尺寸以及每组的总人数算出总共有多少个尺寸相同的组，然后为每个组分配数量等于其尺寸的人（即索引），然后加入result中
        for(Integer i:sizeAndCount.keySet())
        {
            int Count=sizeAndCount.get(i);
            int groups=Count/i;
            for(int j=0;j<groups;j++)
            {
                List group=new ArrayList<Integer>();
                for(Integer interger:sizeAndIndex.get(i).subList(i*j,(j+1)*i))
                    group.add(interger);
                result.add(group);
            }
        }
            return result;
    }
}
```