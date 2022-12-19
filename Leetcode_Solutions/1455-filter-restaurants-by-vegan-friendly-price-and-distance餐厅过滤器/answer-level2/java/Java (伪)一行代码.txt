```
class Solution {
  public List<Integer> filterRestaurants(int[][] restaurants, int veganFriendly, int maxPrice,
      int maxDistance) {
    return Arrays.stream(restaurants)
        .filter(
            x -> (veganFriendly == 1 ? x[2] == 1 : true) && x[3] <= maxPrice && x[4] <= maxDistance)
        .sorted(new Comparator<int[]>() {
          @Override
          public int compare(int[] i1, int[] i2) {
            return i1[1] == i2[1] ? i2[0] - i1[0] : i2[1] - i1[1];
          }
        }).mapToInt(x -> x[0]).boxed().collect(Collectors.toList());
  }
}
```
