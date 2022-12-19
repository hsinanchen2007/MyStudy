### 解题思路
此处撰写解题思路
直接插入操作即可

### 代码

```java
class Solution {
    public int[] createTargetArray(int[] nums, int[] index) {
        int []temp = new int[nums.length];
        int i  = 0;
        while(i < nums.length){
            insert(temp , index[i] , nums[i]);
            i++;
        }
        return temp;
    }
    public void insert(int [] dataTemp , int index , int data){
        for(int i = dataTemp.length - 1; i > index;i -- ){
            dataTemp[i] = dataTemp[i - 1];
        }
        dataTemp[index] = data;
    }
}
```