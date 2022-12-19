### 解题思路
从第一个元素到最后一个元素，再回到第一个元素，逐个计算糖果发放个数，
第i次发放的糖果个数为i个，给元素位置为i-1的数组值+i
如果糖果个数不够，就发放剩余糖果，结束循环

### 代码

```java
class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        if(num_people<1){
            return null;
        }
        
        int[] result=new int[num_people];
        
        int i=0;
        while(candies>0){
            if(candies>=i+1){
                result[i%num_people]+=i+1;
                candies-=i+1;
            }else{
                result[i%num_people]+=candies;
                break;
            }
            i++;
        }
        
        return result;
    }
}
```