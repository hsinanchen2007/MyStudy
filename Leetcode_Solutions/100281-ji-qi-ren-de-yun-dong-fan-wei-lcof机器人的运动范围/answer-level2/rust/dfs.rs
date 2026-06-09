```rust
impl Solution {
    fn meet_spec(i: i32, j: i32, k: i32) -> bool {
        let mut sum = 0;
        let mut i = i;
        let mut j = j;

        while i > 0 {
            sum += i % 10;
            i = i / 10;
        }

        while j > 0 {
            sum += j % 10;
            j = j / 10;
        }

        sum <= k
    }

    fn moving_count_from_ij(
        m: i32,
        n: i32,
        k: i32,
        i: i32,
        j: i32,
        visited: &mut HashSet<(i32, i32)>,
    ) -> i32 {
        if i >= m || j >= n || visited.contains(&(i, j)) || !Solution::meet_spec(i, j, k) {
            return 0;
        }

        visited.insert((i, j));

        return 1
            + Solution::moving_count_from_ij(m, n, k, i + 1, j, visited)
            + Solution::moving_count_from_ij(m, n, k, i, j + 1, visited);
    }

    pub fn moving_count(m: i32, n: i32, k: i32) -> i32 {
        let mut visited: HashSet<(i32, i32)> = HashSet::new();

        Solution::moving_count_from_ij(m, n, k, 0, 0, &mut visited)
    }
}
```