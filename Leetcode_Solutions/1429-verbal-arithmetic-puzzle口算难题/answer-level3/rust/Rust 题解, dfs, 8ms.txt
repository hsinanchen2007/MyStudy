

思路：从个位开始判断，如果个位能满足条件再判断十位，直到所有位满足条件

注意处理前导0



```rust
impl Solution {
    pub fn is_solvable(words: Vec<String>, result: String) -> bool {
        let mut v: Vec<Vec<usize>> = Vec::new();
        for i in 0..words.len() {
            v.push(vec![]);
            for c in words[i].chars().rev() {
                v[i].push(c as usize - 'A' as usize);
            }
        }
        let mut res: Vec<usize> = Vec::new();
        for c in result.chars().rev() {
            res.push(c as usize - 'A' as usize);
        }
        let mut map: [i32; 26] = [-1; 26];
        let mut vis: [bool; 10] = [false; 10];
        fn dfs(x: usize, y: usize, add: usize, map: &mut [i32; 26], vis: &mut [bool; 10], v: &Vec<Vec<usize>>, res: &Vec<usize>) -> bool {
            if y == res.len() { return true; }
            if y >= v[x].len() || map[v[x][y]] != -1 {
                let mut i: usize = 0; if y < v[x].len() { i = map[v[x][y]] as usize; }
                if !(i == 0 && y == v[x].len() - 1) {
                    let t = (add + i) % 10;
                    if x == v.len() - 1 {
                        if !(y + 1 == res.len() && add + i == 0) {
                            if map[res[y]] == -1 {
                                if !vis[t] {
                                    map[res[y]] = t as i32; vis[t] = true;
                                    if dfs(0, y + 1, (add + i) / 10, map, vis, v, res) { return true; }
                                    map[res[y]] = -1; vis[t] = false;
                                }
                            } else if t == map[res[y]] as usize {
                                if dfs(0, y + 1, (add + i) / 10, map, vis, v, res) { return true; }
                            }
                        }
                    } else {
                        if dfs(x + 1, y, add + i, map, vis, v, res) { return true; }
                    }
                }
            } else {
                for i in 0..10 {
                    if vis[i] { continue; }
                    if !(i == 0 && y == v[x].len() - 1) {
                        map[v[x][y]] = i as i32; vis[i] = true;
                        let t = (add + i) % 10;
                        if x == v.len() - 1 {
                            if !(y + 1 == res.len() && add + i == 0) {
                                if map[res[y]] == -1 {
                                    if !vis[t] {
                                        map[res[y]] = t as i32; vis[t] = true;
                                        if dfs(0, y + 1, (add + i) / 10, map, vis, v, res) { return true; }
                                        map[res[y]] = -1; vis[t] = false;
                                    }
                                } else if t == map[res[y]] as usize {
                                    if dfs(0, y + 1, (add + i) / 10, map, vis, v, res) { return true; }
                                }
                            }
                        } else {
                            if dfs(x + 1, y, add + i, map, vis, v, res) { return true; }
                        }
                        map[v[x][y]] = -1; vis[i] = false;
                    }
                }
            }
            return false;
        }
        dfs(0, 0, 0, &mut map, &mut vis, &v, &res)
    }
}
```
