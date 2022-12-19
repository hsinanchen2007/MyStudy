HashMap+两层for循环 
执行用时 :3 ms, 在所有 Java 提交中击败了96.71%的用户
内存消耗 :39.6 MB, 在所有 Java 提交中击败了5.64%的用户
感觉自己写的有点笨比的意思
附上代码
class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        int n = nums1.length;
        int[] res = new int[n];
        boolean flag;
        Map<Integer,Integer> map = new HashMap<>(); 
        for(int i = 0;i < nums2.length;i ++){
            map.put(nums2[i],i);
        }
        for(int i = 0;i < nums1.length;i ++){
            flag = false;
            int index = map.get(nums1[i]);
            for(;index < nums2.length;index ++){
                    if(nums2[index] > nums1[i]){
                        res[i] = nums2[index];
                        flag = true;
                        break;
                    }
            }
            if(!flag){
                res[i] = -1;
            }
        }
        return res;
    }
}