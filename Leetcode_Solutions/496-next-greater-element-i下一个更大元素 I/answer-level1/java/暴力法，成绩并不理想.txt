### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        Map<Integer,Integer>map = new HashMap<Integer, Integer>();
        int i=0,j=0;
        for( i=0;i<nums2.length;i++){
            for(j=i+1;j<nums2.length;j++){
                if(nums2[j]>nums2[i]){
                    map.put(nums2[i],nums2[j]);
                    break;
                }
            }
            if(j==nums2.length){
                map.put(nums2[i],-1);
            }
        }

        int re[]=new int[nums1.length];
        for(i=0;i<re.length;i++){
            re[i]=map.get(nums1[i]);
        }

        return re;
    }
}
```