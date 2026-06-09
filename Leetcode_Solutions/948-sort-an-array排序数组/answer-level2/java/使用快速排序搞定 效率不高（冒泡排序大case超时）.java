### 解题思路
此处撰写解题思路
本来偷懒用冒泡排序 发现一个大的case超时 没法搞
        int temp;        
        for(int i=0;i<nums.length;i++){
            for(int j=0;j<nums.length-i-1;j++){
                if(nums[j]>nums[j+1]){
                    temp=nums[j];
                    nums[j]=nums[j+1];
                    nums[j+1]=temp;
                   
                }
            }
        }

放弃了 使用了下面的 快速排序搞定 不过效率还是比较低下

### 代码

```java
class Solution {
    public List<Integer> sortArray(int[] nums) {        
     quickSort(nums,0,nums.length-1);
     List<Integer> listdata=new ArrayList<Integer>(nums.length);
      for(int m=0;m<nums.length;m++){
          listdata.add(nums[m]);
      }  
      return listdata;

    }

    public static void quickSort(int[] array,int left,int right){
        if(left>right){
            return ;
        }
        int i=left;
        int j=array.length-1;
        int base=array[left];//基准数据
        while(i!=j){//相等终止条件
            while(i<j&&array[j]>=base){ //从右边找到比base小的数据
                j--;
            }
            while(i<j&&array[i]<=base){ //从左边找到比base大的数据
                i++;
            }
            if(i<j){ //交换彼此的位置
                int temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }

        }
        //基准数据归位
        array[left]= array[i];
        array[i]=base;

        //分别从左右两边 再次排序
        quickSort(array,left,i-1);
        quickSort(array,i+1,right);
    }

    

}
```