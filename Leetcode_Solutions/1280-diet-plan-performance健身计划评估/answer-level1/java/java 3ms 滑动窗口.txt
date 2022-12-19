```
    public int dietPlanPerformance(int[] calories, int k, int lower, int upper) {
        int res = 0, sum = 0;
        for (int i = 0; i < k; i++)
            sum += calories[i];
        if (sum < lower) res--;
        else if (sum > upper) res++;
        for (int i = k; i < calories.length; i++) {
            sum += calories[i] - calories[i - k];
            if (sum < lower) res--;
            else if (sum > upper) res++;
        }
        return res;
    }
```
