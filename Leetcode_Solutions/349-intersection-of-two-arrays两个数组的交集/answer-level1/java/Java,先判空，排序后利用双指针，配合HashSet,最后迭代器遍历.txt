执行用时 :3 ms, 在所有 Java 提交中击败了97.50%的用户
内存消耗 :36.6 MB, 在所有 Java 提交中击败了53.88%的用户
```
class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        if (nums1.length == 0){
            return nums1;
        }
        if (nums2.length == 0){
            return nums2;
        }

    Arrays.sort(nums1);Arrays.sort(nums2);
    HashSet<Integer> hs = new HashSet<Integer>();
    int p1 = 0; int p2 = 0;
        while (p1 < nums1.length && p2 < nums2.length){
            if (nums1[p1] < nums2[p2]){
                p1++;
            }else if(nums1[p1] > nums2[p2]){
                p2++;
            }else{
                hs.add(nums1[p1]);
                p1++;
                p2++;
            }
                
        }
        int [] ans = new int [hs.size()];
	    Iterator it = hs.iterator();
	        int p = 0;
	        while(it.hasNext()){
	            ans[p++] = (Integer)it.next();
	        }
	        
	    
	    return ans;
    }
}

```
