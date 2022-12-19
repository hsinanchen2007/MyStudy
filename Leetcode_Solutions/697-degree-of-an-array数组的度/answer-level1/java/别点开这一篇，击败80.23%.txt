### 解题思路
方法二用时更少些。

记录一下想法，在题目没有明确限制的时候，除了尽可能要优化之外，也要大胆地去写和实现想法。

有几个一定要熟悉的：
1、计算nums中num出现的次数，用Map记录
2、找出数量最多的num（求Map最大值，可以用Collections.max 也可以用遍历）
3、边界问题一定要多思考

### 代码
方法一：
```java
class Solution {
    public int findShortestSubArray(int[] nums) {
        Map<Integer, Integer> countMap = new HashMap<>(),
            left = new HashMap(), right = new HashMap();

        int len = nums.length;

        for(int i = 0; i < len; i++){
            int num = nums[i];
            countMap.put(num, countMap.getOrDefault(num, 0) + 1);
            if(left.get(num) == null) 
                left.put(num, i);
            right.put(num, i);
        }

        int degree = 1, ans = len;
        for(Integer key : countMap.keySet()){
            int keyNum = countMap.get(key);
            if(keyNum > degree){
                degree = keyNum;
                ans = right.get(key) - left.get(key);
            }else if(keyNum == degree){
                ans = Math.min(ans, right.get(key) - left.get(key));
            }
        }
        return ans + 1;
    }
}
```

方法二：
```java
class Solution {
    public int findShortestSubArray(int[] nums) {
        HashMap<Integer, Integer> countMap = new HashMap<>();
        HashMap<Integer, int[]> indexMap = new HashMap<>();

        for(int i = 0; i < nums.length; i++){
            countMap.put(nums[i], countMap.getOrDefault(nums[i], 0) + 1);
            int[] temp = indexMap.getOrDefault(nums[i], new int[]{i, Integer.MIN_VALUE});
            temp[1] = i;
            indexMap.put(nums[i], temp);
        }

        int max = 0;
        int ans = Integer.MAX_VALUE;
        
        for(Integer key : countMap.keySet()){
            if(countMap.get(key) > max){
                max = countMap.get(key);
                ans = indexMap.get(key)[1] - indexMap.get(key)[0];
            }else if(countMap.get(key) == max){
                ans = Math.min(ans, indexMap.get(key)[1] - indexMap.get(key)[0]);
            }
                
        }
        return ans + 1;
    }
}
```