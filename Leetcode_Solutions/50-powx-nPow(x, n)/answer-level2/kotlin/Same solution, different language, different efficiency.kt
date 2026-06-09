Java solution: 
```
    public double myPow(double x, int n) {
        if (n < 0) {
            x = 1 / x;
        }
        return solv(x, n);
    }

    double solv(double x, int n) {
        if (n == 0) {
            return 1.0;
        }
        double value = solv(x, n / 2);
        if (n % 2 == 0) {
            return value * value;
        }
        return value * value * x;
    }
```

Java solution efficiency: 
**Runtime: 0 ms, faster than 100.00% of Java online submissions for Pow(x, n).
Memory Usage: 36.7 MB, less than 5.88% of Java online submissions for Pow(x, n).**

Kotlin solution: 
```
    fun myPow(x: Double, n: Int): Double {
        var xVal = x
        if (n < 0) {
            xVal = 1 / x
        }
        return recursivePow(xVal, n)
    }

    fun recursivePow(x: Double, n: Int): Double {
        if (n == 0) {
            return 1.0
        }
        val halfP = recursivePow(x, n / 2)
        return if (n and 1 == 1) halfP * halfP * x else halfP * halfP
    }
```
Kotlin solution efficiency: 
**Runtime: 148 ms, faster than 73.53% of Kotlin online submissions for Pow(x, n).
Memory Usage: 32 MB, less than 100.00% of Kotlin online submissions for Pow(x, n).**


**So, Java language is better in efficiency?**