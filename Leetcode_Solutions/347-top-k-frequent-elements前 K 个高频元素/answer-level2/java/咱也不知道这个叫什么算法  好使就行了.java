先看一下执行结果：
执行用时 :21 ms, 在所有 Java 提交中击败了96.29% 的用户
内存消耗 :40.6 MB, 在所有 Java 提交中击败了96.12%的用户

应该都是可以看得过去的
思路是这样的：
首先要明确题目的意思：他说的k是合理的  这就说明两个人出现次数相同的话，要么两个人都符合，要么都不符合，这一点狠狠很重要
1.咱先用一个map来记录每一个数字出现的次数
2.在第一次遍历填充map的同时  通过一个maxCount 变量来记录最大的频数
3.我们通过二分查找（从0到maxCount）某个数字满足 有k个数字出现的次数是大于等于他的 namename这些数字就是结果了

可取点：
        定义了一个maxCount变量！！！
代码如下：
```
public List<Integer> topKFrequent(int[] nums, int k) {
        Map<Integer,Integer> map=new HashMap<>();
        int maxCount=1;//这个是用来记录最高频次数的
        for (int num : nums) {
            if (map.containsKey(num)) {
                Integer tmp = map.get(num);
                map.put(num, tmp +1);
                if (tmp+1 >maxCount)maxCount= tmp+1;
            } else map.put(num, 1);
        }
        Set<Map.Entry<Integer, Integer>> set = map.entrySet();
        int begin=0;int end=maxCount;int mid=(begin+end)/2;
        while (begin<=end){
            int count=0;
            for (Map.Entry<Integer, Integer> entry : set)
                if (entry.getValue()>=mid)count++;
            if (count==k)   {
                List<Integer> res=new ArrayList<>();
                for (Map.Entry<Integer, Integer> entry : set)
                    if (entry.getValue()>=mid)res.add(entry.getKey());
                return res;
            }
            else if (count>k)begin=mid+1;
            else end=mid-1;
            mid=(begin+end)/2;
        }
        return new ArrayList<>();
```
