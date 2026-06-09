### 解题思路
* 定义记录每个元素出现次数的Map
* 定义记录每个元素首先出现的数组下表
* 定义记录每个元素最后出现的数组下表
* 最短连续数组的长度为最后出现下标减去首次出现下标+1
* 巧妙利用工具类计算输入数组的度
#### 干扰项：
* 子数组
#### 关键字： 
* 最短连续子数组
连续子数组，决定了不会出现结果不确定，递归形式去做回溯。

### 代码（优化官方解题）
java
```java
class Solution {
    public int findShortestSubArray(int[] nums) {
        //<x,count> 记录每个元素出现的次数
        Map<Integer,Integer> count = new HashMap<>();
        //<x,index>每个元素的起始位置
        Map<Integer,Integer> left = new HashMap<>();
        //<x,index>每个元素的结束位置，如果没有重复，那么left和right索引一样
        Map<Integer,Integer> right = new HashMap<>();
        for(int i = 0; i < nums.length;i++){
            int x = nums[i];
            if(Objects.isNull(left.get(x))) {
                left.put(x,i);
            }
            //记录当前元素的索引位置，如果当前元素和存在的元素一样，那么记录的索引就是最后一次出现的索引
            right.put(x,i);
            //Map有一个取值为空给默认值的函数
            count.put(x,count.getOrDefault(x,0)+1);
        }
        //利用集合工具类，获取最大数值,先计算一个最大值符合正常思维
        int degree = Collections.max(count.values());
        //最短子数组长度
        int minLength = nums.length;
        //优化遍历方法，提升执行效率
        Set<Map.Entry<Integer,Integer>> entrySet = count.entrySet();
        for(Map.Entry<Integer,Integer> entry:entrySet) {
            int x = entry.getKey();
            int xdegree = entry.getValue();
            if(xdegree == degree) {
                minLength = Math.min(minLength,right.get(x)-left.get(x)+1);
            }
        }
        return minLength;
    }
}
```

#### 弯路记录
 一开始的大脑思维，编写程序开始走偏
```java
//一开始考虑通过下面算法实现计算数组的度
private int calcDegree(int[] nums) {
        Arrays.sort(nums);
        int max = Integer.MIN_VALUE;
        int degree = 1;
        for(int i = 1; i < nums.length; i++) {
            if(nums[i-1] == nums[i]){
                degree++;
            }else {
                degree = 0;
            }
            max = Math.max(max,degree);
        }
       return max;
    }
//核心伪码，实际进入子数组计算时，思考又被发散无法实现
    public int findShortestSubArray(int[] nums) {
        int degree = calcDegree(nums);
        int subLen = subarray(nums,degree);
        return subLen;
    }
```