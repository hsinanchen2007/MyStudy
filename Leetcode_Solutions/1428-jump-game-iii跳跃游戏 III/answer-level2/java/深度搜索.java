此题我采用的是深度优先搜索。从start点开始，向左或者向右两个方向，同时做个标记，这个标记不需要回溯，因为我们知道这个点到达不了的话无论是从左边来的还是从右边来的都到达不了。然后全部访问完毕没有找到那么就是没有找到了，返回false。希望看看各位大佬更好的办法
```
public class p5297 {
    @Test
    public void test(){
        int [] arr = {3,0,2,1,2};
        System.out.println(canReach(arr,2));
    }
    public boolean canReach(int[] arr, int start) {
        boolean [] flag = new boolean[arr.length];
        return sousuo(start,arr,flag);
    }
    public boolean sousuo(int start,int [] arr,boolean [] flag){
        if(arr[start] == 0)return true;
        int right = start+arr[start];
        int left = start-arr[start];
        if(right < arr.length){
            if(flag[right] == false){
                flag[right] = true;
                boolean rightFlag = sousuo(right,arr,flag);
                if(rightFlag)return rightFlag;
            }

        }
        if(left >= 0){
            if(flag[left] == false){
                flag[left] = true;
                boolean LeftFlag = sousuo(left,arr,flag);
                if(LeftFlag)return LeftFlag;
            }

        }
        return false;
    }
}
```
