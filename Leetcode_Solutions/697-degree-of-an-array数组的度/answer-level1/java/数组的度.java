### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int findShortestSubArray(int[] nums) {
        Map<Integer, Help> map = new HashMap<>();
        for(int i = 0; i < nums.length; i++){
            if(!map.containsKey(nums[i])){
                map.put(nums[i], new Help(1, i, i));
            }
            else{
                Help h = map.get(nums[i]);
                map.put(nums[i], new Help(h.cnt+1, h.startIndex, i));
            }
        }
        int max = 0;
        int shortest = Integer.MAX_VALUE;
        for(Integer key : map.keySet()){
            Help h = map.get(key);
            if(h.cnt > max){
                max = h.cnt;
                shortest = h.endIndex - h.startIndex + 1;
            }
            else if(h.cnt == max){
                shortest = (h.endIndex - h.startIndex + 1) < shortest?
                        (h.endIndex - h.startIndex + 1) : shortest; 

            }
        }

        return shortest;

    }

    class Help{
        private int cnt;
        private int startIndex;
        private int endIndex;

        public Help(int cnt, int startIndex, int endIndex){
            this.cnt = cnt;
            this.startIndex = startIndex;
            this.endIndex = endIndex;
        }
    }
    
        
        
}
```