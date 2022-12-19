### 解题思路
1. 利用集合唯一性的特点，建立一个Integer类型的集合set
2. 遍历candies[] ，将每个元素添加到set集合中(candies（） 为int类型，无法直接添加到set集合中，运用valueOf（）方法进行转化即可)
3. 得出集合set的长度res
4. 判断res是否 小于等于 candies.length/2 ; 是的话则返回res， 否则返回candies.length/2



### 代码

```java
class Solution {
    public int distributeCandies(int[] candies) {
        Set<Integer> set = new HashSet<>();
        for(int i=0; i<candies.length; i++)
            set.add(Integer.valueOf(candies[i]));
        int res = set.size();
        if(res<=candies.length/2)
            return res;
        return candies.length/2;
    }
}
```