### 解题思路
每次都是菜鸟解题：暴力。
要注意arr长度的判断。

### 代码

```java
class Solution {
    public int[] replaceElements(int[] arr) {
        if(arr.length==0)  return null;
        if(arr.length==1) {
            arr[0]=-1;
            return arr;
        }
        if(arr.length==2) {
            arr[0]=arr[1];
            arr[1]=-1;
            return arr;
        }
        for(int i=0;i<arr.length-1;i++){
            int max=-1;
	for(int j=i+2;j<arr.length;j++) {
	    if(arr[j]>arr[i+1]) max=Math.max(max, arr[j]);
	    else max=Math.max(max, arr[i+1]);
	}
         arr[i]=max;
        }
        arr[arr.length-2]=arr[arr.length-1];
        arr[arr.length-1]=-1;
        return arr;
    }
}
```