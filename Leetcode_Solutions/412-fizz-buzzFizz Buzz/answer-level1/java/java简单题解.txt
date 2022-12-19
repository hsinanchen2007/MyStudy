```
class Solution {
    List<String> ret = new ArrayList<>();
    public List<String> fizzBuzz(int n) {
        if (n == 0) {
            Collections.reverse(ret);
            return ret;
        }

        if (n % 3 == 0 && n % 5 == 0) {
            ret.add("FizzBuzz");
        } else if (n % 3 == 0) {
            ret.add("Fizz");
        } else if (n % 5 == 0) {
            ret.add("Buzz");
        } else {
            ret.add(n + "");
        }

        return fizzBuzz(n - 1);
    }
}
```
