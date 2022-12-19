class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        int max=arr1[0],min=arr1[0];
        int alen=arr1.length,blen=arr2.length;
        for(int i=1;i<alen;i++){
            if(arr1[i] > max){
                max = arr1[i];
            }
            if(arr1[i] < min){
                min = arr1[i];
            }
        }
        int temp[]=new int[max-min+1];
        for(int i=0;i<alen;i++){
            temp[arr1[i]-min]++;
        }
        int count=0,index=0;
        for(int i=0;i<blen;i++){
            count=temp[arr2[i]-min];
            while(count>0){
                arr1[index++]=arr2[i];
                count--;
            }
            temp[arr2[i]-min]=0;
        }
        for(int i=0; i<temp.length; i++){
            count=temp[i];
            while(count>0){
                arr1[index++]=i+min;
                count--;
            }
             temp[i]=0;
        }
        return arr1;
    }        
}

这个可以说是桶排序，第一个for是为了开辟数组内存在arr1的数字范围
第二个for是将按照arr2进行排序
第三个for是为了拿出桶内存在的数字（已排序）
