### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean verifyPostorder(int[] postorder) {
        return verify(postorder, 0, postorder.length - 1);
    }

    private boolean verify(int[] data, int left, int right){
        if(left >= right){
            return true;
        }
        int index;
        for(index = left; index < right; index++){
            if(data[index] >= data[right]){
                break;
            }
        }
        System.out.print(index);
        for(int i = index; i < right; i++){
            if(data[i] <= data[right]){
                return false;
            }
        }
        return verify(data, left, index-1) && verify(data, index, right-1);
    }
}
```