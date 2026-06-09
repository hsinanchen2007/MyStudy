### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<Integer> sortArray(int[] nums) {
        if(nums.length==0) return new ArrayList<Integer>();
        //bubbleSort(nums);
        //chooseSort(nums);
        //insertSort(nums);
        //shellSort(nums);
        //nums = mergeSort(nums);
        //fastSort(nums,0,nums.length-1);
        //heapSort(nums);
        countSort(nums);

        List<Integer> result = toList(nums);
        return result;
    }

//////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////
    public void countSort(int[] nums){
        int min = nums[0];
        int max = nums[0];
        for(int i=0;i<nums.length;i++){
            if(max<nums[i]) max = nums[i];
            else if(min>nums[i]) min = nums[i];
        }
        int range = max-min+1;
        int bias = 0-min;

        int[] count = new int[range];
        for(int i=0;i<nums.length;i++){
            count[nums[i]+bias]++;
        }
        for(int i=0,j=0;i<range;i++){
            while(count[i]>0){
                nums[j] = i-bias;
                j++;
                count[i]--;
            }
        }
    }
//////////////////////////////////////////////////////////////////////////////////////
    public void heapSort(int[] nums){
        if(nums.length<=1) return;
        heap_maxHeap(nums,nums.length);
        for(int i=nums.length-1;i>0;i--){
            swap(nums,0,i);//每次把根和最后一个没排序的交换
            heap_changeToMaxRootHeap(nums,0,i);//交换后的排序成最大堆
        }
    }
//把堆变成最大堆
    public void heap_maxHeap(int[] nums,int length){
        for(int i=length/2-1;i>=0;i--){//从枝往根换，保证根比底下都大
            heap_changeToMaxRootHeap(nums,i,length);
        }
    }
//把一个仅根不满足最大堆的堆变成最大堆，因此可以利用最大堆特性
    public void heap_changeToMaxRootHeap(int[] nums,int root,int length){
        if(root*2+2<=length-1&&nums[root]<nums[root*2+2]&&nums[root*2+1]<nums[root*2+2]){//存在右节点且右节点是三个点最大，需要交换右节点
            swap(nums,root,root*2+2);
            heap_changeToMaxRootHeap(nums,root*2+2,length);
            return;
        }
        if(root*2+1<=length-1&&nums[root]<nums[root*2+1]){//存在左节点，左节点比根节点大，交换（此时要么没有右节点，要么右节点小于等于左键点）
            swap(nums,root,root*2+1);
            heap_changeToMaxRootHeap(nums,root*2+1,length);
        }
    }
//////////////////////////////////////////////////////////////////////////////////////
    public void fastSort(int[] nums,int left,int right){
        if(left>=right) return;

        int smallIndex = left;
        int standard = nums[left];

        for(int i=left;i<=right;i++){
            if(nums[i]<standard){
                swap(nums,i,smallIndex+1);
                smallIndex++;
            }
        }
        swap(nums,left,smallIndex);
        fastSort(nums,left,smallIndex-1);
        fastSort(nums,smallIndex+1,right);
    }
//////////////////////////////////////////////////////////////////////////////////////
//用复制新数组方法的归并
    public int[] mergeSort(int[] nums){
        if(nums.length<=1) return nums;
        int mid = (nums.length-1)/2;
        int[] leftArray = Arrays.copyOfRange(nums,0,mid+1);
        int[] rightArray = Arrays.copyOfRange(nums,mid+1,nums.length);

        return mergeSort_mergeArray(mergeSort(leftArray),mergeSort(rightArray));
    }
    public int[] mergeSort_mergeArray(int[] nums1,int[] nums2){
        int n1 = 0;
        int n2 = 0;
        int[] result = new int[nums1.length+nums2.length];
        for(int i=0;i<nums1.length+nums2.length;i++){
            if(n2>=nums2.length){
                result[i] = nums1[n1];
                n1++;
            }else if(n1<nums1.length&&nums1[n1]<=nums2[n2]){
                result[i] = nums1[n1];
                n1++;
            }else{
                result[i] = nums2[n2];
                n2++;
            }
        }
        return result;
    }
//////////////////////////////////////////////////////////////////////////////////////
    public void shellSort(int[] nums){
        int gap = nums.length/2;
        while(gap>=1){//要排好多次
            for(int i=0;i<gap;i++){//每次一共有gap个待排序数组
            //开始插入排序
                for(int j=i+gap;j<nums.length;j+=gap){
                    for(int k=j;k>=gap;k-=gap){
                        if(nums[k]<nums[k-gap]){
                            swap(nums,k,k-gap);
                        }else break;
                    }
                }
            }//结束插入排序
            gap/=2;
        }
    }
//////////////////////////////////////////////////////////////////////////////////////
    public void insertSort(int[] nums){
        for(int i=1;i<nums.length;i++){
            for(int j=i;j>0;j--){
                if(nums[j]<nums[j-1]){
                    swap(nums,j,j-1);
                }else{
                    break;
                }
            }
        }
    }
//////////////////////////////////////////////////////////////////////////////////////
    public void chooseSort(int[] nums){
        for(int i=0;i<nums.length;i++){
            int curMin = nums[i];
            int curMinIndex = i;
            for(int j=i+1;j<nums.length;j++){
                if(nums[j]<curMin){
                    curMin = nums[j];
                    curMinIndex = j;
                }
            }
            swap(nums,i,curMinIndex);
        }
    }
//////////////////////////////////////////////////////////////////////////////////////
    public void bubbleSort(int[] nums){
        for(int i=0;i<nums.length;i++){
            for(int j=0;j<nums.length-i-1;j++){//j的上限要注意
                if(nums[j]>nums[j+1]) swap(nums,j,j+1);
            }
        }
    }
//////////////////////////////////////////////////////////////////////////////////////
    public void swap(int[] nums,int a,int b){
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }
    public List<Integer> toList(int[] nums){
        List<Integer> list = new ArrayList<>();
        for(int i=0;i<nums.length;i++){
            list.add(nums[i]);
        }
        return list;
    }
}
```