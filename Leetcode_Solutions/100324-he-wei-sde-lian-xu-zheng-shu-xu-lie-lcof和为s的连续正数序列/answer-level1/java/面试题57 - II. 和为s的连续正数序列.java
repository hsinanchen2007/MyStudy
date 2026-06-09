### 解题思路
暴力破解

### 代码

```java
class Solution {
    public int[][] findContinuousSequence(int target) {
       if(target<3)
            return null;
       
        //暴力破解
        int[] arr=new int[target/2+1];
        for(int i=0;i<arr.length;i++){
            arr[i]=i+1;
        }
        List<int[]> list=new ArrayList<int[]>();
        for(int j=0;j<arr.length;j++){
            int sum=0;
            for(int k=j;k<arr.length;k++){
                sum+=arr[k];
                if(sum==target){
                    list.add(Arrays.copyOfRange(arr,j,k+1));
                    break;
                }
                if(sum>target){
                    break;
                }
            }
        }
        int[][] res=new int[list.size()][arr.length];
        for(int i=0;i<list.size();i++){
            res[i]=list.get(i);
        }
        return res;
    }
}
```