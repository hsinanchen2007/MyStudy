### 解题思路
HashMap 解决

### 代码

```java
class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        HashMap<Integer,Integer> map = new HashMap<>();
        for(int i:nums1){
            if(map.get(i)==null){
                map.put(i,1);
            }else {
                map.put(i,map.get(i)+1);
            }
        }
        int[] res = new int[nums1.length];
        int index = 0;
        for(int i:nums2){
            Integer j = map.get(i);
            if(j!=null && j>0){
                res[index++] = i;
                map.put(i,j-1);     //防止添加多余的
            }
        }
        return Arrays.copyOf(res,index);
    }
}
```