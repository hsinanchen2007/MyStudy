## 排序的稳定性
稳定性排序：冒泡排序，插入排序、归并排序、基数排序
不稳定性排序：选择排序、快速排序、希尔排序、堆排序

## 1. 冒泡排序
**思路**
依次比较相邻的两个数，将较小的数放在前面，较大的数放在后面，一轮比较后，最后一个数为第一大的数，经过n-1轮比较调整后，数组升序排列。
**复杂度**：n个数据排序
(1)数组逆序时，要经过n-1趟排序，第i趟排序中比较次数为n-i次，找到第i大的数，总的比较次数为n(n-1)/2=O(n\*n),记录移动次数为3*n(n-1)/2=O(n\*n)。
(2)数组正序时，排序趟数为1，比较次数为n-1，时间复杂度为O(n)。
平均时间复杂度为O(n\*n)。
**代码**
```
public int[] BubbleSort(int[] nums) {
        for(int i=0; i<nums.length-1; i++){ //n-i趟排序
            for(int j=0; j<nums.length-1-i; j++){   //n-i次比较
                if(nums[j] > nums[j+1]){    //判断是否交换
                    int temp = nums[j+1];
                    nums[j+1] = nums[j];
                    nums[j] = temp;
                }
            }
        }
        return nums;
}
```
**优化**
排序过程中，如果某一趟排序中未发生交换操作，说明数组已经有序，没有必要继续排序。当最后一次比较的位置为i时，则说明i之后的元素也是有序的。因此，设置flag变量用于判断一趟排序中是否发生狡猾，如果没有直接返回结果；设置pos变量记录每一趟排序中最后一次交换的位置，在下一趟排序中，只需要比较0-pos位置的元素即可，pos之后的元素必是有序的。
```
 public int[] sortArray(int[] nums) {
        int pos = 0;    //记录最后一次发生交换的位置
        int len = nums.length-1;    //每轮比较的长度
        for(int i=0; i<nums.length-1; i++){ //n-i趟排序   
            int flag = 0;   //判断该轮是否发生交换
            for(int j=0; j<len; j++){   //n-i次比较
                if(nums[j] > nums[j+1]){    //判断是否交换
                    int temp = nums[j+1];
                    nums[j+1] = nums[j];
                    nums[j] = temp;
                    flag = 1;   
                    pos = j;
                }
            }
            if(flag == 0){
                return nums;
            }
            len = pos;  //最后一次发生交换的位置传给len，缩减下一轮比较的长度
        }
        return nums;
}
```

## 2. 选择排序
**思路**
n个元素分为有序区[0~i-1]和无序区[i~n]，每趟排序从i到n中选择最小的元素放到第i的位置上，则前i个数有序，进行n-1趟排序后数组升序。
**复杂度**
在最好和最坏情况下，都需要遍历和选择无序区最小元素的操作，时间复杂度都是O(n*n)。
**代码**
```
public int[] SelectSort(int[] nums) {
        for(int i=0; i<nums.length; i++){
            int minIndex = i;   //无序区最小元素的下标，初始化为无序区的第一个元素
            for(int j=i; j<nums.length; j++){
                if(nums[j] < nums[minIndex]){   //如果有更小的元素，交换下标给minIndex
                    minIndex = j;
                }
            }
            if(i != k){ //如果无序区第一个元素不是最小的，则进行交换
                int temp = nums[minIndex];
                nums[minIndex] = nums[i];
                nums[i] = temp; 
            }
            
        }
        return nums;
}
```
**优化**
可以考虑在每趟排序中，同时找到无序区的最大和最小元素，最小元素放到无序区开头，最大元素放到无序区结尾位置。
**代码**
```
public int[] SelectSort(int[] nums) {
       int left = 0;    //设置left和right分别为无序区的上下边界
       int right = nums.length-1;

       while(left < right){
           int minIndex = left; //记录无序区中最小最大元素的位置
           int maxIndex = right;
           for(int i=left; i<=right; i++){ //遍历无序区，找到最小最大元素的位置
               if(nums[i] < nums[minIndex]){
                   minIndex = i;
               }
               if(nums[i] > nums[maxIndex]){
                   maxIndex = i;
               }
           }
           if(minIndex != left){
               int temp = nums[left];
               nums[left] = nums[minIndex];
               nums[minIndex] = temp;
           }
            //这里很重要，如果最大元素下标是left,前面已经和最小元素交换了，此时最大元素下标应该是min
           if(maxIndex == left){
               maxIndex = minIndex;
           }
           if(maxIndex != right){
               int temp = nums[right];
               nums[right] = nums[maxIndex];
               nums[maxIndex] = temp;
           }
           left++;
           right--;
       }
       return nums;
    }
```

## 3. 插入排序
**思路**
遍历数组，对于当前元素i，[0~i-1]为有序区，遍历有序区，找到第一个小于i的元素j的位置，由于是数组，需要将j后方的元素依次后移一位，空出合适的位置，然后将i插入到j之后，即j<i<j+1，将i插入到有序区中。
**复杂度**
在最坏情况下，数组完全逆序，插入第2个元素时要考察前1个元素，插入第3个元素时，要考虑前2个元素，...，插入第N个元素，要考虑前 N - 1 个元素。时间复杂度为O(n*n)。
最好情况下，数组已经是有序的，每插入一个元素，只需要考查前一个元素，时间复杂度为O(n)。
平均时间复杂度为O(n\*n)。
```
 public int[] Insertsort(int[] nums) {
        for(int i=1; i<nums.length; i++){
            int temp = nums[i]; //记录当前元素
            int j=i;
            for(;j>0&&nums[j-1]>temp; j--){ //从当前元素开始向前找到合适位置并空出该位置
                nums[j] = nums[j-1];
            }
            nums[j] = temp; //插入元素
        }
        return nums;
    }
```

## 4. 归并排序
**思路**
采用分治的思想，将数组划分为前后两部分，对于两部分的元素，做归并。
归并过程工作原理如下：
第一步：申请空间，使其大小为两个已经排序序列之和，该空间用来存放合并后的序列
第二步：设定两个指针，最初位置分别为两个已经排序序列的起始位置
第三步：比较两个指针所指向的元素，选择相对小的元素放入到合并空间，并移动指针到下一位置
重复步骤3直到某一指针超出序列尾
将另一序列剩下的所有元素直接复制到合并序列尾
**复杂度**
n个元素每次进行二路归并分为两部分，需要进行logn次归并，每轮归并中要进行n次比较。
时间复杂度为O(nlogn)。
**代码**
```
public static int[] MergeSort(int[] nums, int low, int high){
        int mid = (low + high)/2;   //对数组从中间划分
        if(low < high){ //分别对划分的两部分进行递归排序，结果进行归并
            MergeSort(nums, low, mid);
            MergeSort(nums, mid+1, high);
            Merge(nums, low, mid, high);
        }
        return nums;
    }

    public static void Merge(int[] nums, int low, int mid, int high){
        int[] temp = new int[high-low+1];
        int i = low;
        int j = mid + 1;
        int k = 0;
        //一次比较前后两部分的数据，将较小的元素加入到结果数组中
        while(i<=mid && j<=high){
           if (nums[i] <= nums[j]) {  
                temp[k++] = nums[i++];  
            } else {  
                temp[k++] = nums[j++];  
            }  
        }
        //剩余其他数据加入到结果数组尾，有且仅有一部分数据有剩余
        while(i <= mid){
            temp[k++] = nums[i++];
        }
        while(j <= high){
            temp[k++] = nums[j++];
        }
        //将结果数组复制到原数组中
        for(k=0; k<temp.length; k++){
            nums[low+k] = temp[k];
        }
    }
```








 