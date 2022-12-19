```
class Solution {
    public int[][] reconstructQueue(int[][] people) {
        if (people == null || people.length == 0 || people[0] == null || people[0].length == 0) {
            return new int[0][];
        }
        List<int[]> result = new ArrayList<>();
        Arrays.sort(people, (e1, e2) -> (e1[0] != e2[0] ? e2[0] - e1[0] : e1[1] - e2[1]));
        for (int[] person : people) {
            result.add(person[1], person);
        }
        return result.toArray(new int[0][]);
    }
}
```
