class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
  return Arrays.stream(nums1).flatMap(i-> Arrays.stream(nums2).filter(a-> a!=i?false:true)).distinct().toArray();
    }
}