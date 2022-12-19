执行用时 :9 ms, 在所有 java 提交中击败了92.53% 的用户
内存消耗 :39.2 MB, 在所有 java 提交中击败了100.00%的用户
```
class Solution {
    class peopleCompare implements Comparator<int[]>{
        public int compare(int[] o1, int[] o2){
            return o1[0] == o2[0] ? o1[1]-o2[1] : o2[0]-o1[0];
        }
    }
    public int[][] reconstructQueue(int[][] people) {
        if(people == null || people.length < 2 || people[0].length < 2)
            return people;
        Arrays.sort(people,new peopleCompare());
        LinkedList<int[]> list = new LinkedList();
        for(int[] nums : people){
            list.add(nums[1],nums);
        }
        return list.toArray(new int[list.size()][2]);
    }
}
```
