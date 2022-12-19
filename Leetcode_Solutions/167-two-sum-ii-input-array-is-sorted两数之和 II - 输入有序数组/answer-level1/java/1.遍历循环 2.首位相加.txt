### 解题思路
此处撰写解题思路
法1，遍历数组，两两相加，判断是否等于targettarget，若相等，则将角标+1输出。执行时间很长。
法2，使用头和尾相加，只用遍历一半的数组。执行时间1s.

### 代码

```java
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        /*
        int length = numbers.length;
        for(int i=0;i<length;i++){
            for(int j=i+1;j<length;j++){
                if(numbers[j] == target -numbers[i])
                    return new int [] {i+1,j+1};
            }
        }
        throw new RuntimeException("no answer");*/
        int head =0;
        int last = numbers.length-1;
        while(numbers[head]+numbers[last] != target){
            if(numbers[head] + numbers[last] > target)
                last--;
            else
                head ++;
        }
        return new int [] {head+1,last+1};
    }
}
```