令巨无霸汉堡的数量为total_jumbo，小皇堡的数量为total_small，则有以下二元一次方程组：
4 × total_jumbo + 2 × total_small = tomatoSlices
total_jumbo + total_small = cheeseSlices
这个二元一次方程组一定有唯一解，但是未必有非负整数解，而题目要求的是非负整数解，只有当解是非负整数解时才应该返回，否则应返回[]。
显然tomatoSlices为偶数时才可能有整数解，因此如果tomatoSlices为奇数则直接返回[]。
然后就可以根据二元一次方程组的算法计算得到total_jumbo和total_small，可以保证得到的解是整数，再判断是不是非负整数解，如果是非负整数解则返回，否则返回[]。
```
class Solution {
    public List<Integer> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        List<Integer> numbers = new ArrayList<Integer>();
        if (tomatoSlices % 2 != 0)
            return numbers;
        int halfTomatoSlices = tomatoSlices / 2;
        int totalJumbo = halfTomatoSlices - cheeseSlices;
        int totalSmall = cheeseSlices * 2 - halfTomatoSlices;
        if (totalJumbo >= 0 && totalSmall >= 0) {
            numbers.add(totalJumbo);
            numbers.add(totalSmall);
        }
        return numbers;
    }
}
```
