![奇怪的知识增加了.jpg](https://pic.leetcode-cn.com/e363c014a0082ac035456c68a033369e93ebe3577a2151fdc524eed245caadb5-%E5%A5%87%E6%80%AA%E7%9A%84%E7%9F%A5%E8%AF%86%E5%A2%9E%E5%8A%A0%E4%BA%86.jpg)


### 代码

```java
class Solution {
    public boolean verifyPostorder(int[] postorder) {
        int len = postorder.length;
        return method(postorder, 0, len-1);
    }
    public boolean method(int [] arr, int i, int j){
        if(i >= j) return true;
        int tmp = i;
        while(arr[tmp]<arr[j]){
            tmp ++;
        }
        for(int k = tmp; k <j; k++){
            if(arr[k]<arr[j]) return false;
        }
        return method(arr, i, tmp-1) && method(arr, tmp,j-1);
    }

}
```