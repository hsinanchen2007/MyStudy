具体思路如下:

```java
基本难点就是要去掉重复的
以这个[1,1,2]为例
正常会返回6个结果：其中第一行是以下标为0的1开始，而第二行是以下标为1的1开始。
1，1，2；1，2，1
1，1，2；1，2，1
2，1，1；2，1，1
去重做法就是，在dfs时要判断i和i-1是否相等和i-1这个值是否被用。
相等和没有被用就跳过这个i的情况，直接去i+1判断。
因为没被用的话，之后就可以再用这个i-1，那就会出现重复的情况。
比如说第二行是i=1时的判断，此时i和i-1的值相等，且i-1的值没被用
那么跳过i=1这个情况，直接去i=2，所以我们就去掉了第二行所有重复的。
```

还有一个大家都会有问题的地方是：为什么这里取false或者取true，都可以通过提交呢？
```java
if(i>0&&nums[i-1]==nums[i]&&flag[i-1]==false)
    continue;
```

答案如下：
```
i-1和i的值相等，且i-1没被用过（之后可能会被用就产生重复）
flag【i-1】=false是取相等的数中最左边的那个数当ll的第一个数，
而flag【i-1】=true就是取相等的数中最右边的那个数当ll的第一个数，也就是说分别取第一行和第二行。
```

完整代码：
```java
class Solution {
    List<List<Integer>>list;
    int []nums;
    public List<List<Integer>> permuteUnique(int[] nums) {
        this.nums=nums;
        list=new ArrayList<>();
        //切记必须要先排序啊！！！！！！这样只有相邻的才可能相等，才可以判断去除！！！！！
        Arrays.sort(nums);
        List<Integer>ll=new ArrayList<>();
        boolean []flag=new boolean[nums.length];
        dfs(ll,flag,0);
        return list;
    }
    public void dfs(List<Integer>ll,boolean[]flag,int length){
        if(length==nums.length)
        {
            list.add(new ArrayList<>(ll));
            return ;
        }
        for(int i=0;i<nums.length;i++)
        {
            //这个位置用过了
            if(flag[i])
                continue;
            //i-1和i的值相等，且i-1没被用过（之后可能会被用就产生重复）
            //flag[i-1]=false是取相等的数中最左边的那个数当ll的第一个数，
            //而flag[i-1]=true就是取相等的数中最右边的那个数当ll的第一个数，也就是说分别取第一行和第二行。
            if(i>0&&nums[i-1]==nums[i]&&flag[i-1]==false)
            {
                continue;
            }
            ll.add(nums[i]);
            flag[i]=true;
            dfs(ll,flag,length+1);
            ll.remove(ll.size()-1);
            flag[i]=false;
        }
    }
}
```