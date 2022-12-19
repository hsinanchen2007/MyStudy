### 解题思路
利用hash表，一遍for循环
### 代码

```java
class Solution {
    public int[] twoSum(int[] nums, int target) {

        //创建Map对象
        //数据采用的哈希表结构
        Map<Integer,Integer> map= new HashMap<Integer,Integer>();

        for(int i=0;i<nums.length;i++)
        {
            int index=target-nums[i];
            if(map.containsKey(index))
                return new int [] {map.get(index),i};//关键是谁先谁后的问题
            map.put(nums[i],i);
        }

        throw new IllegalArgumentException("no two sum solution!");
        //抛出异常
    }
}
```

### 解题思路
利用hash表，两遍for循环
### 代码

```java
class Solution {
    public int[] twoSum(int[] nums, int target) {

        //创建Map对象
        //数据采用的哈希表结构
        Map<Integer,Integer> map= new HashMap<Integer,Integer>();
        
        int index;


        //第一遍循环
        for(int i=0;i<nums.length;i++)
            map.put(nums[i],i);//nums[i]做为index，i作为value
        
        //第二遍循环
        for(int i=0;i<nums.length;i++)
        {
            index=target-nums[i];
            if(map.containsKey(index) && map.get(index)!=i)
                return new int[] {i,map.get(index)};
            
        }

        //抛出异常
        throw new IllegalArgumentException("no two sum solution~");


    }
}
```




### 解题思路
暴力搜索
### 代码

```c
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int part_1,part_2; //记录找到的第一个数和第二个数的下标
    int i,j;
    int *result = (int *)malloc(sizeof(int)*2);//分配空间

    for(i=0;i<numsSize;i++)
    {
        for(j=0;j<numsSize;j++)
        {
            if(i!=j) //i==j的话，直接跳过
            {
                if((nums[i]+nums[j])==target)
                {
                    if(i>j)
                    {
                        result[0]=j;
                        result[1]=i;
                    }
                    else
                    {
                        result[0]=i;
                        result[1]=j;
                    }
                    *returnSize=2;
                }

            }
        }

    }
    return result;
}
```