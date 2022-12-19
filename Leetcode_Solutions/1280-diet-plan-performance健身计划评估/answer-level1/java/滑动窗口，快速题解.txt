```java []
class Solution {
    public int dietPlanPerformance(int[] calories, int k, int lower, int upper) {
        int sum = 0;
        int grade = 0;
        for(int i = 0;i<calories.length;i++){
            //保持窗口大小为k
            if(i>(k-1)){
                //System.out.println("i "+i+" "+sum);
                if(sum < lower) grade--;
                if(sum > upper) grade++;
                sum-=calories[i-k];
                
            }
            sum+=calories[i];
        }
        //for 循环内未对最后一次符合条件情况做加减分判断
        if(calories.length-1>=k-1){
                if(sum < lower) grade--;
                if(sum > upper) grade++;            
        }
        return grade;
    }
}
```

