### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int findSpecialInteger(int[] arr) {
        int len = arr.length;
        if (len == 1){
            return arr[0];
        }
        double threshold = len * 0.25;
        Map<Integer,Integer> map = new HashMap<Integer, Integer>();
        for (int i =0;i < len;i++){
            int key = arr[i];
            Set<Integer> keySet = map.keySet();
            if (keySet.contains(key)){
                //map中已经有这个数字了
                int count = map.get(key);
                count++;
                if (count > threshold){
                    return key;
                }
                map.put(key,count);
            }else {
                //map中没有这个数字
                map.put(key,1);
            }
        }
        return -1;//表示未找到
    }
}
```