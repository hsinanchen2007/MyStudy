### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] distributeCandies(int candies, int num_people) {
           int[] arr = new int[num_people];
           int c = 0;
           int sum = 0;
  
           for(int i = 1;i<=num_people;i++){
               if(candies - sum > num_people*c+(i)){   //还能正常分配
                  
                   arr[i-1] = arr[i-1]+(num_people*c+(i));
                   sum+=num_people*c+(i);
               }else{
                  
                    arr[i-1] = arr[i-1]+(candies - sum);   //不能正常分配 就把剩余的赋值
                     sum+=candies - sum;
                    break;
               }
              // sum += arr[i-1];
               if(i == num_people){              //每分配一轮后 从1又开始分
                   i = 0;
                   c++;
               }
           }
          
           return arr;

          

    }

   
}
```