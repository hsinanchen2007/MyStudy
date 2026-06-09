### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {
        List<Integer> res = new ArrayList<>();
        Map<Integer,Integer> hm = new HashMap<>();
        for(int num:nums){
            if(hm.containsKey(num)){
                hm.put(num,hm.get(num)+1);
            }else{
                hm.put(num,1);
            }
        }

        List<Integer>[] list = new List[nums.length+1];
        for(int key:hm.keySet()){
            int i = hm.get(key);
            if(list[i]==null){
                list[i] = new ArrayList<>();
            }
            list[i].add(key);
        }

        for(int i=list.length-1;i>=0&&res.size()<k;i--){
            if(list[i]==null){
                continue;
            }
            res.addAll(list[i]);
        }

        return res;
    }
}
```