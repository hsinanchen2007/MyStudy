```
class Solution {
    public int trap(int[] height) {
        int sum = 0;
        //存储所有水槽的边的下标
        List<Integer> list = new LinkedList<>();
        // 递增或递减的标识
        boolean flag = true;
        for(int i = 0;i < height.length-1;i++){
            if(height[i+1] < height[i]){
                // 当从递增转化为递减时，此时下标是某个水槽边的下标,并将加入list中
                if(flag){
                    int size = list.size();
                    // 合并多个小水槽，使之成为一个大水槽
                    while(size > 1){
                      int last = height[list.get(size - 1)];
                        int secondLast = height[list.get(size - 2)];
                        if(last < secondLast && last <= height[i]){
                            list.remove(size - 1);
                            size--;
                        }
                        else
                            break;
                    }
                    list.add(i);
                }
                flag = false;
            }
            else{
                flag = true;
            }
        }
        if(flag){
            int size = list.size();
            while(size > 1){
              int last = height[list.get(size - 1)];
                int secondLast = height[list.get(size - 2)];
                if(last < secondLast && last <= height[height.length-1]){
                    list.remove(size - 1);
                    size--;
                }
                else
                    break;
            }
            list.add(height.length-1);
        }
        // 水槽边的下标全部计算完毕
        
        Integer[] array = list.toArray(new Integer[list.size()]);
        
        for(int i = 1;i < array.length;i++){
            // 决定能装多少水的是最小的水槽边的高度
            int min = Math.min(height[array[i-1]],height[array[i]]);
            for(int j = array[i-1]+1;j < array[i];j++){
                if(height[j] < min)
                    sum += min - height[j];
            }
        }
        return sum;
    }
}
```
