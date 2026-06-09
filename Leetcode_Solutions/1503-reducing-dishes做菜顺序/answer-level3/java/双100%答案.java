sum<0时的那个菜就是最后抛弃的菜
```
public int maxSatisfaction(int[] satisfaction) {
    Arrays.sort(satisfaction);
    int n = satisfaction.length;
    int sum = 0;
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (sum + satisfaction[i] > 0) {
            sum += satisfaction[i];
            ans += sum;
        } else {
            break;
        }
    }
    return ans;
}
```
