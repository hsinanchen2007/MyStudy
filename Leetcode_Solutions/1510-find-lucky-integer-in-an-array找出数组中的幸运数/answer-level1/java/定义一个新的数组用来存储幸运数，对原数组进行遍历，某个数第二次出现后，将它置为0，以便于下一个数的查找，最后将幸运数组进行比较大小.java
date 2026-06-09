### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int findLucky(int[] arr) {
        int[] lucky=new int[100];
        int k=0;
        for(int i=0;i<arr.length;i++){
            if(arr[i]==0)
                continue;
            int flag=1;
            for(int j=i+1;j<arr.length;j++){
                if(arr[i]==arr[j]){
                    flag++;
                    arr[j]=0;
                }
            }
            if(arr[i]==flag){
                lucky[k]=flag;
                k++;
            }
        }
        int max=lucky[0];
        if(lucky[0]!=0){
            for(int i=1;i<lucky.length&&lucky[i]!=0;i++){
                if(max<lucky[i]){
                    max=lucky[i];
                }
            }
        }else{
            max=-1;
        }
        return max;
    }
}
```