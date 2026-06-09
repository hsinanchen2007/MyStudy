### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    class myComparator implements Comparator<int[]>{
        @Override
        public int compare(int[] a, int[] b){
            if(a[0] < b[0]){
                return 1;
            }
            else if(a[0] > b[0]){
                return -1;
            }
            else{
                if(a[1] > b[1]){
                    return 1;
                }
                else if(a[1] < b[1]){
                    return -1;
                }
                else{
                    return 0;
                }
            }
        }
    }
    public int[][] reconstructQueue(int[][] people) {
        // 先排个高的人
        Arrays.sort(people, new myComparator());
        List<int[]> list = new ArrayList<>();

        for(int i = 0; i < people.length; i++){
            int[] person = people[i];
            list.add(person[1], person);
        }

        return list.toArray(new int[people.length][2]);

        
        
    }
}
```