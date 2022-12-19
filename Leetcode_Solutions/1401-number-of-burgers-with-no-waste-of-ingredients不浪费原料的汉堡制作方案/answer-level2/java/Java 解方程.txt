```
class Solution {
    public List<Integer> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        List<Integer> result = new ArrayList<>();
        if (tomatoSlices % 2 != 0 || tomatoSlices > 4 * cheeseSlices || tomatoSlices < 2 * cheeseSlices) {
            return result;
        }
        int bigBurgers = tomatoSlices / 2 - cheeseSlices;
        int smallBurgers = cheeseSlices - bigBurgers;
        result.add(bigBurgers);
        result.add(smallBurgers);
        return result;
    }
}
```
