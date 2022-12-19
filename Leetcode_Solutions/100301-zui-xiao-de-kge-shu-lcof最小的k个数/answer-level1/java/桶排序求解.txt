### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
        if (k==arr.length){
            return arr;
        }

        if (k==0){
            return new int[0];
        }
        int[] count=new int[10001];

        for (int i : arr) {
            count[i]++;
        }
        
        int[] result=new int[k];
        int index=0;
        for (int i = 0; i < count.length; i++) {
            if (count[i]==0){
                continue;
            }
            
            while (count[i]>0&&index!=k){
                result[index]=i;
                index++;
                count[i]--;
            }
            
            if (index==k){
                break;
            }
        }
        
        return result;
    }
}
```