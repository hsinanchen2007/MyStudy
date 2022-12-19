### 解题思路

个人觉得难到时不太难，只是注意几个细节：  

1、没有旋转的情况  
2、所有数字都相同的情况  
3、只有一个数字的情况  

剩下的就是从后面往前面找，当到某一个数字它的前面一个数字比当前数字大的时候，那最小数字就是当前数字了。

### 代码

```java
class Solution {
    public int minArray(int[] numbers) {
        if(numbers.length == 1){
            return numbers[0];
        }

        int end = numbers.length - 1;
        if(numbers[0] < numbers[end] ){//没旋转
            return numbers[0];
        }

        int minNum = numbers[0];

        while(end >= 1){
            if(numbers[end] < numbers[end - 1]){
                return numbers[end];
            }
            end --;
        }

        return minNum;

    }
}
```