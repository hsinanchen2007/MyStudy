### 解题思路
第一时间想到的暴力，但是觉得应该还有其他办法，然后发现等差数列实在复杂……先用暴力解决，然后再看一下等差数列到底怎么实现吧。

### 代码

```java
class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        int [] arr=new int[num_people];
        int start=1,i=0;
        while(candies!=0){
            if(candies<=start){
                arr[i%num_people]+=candies;
                return arr;
            }
            arr[i%num_people]+=start;
            candies=candies-start;
            i+=1;
            start+=1;

        }
        return arr;
    }
}
```