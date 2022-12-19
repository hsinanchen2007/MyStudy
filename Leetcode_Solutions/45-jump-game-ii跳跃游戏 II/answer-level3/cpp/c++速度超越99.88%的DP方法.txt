a保存上一步能到达最远处，b保存当前步能到达最远处。
j为当前步数，
每当当前位置大于a能到达的位置，步数加一，a更新为b。
b每次更新完判断是否可以跳出，时间复杂度O(n),空间复杂度O(1)。
```
int n = nums.size();
if(n == 1) return 0;
if(nums[0] >= n-1) return 1;
int j = 2, a = nums[0], b = nums[0];
for(int i = 1; i < n; i++) {
    if(i > a) a=b, j++;
    if(i + nums[i] > b) {
        b = i + nums[i];
        if(b >= n-1) break;
    }
}
return j;
```
