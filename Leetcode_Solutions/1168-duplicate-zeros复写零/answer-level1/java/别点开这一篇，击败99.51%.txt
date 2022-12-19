### 解题思路
用clone方法还是偷懒了，讨论大家关注在“原地”这个点上

官方方法从0的数量入手，也是不错的选择

### 代码

```java
class Solution {
    public void duplicateZeros(int[] arr) {

        int[] temp = arr.clone();

        for(int index = 0, i = 0; index < temp.length ; i++, index++){
            if(temp[i] != 0){
                arr[index] = temp[i];
            }else{
                arr[index] = 0;
                if(index < temp.length - 1){
                    index++;
                    arr[index] = 0;
                }
            }
        }
    }
}
```