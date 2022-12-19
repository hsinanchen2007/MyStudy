### 利用快速排序对数组里面的数进行 数位比较 的排序，最后转换成字符串
```
class Solution {
    public String minNumber(int[] nums) {
        quickSortByDit(nums);
        StringBuilder builder = new StringBuilder();
        for (int num:
             nums) {
            builder.append(num);
        }
        return builder.toString();
    }

    /*调用对比位序方法取代比较数值，进行快速排序*/
    public void quickSortByDit(int[] arr){
        quickSortByDit(arr, 0, arr.length-1);
    }

    private void quickSortByDit(int[] arr, int low, int high){
        if (low >= high)   return;
        int pivot = partition(arr, low, high);        //将数组分为两部分
        quickSortByDit(arr, low, pivot - 1);                   //递归排序左子数组
        quickSortByDit(arr, pivot + 1, high);                  //递归排序右子数组
    }

    private int partition(int[] arr, int low, int high){
        int pivot = arr[low];     //基准，保存初始arr[low]值
        while (low < high){
            while (low < high && compareByDit(arr[high] , pivot) != -1) {
                high--;
            }
            arr[low] = arr[high];             //交换比基准大的记录到左端
            while (low < high && compareByDit(arr[low] ,pivot) != 1) {
                low++;
            }
            arr[high] = arr[low];           //交换比基准小的记录到右端
        }
        //此时low=high，扫描完成，基准到位，填坑
        arr[low] = pivot;
        //返回的是基准的位置
        return low;
    }

    /**
     * 不可以直接将a+b与b+a拼接后比较谁应该在前
     * 因为输入用例很大，拼接后字符串有可能会转换成int范围大的数
     * 对比整数 a 和 b 按位序对比，返回 1 0 -1 ，对应 a应该在后，在前，相同，三种情况
     */
    public int compareByDit(int a ,int b){
        String sa = String.valueOf(a);
        String sb = String.valueOf(b);
        int slen = Math.min(sa.length(), sb.length());
        //循环对比那一位开始谁更小
        for(int i =0 ; i < slen ; i++ ) {
            if(sa.charAt(i) != sb.charAt(i)) {
                if(sa.charAt(i) > sb.charAt(i)) return 1;
                else return -1;
            } else  {
                if(i==slen-1 && sa.length() != sb.length()) {
                        if(sa.length() > sb.length()) sb = sa.substring(i+1)+sb;
                        else sa = sb.substring(i+1) + sa;
                        if(Integer.parseInt(sa) > Integer.parseInt(sb)) return -1; //将较长整数剩余部分移到较短整数开头，比较数值
                        else return 1;   // 12 与 121 返回 1，因为12112更小
                    }
                }
            }
        
        return 0;
    }
}
```
