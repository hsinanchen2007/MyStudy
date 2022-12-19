### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int thirdMax(int[] nums) {
       ArrayList<Integer> list=new ArrayList<>();
       for(int i=0;i<nums.length;i++){
           if(!list.contains(nums[i]))
           list.add(nums[i]);
       }
       if(list.size()==2)
        return list.get(0)>list.get(1)?list.get(0):list.get(1);
       else if(list.size()==1)return list.get(0);
       PriorityQueue<Integer> largeK = new PriorityQueue<Integer>(3);
                for(int i=0;i<list.size();i++){
                    largeK.add(list.get(i));
                    if (largeK.size() > 3) {
                        largeK.poll();
                    }
                }
                return largeK.peek(); 
    }
}
```