### 解题思路
K个工人中，肯定是选择成本最高的工人（即(wage/quality)最大的工人）作为基准
在保证单位成本wage/quality的前提下，使用的quality越少，总成本就越少

所以，先对各个工人的单位成本进行排序，然后从前到后遍历，则当前的工人成本就是最大成本
使用大顶堆保存此前K个最小的quality值，如果使用当前工人，总成本最小是 单位成本*sum(堆)，更新堆顶

### 代码

```java
class Solution {
    public double mincostToHireWorkers(int[] quality, int[] wage, int K) {
        int len = wage.length;
        double[][] nums = new double[len][2];
        //计算单位成本
        for(int i=0 ; i<len ; i++){
            nums[i][0] = wage[i]*1.0/quality[i];
            nums[i][1] = quality[i];
        }
        //根据单位成本从低到高排序
        Comparator<double[]> comp = new Comparator<double[]>(){
            public int compare(double[] a,double[] b){
                return a[0] > b[0] ? 1 : (a[0]==b[0] ? 0 : -1) ;
            }
        };
        Arrays.sort(nums,comp);
        
        double sum = 0;
        double res = 0;
        //大顶堆
        Comparator<Double> comp2 = new Comparator<Double>(){
            public int compare(Double a,Double b){
                return a < b ? 1 : (a==b ? 0 : -1) ;
            }
        };
        PriorityQueue<Double> queue = new PriorityQueue<>(comp2);
        //先计算前K个值
        for(int i=0 ; i<K ; i++){
            sum += nums[i][1];
            queue.offer(nums[i][1]);
        }
        //从K+1开始遍历，更新堆，求最小值
        res = nums[K-1][0] * sum;
        for(int i=K ; i<len ; i++){
            if(nums[i][1] < queue.peek()){               
                sum = sum - queue.poll() + nums[i][1]; 
                queue.offer(nums[i][1]);
                res = Math.min(sum*nums[i][0],res);
            }
        }
        return res;
    }
}
```