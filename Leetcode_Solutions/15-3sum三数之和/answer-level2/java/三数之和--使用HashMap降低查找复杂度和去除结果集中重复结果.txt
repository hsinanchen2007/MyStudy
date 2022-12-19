### 解题思路
1：先将数组排序
2：求三元和为0，此题以0为界，将数组分解成正数、0、负数三部分
3：借助于HashMap，将查找的复杂度降低为线性
4：借助于map排除最后结果中的重复记录
5：标记一个最大值一个最小值，用以减少循环次数
### 过程：
1：如果有0元素，则：循环正数，查找负数集合中是否有对应的相反数，有则加入结果集
2：如果有0元素，判断0元素的个数如果大于等于3，则将[0,0,0]加入结果集
3：判断两负一正的情况，双循环负数列表left，从绝对值小的部分开始循环，当两个负数之和的绝对值大于最大值，则跳出内层循环，否则在正数列表中查找两个负数之和的绝对值（使用HashMap），查找到则加入结果集
4：判断两正一负的情况，双循环正数列表right，当两个正数之和大于最小值的绝对值，则跳出内层循环，否则在负数列表中查找两个正数的和的相反数，查找到则加入结果集
5：从HashMap的values中返回结果集

### 循环次数
实测循环次数比双指针的两层for循环低一半以上

### 代码

```java
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        if(nums == null || nums.length==0) return new ArrayList<>();
        List<Integer> left  = new ArrayList<>();
        List<Integer> right = new ArrayList<>();
        Map<Integer,Integer> leftMap = new HashMap<>();
        Map<Integer, Integer> rightMap = new HashMap<>();
        Map<String, List<Integer>> resultMap = new HashMap<>();
        boolean zeroFlag = false;
        Arrays.sort(nums);
        int zeroTims = 0;
        int leftMin = nums[0];
        int rightMax = nums[nums.length-1];
        if(leftMin > 0 || rightMax < 0) return new ArrayList<>();
        for (int num : nums) {
            if(num > 0){
                right.add(num);
                rightMap.put(num,num);
            }else if(num < 0){
                left.add(num);
                leftMap.put(num,num);
            }else{
                zeroTims++;
                zeroFlag = true;
            }
        }
        if(zeroFlag){
            for (Integer a : right) {
                if(leftMap.get(-a) != null){
                    resultMap.put(-a + ",0," + a, Arrays.asList(new Integer[]{-a,0,a}));
                }
            }
            if(zeroTims > 2){
                resultMap.put("0,0,0", Arrays.asList(new Integer[]{0,0,0}));
            }
        }
        int first;
        int second;
        for (int i = left.size() - 1 ; i >= 0 ; i--) {
            for (int j = i-1; j >= 0; j--) {
                if(left.get(i) + left.get(j) < -rightMax){
                    break;
                }
                if(rightMap.get(-(left.get(i) + left.get(j))) != null) {
                    first = left.get(j);
                    second = left.get(i);
                    resultMap.put(first + "," + second + "," + (-(first + second)), Arrays.asList(new Integer[]{first,second,-(first + second)}));
                }
            }
        }
        for (int i = 0; i < right.size(); i++) {
            for (int j = i+1; j < right.size(); j++) {
                if(right.get(i) + right.get(j) > -leftMin){
                    break;
                }
                if(leftMap.get(-(right.get(i) + right.get(j))) != null) {
                    first = right.get(i);
                    second = right.get(j);
                    resultMap.put((-(first + second)) + "," + first + "," + second, Arrays.asList(new Integer[]{-(first + second),first,second}));
                }
            }
        }
        return new ArrayList<>(resultMap.values());
    }
}
```