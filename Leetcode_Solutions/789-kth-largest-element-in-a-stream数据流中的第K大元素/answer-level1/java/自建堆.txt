### 解题思路
自行建堆，然后进行堆排序，获得一个有序的数组，为啥感觉有点笨笨的，但是熟悉了堆的建立思路
建堆：从底（最后一个父节点）往上（根节点）寻找两个子节点的最大值并与父节点比较，比父大则交换，
    若交换则递归的将子节点作根所在的子树往下比较，维护堆结构，
堆排序，不停的将最大的堆顶与最后一个节点交换，然后往下递归的将根节点所在的子树往下比较，维护堆结构，
    

### 代码

```java
class KthLargest {
    List<Integer> list;
    int k;
    public KthLargest(int k, int[] nums) {
        this.k=k;
        List<Integer> list=new ArrayList<>();
        if(nums==null||nums.length==0) {
            this.list=list;
        	return;
        }
        if(nums.length<2){
            list.add(nums[0]);
            this.list=list;
        	return;
        }
        // 建堆一次
        createHeap(nums);
        
        int temp=nums[nums.length-1];
        nums[nums.length-1]=nums[0];
        nums[0]=temp;
        if(nums.length<3){
            list.add(nums[0]);
            list.add(nums[1]);
            this.list=list;
        	return;
        }
       
        for(int i=nums.length-2;i>0;i--){
            downShift(nums,0,i);
            int temp1=nums[i];
            nums[i]=nums[0];
            nums[0]=temp1;
            
        }
        for(int i=0;i<nums.length;i++){
            list.add(nums[i]);
        }
        this.list=list;
    }
    public void createHeap(int[] arr){
        if(arr.length<2){
            return;
        }
        // 建堆
        int lastFather=(arr.length-2)/2;
        for(int i=lastFather;i>=0;i--){
            int maxChild=2*i+1;
            if((2*i+2)<=(arr.length-1)){
                if(arr[2*i+1]<arr[2*i+2]){
                    maxChild=2*i+2;
                }
            }
            if(arr[maxChild]<=arr[i]){
                continue;
            }
            // 交换最大孩子与父节点
            int temp=arr[i];
            arr[i]=arr[maxChild];
            arr[maxChild]=temp;
            // 递归使得被交换的父节点所在子树为堆
            downShift(arr,maxChild,arr.length-1);
           
        }

    } 
    // 递归排好所有子节点
    public void downShift(int[] arr,int root,int last){
        if(2*root+1>last){
            return;
        }
        int maxChild=2*root+1;
        if((2*root+2<=last)&&(arr[maxChild]<arr[2*root+2])){
           maxChild=2*root+2;
        }
        if(arr[maxChild]<=arr[root]){
            return;
        }
        int temp=arr[maxChild];
        arr[maxChild]=arr[root];
        arr[root]=temp;
        downShift(arr,maxChild,last);
    }
    // 插入堆，然后调整
    public int add(int val) {
       int ori=list.size();
       if(ori==0){
           list.add(val);
           return list.get(list.size()-k);
       }
       for(int i=0;i<list.size();i++){
           if(list.get(i)>val){
               list.add(i,val);
               break;
           }
       }
       if(list.size()==ori){
           list.add(val);
       }
       return list.get(list.size()-k);
    }
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */
```