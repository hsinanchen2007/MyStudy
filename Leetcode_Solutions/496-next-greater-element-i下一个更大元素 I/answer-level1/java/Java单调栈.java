题目无重复数字，且nums1是nums2的子集，根据nums2建单调栈将每个数对应的结果存入Map，根据nums1遍历
```
class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        int[] ans = new int[nums1.length];
        HashMap<Integer, Integer> map = new HashMap<>();
        Stack<Integer> s = new Stack<>();
        for(int i = nums2.length - 1;i >= 0;i--){
            while(!s.isEmpty() && nums2[i] >= s.peek()){
                s.pop();
            }
            map.put(nums2[i], s.isEmpty() ? -1 : s.peek());
            s.push(nums2[i]);
        }
        for(int j = 0 ;j < nums1.length;j++){
            ans[j] = map.get(nums1[j]);
        }
        return ans;
    }
}
```
