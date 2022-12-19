BFS，队列记录状态

一个状态包含
1. 箱子的位置
2. 人在箱子的方向

从当前队列的每一个状态，可以得到相邻的 4 个新方位，以及到达新方位所需要的人的位置。
用 UnionFind 算法判断箱子挡住当前一个位置时，人的旧位置和新位置在图中是否联通。
如果联通，可到达，加入新的队列。

状态一共不超过 row * col * 4 种，BFS的复杂度为 O(n^2 x 4) 每次判断联通的复杂度大概是 O(n^2)，一共 O(4 x n^4)

```
struct UnionFinder {
  root: Vec<usize>,
  size: Vec<i32>,
}

impl UnionFinder {
  fn new(size: usize) -> UnionFinder {
    UnionFinder {
      root: (0..size).collect(),
      size: vec![1; size],
    }
  }

  fn get_root(&mut self, mut idx: usize) -> usize {
    while idx != self.root[idx] {
      self.root[idx] = self.root[self.root[idx]];
      idx = self.root[idx];
    }
    idx
  }

  fn union(&mut self, idx_a: usize, idx_b: usize) {
    let root_a = self.get_root(idx_a);
    let root_b = self.get_root(idx_b);
    if root_a == root_b {
      return;
    }
    if self.size[root_a] < self.size[root_b] {
      self.root[root_b] = root_a;
      self.size[root_a] += self.size[root_b];
    } else {
      self.root[root_a] = root_b;
      self.size[root_b] += self.size[root_a];
    }
  }
}

impl Solution {
  pub fn min_push_box(mut grid: Vec<Vec<char>>) -> i32 {
    let mut player_start_pos = None;
    let mut box_start_pos = None;
    let mut box_target_pos = None;
    for r in 0..grid.len() {
      for c in 0..grid[0].len() {
        match grid[r][c] {
          'B' => {
            box_start_pos = Some((r, c));
            grid[r][c] = '.'; // reset as '.'
          },
          'T' => {
            box_target_pos = Some((r, c));
            grid[r][c] = '.'; // reset as '.'
          },
          'S' => {
            player_start_pos = Some((r, c));
            grid[r][c] = '.'; // reset as '.'
          },
          _ => (),
        }
      }
    }
    let player_start_pos = player_start_pos.expect("player_start_pos exist");
    let box_start_pos = box_start_pos.expect("box_start_pos exist");
    let box_target_pos = box_target_pos.expect("box_target_pos exist");

    #[derive(Copy, Clone, Debug, PartialEq, Eq)]
    enum Di { Left, Right, Up, Down };
    impl Di {
      fn reverse(&self) -> Di {
        match self {
          Di::Left => Di::Right,
          Di::Right => Di::Left,
          Di::Up => Di::Down,
          Di::Down => Di::Up,
        }
      }
    }
    type Pos = (usize, usize);

    fn get_free_neighbour(grid: &Vec<Vec<char>>, (r, c): Pos) -> Vec<(Pos, Di)> {
      [(-1,0,Di::Up), (1,0,Di::Down), (0,-1,Di::Left), (0,1,Di::Right)].into_iter().filter_map(|&(d_r, d_c, di)| {
        let (nb_r, nb_c) = (r as i32 + d_r, c as i32 + d_c);
        if 0 <= nb_r && nb_r < grid.len() as i32 && 0 <= nb_c && nb_c < grid[0].len() as i32 {
          if grid[nb_r as usize][nb_c as usize] == '#' {
            None
          } else {
            Some(((nb_r as usize, nb_c as usize), di))
          }
        } else {
          None
        }
      }).collect()
    }

    fn can_reach(grid: &Vec<Vec<char>>, box_pos: Pos, pos_a: Pos, pos_b: Pos) -> bool {
      let (rows, cols) = (grid.len(), grid[0].len());
      let mut uf = UnionFinder::new(rows * cols);
      for r in 0..rows {
        for c in 0..cols {
          if grid[r][c] == '#' || (r, c) == box_pos { continue; }
          let idx = r * cols + c;
          for ((nb_r, nb_c), _) in get_free_neighbour(grid, (r, c)) {
            if (nb_r, nb_c) == box_pos { continue; }
            let nb_idx = nb_r * cols + nb_c;
            uf.union(idx, nb_idx);
          }
        }
      }
      uf.get_root(pos_a.0 * cols + pos_a.1) == uf.get_root(pos_b.0 * cols + pos_b.1)
    }

    #[derive(Debug)]
    struct Status {
      box_pos: Pos,
      player_di: Di,
    }
    impl Status {
      fn get_prev_player_pos(&self, rows: usize, cols: usize) -> Option<Pos> {
        let r = self.box_pos.0 as i32;
        let c = self.box_pos.1 as i32;
        let (res_r, res_c) = match self.player_di {
          Di::Left => (r, c - 2),
          Di::Right => (r, c + 2),
          Di::Up => (r - 2, c),
          Di::Down => (r + 2, c),
        };
        if 0 <= res_r && res_r < rows as i32 && 0 <= res_c && res_c < cols as i32 {
          Some((res_r as usize, res_c as usize))
        } else {
          None
        }
      }
      fn get_player_pos(&self) -> Pos {
        let (r, c) = self.box_pos;
        match self.player_di {
          Di::Left => (r, c - 1),
          Di::Right => (r, c + 1),
          Di::Up => (r - 1, c),
          Di::Down => (r + 1, c),
        }
      }
    }
    let mut step = 0;
    let mut queue: Vec<Status> = vec![];
    let mut is_visited = vec![vec![[false; 4]; grid[0].len()]; grid.len()];
    for (player_stand_pos, player_di) in get_free_neighbour(&grid, box_start_pos) {
      if can_reach(&grid, box_start_pos, player_stand_pos, player_start_pos) {
        queue.push(Status {
          box_pos: box_start_pos,
          player_di,
        });
        is_visited[box_start_pos.0][box_start_pos.1][player_di as usize] = true;
      }
    }
    // println!("{:?}", queue);
    while !queue.is_empty() {
      let mut next_queue: Vec<Status> = vec![];
      for status in queue {
        for (new_box_pos, nb_di) in get_free_neighbour(&grid, status.box_pos) {
          let (nb_box_r, nb_box_c) = new_box_pos;
          let new_player_di = nb_di.reverse();
          if is_visited[nb_box_r][nb_box_c][new_player_di as usize] {
            continue;
          }
          let new_status = Status {
            box_pos: new_box_pos,
            player_di: new_player_di,
          };
          // if we want to move box from status.box_pos to new_box_pos
          // we must be sure that player can reach appropriate position from its current position
          // println!("\t {:?} -> {:?}", status, new_status);
          if let Some(player_stand_pos) = new_status.get_prev_player_pos(grid.len(), grid[0].len()) {
            if can_reach(&grid, status.box_pos, status.get_player_pos(), player_stand_pos) {
              if new_box_pos == box_target_pos {
                return step + 1;
              }
              is_visited[nb_box_r][nb_box_c][new_player_di as usize] = true;
              next_queue.push(new_status);
            }
          }
        }
      }
      step += 1;
      queue = next_queue;
      // println!("{:?}", queue);
    }
    -1
  }
}
```
