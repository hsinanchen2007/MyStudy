class Solution {
    public int longestConsecutive(int[] nums) {
        if(nums.length==0)return 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for(int i = 0 ; i<nums.length;i++){
            pq.add(nums[i]);
        }
        int max = 1;
        int tmp = 1;
        int cur = pq.poll();
        while(!pq.isEmpty()){
            int curr = pq.poll();
            if(curr==cur){
                cur = curr;
                continue;
            }
            if(curr!=cur+1){
                tmp = 1;
                cur = curr;  
                continue;
            }
            tmp++;
            cur = curr;
            max = Math.max(max,tmp);
        }
        return max;
    }
}

O(n)时间复杂度
O(n)空间复杂度