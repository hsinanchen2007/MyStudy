### 解题思路
双重循环，时间复杂度O(n^2)

### 代码

```java
class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
                int [] res=new int[nums1.length];
        ArrayList<Integer> arrlist_nums2=new ArrayList<>();
        for(int n2:nums2){
            arrlist_nums2.add(n2);
        }
        for(int i=0;i<nums1.length;i++){
            int index_of_nums2=arrlist_nums2.indexOf(nums1[i]);
            boolean isfind=false;
            for(int j=index_of_nums2;j<arrlist_nums2.size();j++){
                
                if(arrlist_nums2.get(j)>nums1[i]){
                    isfind=true;
                    res[i]=arrlist_nums2.get(j);
                    break;
                }
            }
            if(isfind==false){
                res[i]=-1;
            }

        }
        return res;
    }
}
```