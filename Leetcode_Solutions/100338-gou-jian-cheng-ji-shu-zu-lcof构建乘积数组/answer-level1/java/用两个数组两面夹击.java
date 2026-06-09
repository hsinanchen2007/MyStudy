### 解题思路
用两个数组两面夹击

### 代码

```java
class Solution {
    public int[] constructArr(int[] a) {
        if(a==null||a.length<=0){
            return new int[0];
        }
        int[] left=new int[a.length];
        int[] right=new int[a.length];
        left[0]=a[0];
        right[a.length-1]=a[a.length-1];
        for(int i=1;i<a.length-1;i++){
            left[i]=left[i-1]*a[i];
            right[a.length-1-i]=right[a.length-1-i+1]*a[a.length-1-i];
        }
        int[] ans = new int[a.length];
        ans[0]=right[1];
        ans[a.length-1]=left[a.length-1-1];
        for(int i=1;i<a.length-1;i++){
            ans[i]=left[i-1]*right[i+1];
        }
        return ans;
    }
}
```