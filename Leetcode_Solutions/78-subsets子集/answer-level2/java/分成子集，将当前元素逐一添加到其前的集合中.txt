### 解题思路
参考别人在评论区发表的提示编写算法
创建一个添加空的子集的result后，而后遍历数组将其中的每个元素都添加在其之前元素的集合中；
即若**当前result中已有前i个元素的子集，得到第i + 1个元素后，对result进行遍历分别将第i+1个元素添加到其中即可**，即`addSubSets`方法完成该操作！！！

### 代码

```java
class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        if(nums == null) return result;
        List<Integer> everyResult = new ArrayList<>();
        result.add(everyResult);
        for(int i : nums){
            addSubSets(result, i);
        }
        return result;
    }

    public void addSubSets( List<List<Integer>> result, int value){
        int size = result.size();
        for(int i = 0; i < size; i ++){
            List<Integer> temp = new ArrayList<>(result.get(i));
            temp.add(value);
            result.add(temp);
        }
    }
}
```