JAVA:
执行用时 :5 ms, 在所有 Java 提交中击败了100.00% 的用户

内存消耗 :46 MB, 在所有 Java 提交中击败了100.00%的用户
```dart
class Solution {
    public int maxDistance(List<List<Integer>> arrays) {
        
        // 单次遍历, 用四个列表分别存储最大的两个列表和最小的两个列表
        List<Integer> minList1 = arrays.get(0);
        List<Integer> minList2 = arrays.get(1);
        
        if(minList1.get(0) > minList2.get(0)){
            minList1 = arrays.get(1);
            minList2 = arrays.get(0);
        }
        
        int min1 = minList1.get(0);
        int min2 = minList2.get(0);
        
        List<Integer> maxList1 = arrays.get(0);
        List<Integer> maxList2 = arrays.get(1);
        
        if(maxList1.get(maxList1.size() - 1) <  maxList2.get(maxList2.size() - 1)){
            maxList1 = arrays.get(1);
            maxList2 = arrays.get(0);
        }
        
        int max1 = maxList1.get(maxList1.size() - 1);
        int max2 = maxList2.get(maxList2.size() - 1);        
        
        for(int i = 2 ; i < arrays.size() ; i++ ){
            List<Integer> list = arrays.get(i);
            
            int min = list.get(0);
            int max = list.get(list.size() - 1);
            
            if(min < min1){
                minList2 = minList1;
                min2 = min1;
                minList1 = list;
                min1 = min;
            }else if(min < min2){
                minList2 = list;
                min2 = min;
            }
            
            if(max > max1){
                maxList2 = maxList1;
                max2 = max1;
                maxList1 = list;
                max1 = max;
            }else if(max > max2){
                maxList2 = list;
                max2 = max;
            }
            
        }
        
        // 如果最大的列表和最小的列表是同一个,则需要用第二大和第二小的分别计算
        if(maxList1 == minList1){
            return Math.max(
                max1 - min2,
                max2 - min1
            );
            
        }else{
            return max1 - min1;
        }
    }
}

```