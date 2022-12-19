### 解题思路
用TreeMap存储连续序列开始的索引和长度。

### 代码

```java
class Solution {
    public int[][] findContinuousSequence(int target) {
        //TreeMap记录开始索引和长度
        TreeMap<Integer,Integer> treeMap = new TreeMap<>();
        int left = 1;
        int right = 2;
        if(target < 2) return new int[1][1];
        while(left < (target+1)/2){
            int sum = 0;
            for(int i=left;i<=right;i++){
                //求得当前连续子序列的和
                sum += i;
            }
            if(sum == target){
                treeMap.put(left,right-left+1);
                left++;
            }else{
                if(sum > target) left++;
                if(sum < target) right++;
            }
        }
        //由哈希表恢复原数组
        int len = treeMap.size();
        int[][] res = new int[len][];
        int index = 0;
        for(Map.Entry<Integer,Integer> entry:treeMap.entrySet()){
            int start = entry.getKey();
            int subLen = entry.getValue();
            //每次进行entrySet的遍历，进行长度的赋值，以及数组的存储
            res[index] = new int[subLen];
            int j = 0;
            for(int i = start;i <= start+subLen-1;i++){
                res[index][j++] = i;
            }
            index++;
        }
        return res;
    }
}
```