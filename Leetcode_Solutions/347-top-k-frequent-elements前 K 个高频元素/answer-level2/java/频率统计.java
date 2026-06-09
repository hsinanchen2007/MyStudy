### 解题思路
首先需要对数组进行频率统计，然后按频率排序可以得出结果，
排序算法按题目要求是不能使用快速排序等算法，复杂度不能满足要求，
可以使用O(n)的算法进行排序
同样的词频题目可以看 692题

### 代码

```java
class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {
        List<Integer> retList=new ArrayList<>(k);
        Map<Integer,Integer> counts=new HashMap<>();
        int max=0;//记录最大的序号，优化桶的个数
        for (Integer word:nums){
            counts.put(word,counts.getOrDefault(word,0)+1);
            if(max<counts.get(word)){
                max=counts.get(word);
            }
        }
        //桶排序
        //生成max+1个桶,最大桶数已经通过统计时得知了。
        List<Integer>[] sortList = new List[max+1];
        for(int key : counts.keySet()){
            // 获取出现的次数作为下标
            int i = counts.get(key);
            if(sortList[i] == null){
                sortList[i] = new ArrayList();
            }
            sortList[i].add(key);
        }
        for(int i = sortList.length - 1;i >= 0 && retList.size() < k;i--){
            if(sortList[i] == null) continue;
            retList.addAll(sortList[i]);
        }
        return retList.subList(0,k);
    }
}
```