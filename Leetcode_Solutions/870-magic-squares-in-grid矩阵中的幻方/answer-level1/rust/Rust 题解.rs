```
use std::collections::HashSet;
impl Solution {
    pub fn num_magic_squares_inside(grid: Vec<Vec<i32>>) -> i32 {
        let rowcount = grid.len();
        let colcount = grid[0].len();
        let a = grid;
        if rowcount < 3 || colcount < 3 {
            return 0;
        }
        let mut amount = 0;
        for i in 0..rowcount {
            for j in 0..colcount {
                if a.get(i+2)!=None && a[i+2].get(j+2)!=None {
                    let mut tempv = HashSet::new();     // 利用集合元素的不可重复特点
                    for k in 0..9 {
                        if a[i+k/3][j+k%3]!=0 && a[i+k/3][j+k%3]<10 {
                            tempv.insert(a[i+k/3][j+k%3]);  
                        }
                    }
                    if tempv.len() != 9 {       // 保证子矩阵的元素是 1-9 且不重复
                        continue;
                    }
                    let temp1 = a[i][j]+a[i][j+1]+a[i][j+2];
                    let temp2 = a[i+1][j]+a[i+1][j+1]+a[i+1][j+2];
                    let temp3 = a[i+2][j]+a[i+2][j+1]+a[i+2][j+2];
                    let temp4 = a[i][j]+a[i+1][j]+a[i+2][j];
                    let temp5 = a[i][j+1]+a[i+1][j+1]+a[i+2][j+1];
                    let temp6 = a[i][j+2]+a[i+1][j+2]+a[i+2][j+2];
                    let temp7 = a[i][j]+a[i+1][j+1]+a[i+2][j+2];
                    let temp8 = a[i][j+2]+a[i+1][j+1]+a[i+2][j];

                    if temp1==temp2 && temp2==temp3 && temp3==temp4 && temp4==temp5 && temp5==temp6 && temp6==temp7 && temp7==temp8 {
                        amount += 1;
                    }
                }
            }
        }
        amount
    }
}
```

![image.png](https://pic.leetcode-cn.com/8d8758c9fa53c47d7c96b0ad4ab6621c34f1affda17470e720046720665e0550-image.png)
