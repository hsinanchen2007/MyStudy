### 解题思路
遍历时找出右边最大值和它的下标，通过下标判断是否需要找最大值

### 代码

```java
class Solution {
    public int[] replaceElements(int[] arr) {
        //用来保存右边最大值和右边最大值的下标
        int max = 0,index = 0;
        //循环遍历
        for(int i=0; i<arr.length; i++){
            //最后一个元素，直接赋 -1，跳出循环
            if(i == arr.length -1){
                arr[i] = -1;
                break;
            }
            //判断最大值下标是否大于当前坐标，大于直接赋值，不用再找最大值
            if(index > i){
                arr[i] = max;
                continue;
            }
            //初始化
            max = 0;
            index = 0;
            for(int j=i+1; j<arr.length; j++){
                //找右边最大值和右边最大值下标
                if(arr[j] >= max){
                    max = arr[j];
                    index = j;
                }
            }
            //替换
            arr[i] = max;
        }
        return arr;
    }
}
```