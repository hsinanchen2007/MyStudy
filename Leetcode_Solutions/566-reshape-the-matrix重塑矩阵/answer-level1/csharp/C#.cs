```csharp
public int[][] MatrixReshape(int[][] nums, int r, int c) {
    if(nums == null || nums.Length < 1) return nums;
    int col = nums[0].Length;
    if(r * c != nums.Length * col) return nums;
    int[][] ans = new int[r][];
    int x = 0, y = 0;
    for(int i = 0; i < r; i++)
    {
        ans[i] = new int[c];
        for(int j = 0; j < c; j++)
        {
            ans[i][j] = nums[x][y];
            y++;
            if(y == col)
            {
                x++;
                y = 0;
            }
        }
    }
    return ans;
}
```