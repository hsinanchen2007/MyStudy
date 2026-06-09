```
class Solution {
    public void rotate(int[] nums, int k) {
        ArrayDeque<Integer> deque1 = new ArrayDeque<Integer>();
        for(int i = 0; i < nums.length; i++){
            deque1.add(nums[i]);
        }
        Integer temp = new Integer(1);
        while(k > 0){
            temp = deque1.getLast();
            deque1.removeLast();
            deque1.addFirst(temp);
            k--;
        }
        System.out.println(deque1);
        for(int i = 0; i < nums.length; i++){
            nums[i] = deque1.pop();
        }
    }
}
```