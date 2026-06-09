//从第一个值开始，每次寻找最后一个比该值小的元素记录下标，在此下标往前寻找最大值，以最大值下标为基准向后寻找最后一个比最大值小的下标，如此反复，直到遍历完成。
class Solution {
    int count;
    public int maxChunksToSorted(int[] arr) {
        count=0;
        int i=0;
        int b;//记录子块的内的最大值
        while(i<arr.length){
            if(backMin(i,arr)==i){//子块长度为1，即只有一个元素
                    count++;
                    i++;
            }
            else {//子块长度确定
                    b=midMax(i,backMin(i,arr),arr);
                    i=backMin(b,arr)+1;
                    count++;
            }
        }
        return count;
    }
    //寻找所划分数组里面的最大值，找到返回下标，找不到返回本身
    public int midMax(int begain,int end,int[]a){
        for(int i=begain+1;i<end;i++){
            if(a[i]>a[begain])
            {
                begain=i;
            }
        }
        return begain;
    }
    //寻找到i后面最后一个比它本身小的下标，找到返回，找不到返回本身
    public int backMin(int index,int[]a){
        int max=a[index];
        if(index==a.length-1){
            return index;
        }else{
            for(int i=index+1;i<a.length;i++){
                if(max>a[i]){
                    index=i;
                }
            }
            return index;
        }
    }
}