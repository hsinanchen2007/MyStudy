这题给的二维数组是乱序的，直接是用双指针返回第一个合适的值不一定是最小值，此时需要将两个数组排序
这里直接是用了Comparator来自定义排序，这样就能保证获取到的第一个所需的数据是最小的
还有优化空间，可是我懒了(^_−)☆
~~~Java
class Solution {
    public List<Integer> minAvailableDuration(int[][] slots1, int[][] slots2, int duration) {
        int size_1 = slots1.length;
        int size_2 = slots2.length;
        int i=0;
        int j=0;
        int min_left = 0;
        int min_right = 0;
        int max_left = 0;
        int max_right = 0;
        Arrays.sort(slots1,new Comparator<int[]>() {
            public int compare(int[] o1, int[] o2) {
            return o1[0]-(o2[0]);
            }
        });
        Arrays.sort(slots2,new Comparator<int[]>() {
            public int compare(int[] o1, int[] o2) {
            return o1[0]-(o2[0]);
            }
        });
        List<Integer> result = new ArrayList<>();
        while(i<size_1 && j<size_2){
            min_left = Math.min(slots1[i][0],slots2[j][0]);
            max_left = Math.max(slots1[i][0],slots2[j][0]);
            min_right = Math.min(slots1[i][1],slots2[j][1]);
            max_right = Math.max(slots1[i][1],slots2[j][1]);
            if(max_left <= min_right){
                if(min_right - max_left >= duration){
                    result.add(max_left);
                    result.add(max_left+duration);
                    return result;
                }
                if(slots1[i][1] > slots2[j][1]){
                    j++;
                }else if(slots1[i][1] < slots2[j][1]){
                    i++;
                }else{
                    j++;
                    i++;
                }
            }else if(max_left == slots1[i][0]){
                j++;
            }else if(max_left == slots2[j][0]){
                i++;
            }
        }
        return result;
    }
}
~~~