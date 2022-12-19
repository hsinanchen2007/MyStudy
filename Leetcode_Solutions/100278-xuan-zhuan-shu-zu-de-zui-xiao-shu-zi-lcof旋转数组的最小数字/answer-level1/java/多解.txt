### 解题思路
此处撰写解题思路
1：排序输出numbersnumbers【0】
2: 二分法
3：直接循环处理。

### 代码

```java
class Solution {
    public int minArray(int[] numbers) 
    {
         /*
        Arrays.sort(numbers);
        return numbers[0];
        
        int n=0,len = numbers.length-1;
        int mid =0;
        while(n < len){
            mid = (len - n) /2 ;
        if(numbers[mid] < numbers[len]){
           len = mid;
        }
        else if(numbers[mid] > numbers[len]){
            n = mid + 1;
        }
        else 
            len--;
        
        }
        return numbers[n];*/

        for(int i=0;i< numbers.length-1;i++)
        {
            if(numbers[i] > numbers[i+1])
            {

                return numbers[i+1];

            }
        }
                return numbers[0];
        

    }
}
```