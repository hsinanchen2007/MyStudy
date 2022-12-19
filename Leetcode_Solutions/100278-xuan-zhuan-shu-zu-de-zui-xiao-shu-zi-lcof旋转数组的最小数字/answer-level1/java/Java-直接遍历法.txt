情况一：给出的数组是两段的递增数列
情况二：给出的数组是递增数组

情况一：找到前一个大于当前元素，比较第一个和当前元素，返回最小即可
情况二：如果查找到数组的最后，直接返回第一个元素即可。

```
class Solution {
    public int minArray(int[] numbers) {
        int i = 1;
        while(i < numbers.length){
            if(numbers[i - 1] <= numbers[i]){
                i++;
            }else{
                return Math.min(numbers[0], numbers[i]);
            }

        }
        return numbers[0];
    }
}
```
