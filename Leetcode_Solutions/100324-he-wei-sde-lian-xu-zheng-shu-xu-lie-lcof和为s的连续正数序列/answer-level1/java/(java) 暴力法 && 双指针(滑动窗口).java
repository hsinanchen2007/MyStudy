# 暴力法
直接的遍历所有的可能的序列，保存结果
```
class Solution {
    public int[][] findContinuousSequence(int target) {
        List<int[]> res = new ArrayList<>();

        if(target <= 2){
            return null;
        }

        for(int i = 1;i < target/2 + 1;i ++){
            int temp = target;
            int count = i;
            while(temp > 0){
                temp = temp - count;
                count++;
            }
            if(temp == 0){
                int[] arr = new int[count - i];
                int a = i;
                for(int j = 0;j < arr.length;j++){
                    arr[j] = a;
                    a++;
                }
                res.add(arr);
            }
        }
    
        return res.toArray(new int[0][]);

    }
}
```
# 双指针
题目要求的是连续的序列，在给定题目条件是数组时(该题类似于数组)，很可能使用双指针，滑动窗口来进行解题

min，max分别表示连续序列的上下边界
max - min + 1 为连续序列的长度
sum 表示连续序列的和


- 当sum小于目标值，max++，sum += max
- 当sum大于目标值，sum -= min, min++
- 当sum等于目标值，进行状态的重置，sum -= min, min ++


```java
class Solution {
    public int[][] findContinuousSequence(int target) {
        if(target <= 2){
            return null;
        }
        List<int[]> res = new ArrayList<>();
        // 使用双指针
        int min = 1;  
        int max = 2;
        int sum = min + max;
        while(min < max && max < target){
            if(sum < target){
                // sum小于目标值，max++，sum += max
                max++;
                sum += max;
            }
            else if(sum > target){
                // sum大于目标值，sum -= min, min++
                sum -= min;
                min++;
            }
            else{
                // sum == target
                // 使用temp保存结果
                int[] temp = new int[max - min + 1];
                int j = min;
                for(int i = 0;i < temp.length;i++){
                    temp[i] = j++;
                }
                // 添加结果
                res.add(temp);

                // 连续序列的头部 min++，sum -= min, 重复上面步骤
                sum -= min;
                min++;
            }
        }
        return res.toArray(new int[0][]);

    }
}
```