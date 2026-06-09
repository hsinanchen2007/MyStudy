### 解题思路
用一个map存储key，判断是否包含*2或者/2的数，除以2时要判断是否为偶数。

### 代码

```java
class Solution {
    public boolean checkIfExist(int[] arr) {
        Map<Integer,Integer> map = new HashMap<>();
        for(int a : arr){
            if(map.containsKey(a*2)){
                return true;
            }else if(a%2==0&&map.containsKey(a/2)){
                return true;
            }else{
                map.put(a,1);
            }
        }
        return false;
    }
}
```