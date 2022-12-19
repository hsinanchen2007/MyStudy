这道题的突破点在于 maxChoosableNumber <= 20。我们在进行取数游戏的过程中，由于某个数取了之后就不能取，因此需要记住之前的状态，即哪些取了哪些没取。由于数最大就20，因此我们可以用二进制的第i位为1还是0来表示数字i有没有被取过。因此可以用一个整数x来存储状态。另一方面，这个游戏是累加所取的数，看谁先让累加值大于desire。我们可以发现，只要取了a b c三个数，不论顺序是啥，它们的和就确定了为a+b+c。也就是说x除了可以表示哪些数取了，还能同时表示目前已经累加到多少了。举个例子，x等于6，对应二进制就是110，也就意味着2和3已经被取过了，其它数都没取过。既然取了2和3，也就说明当前累加到了5。因此一个x可以包含很多信息量。
另一方面，x=6代表2和3都被取了，累加到5。假设你是先手，不论你先取3还是先取2，都无所谓了，因为现在已经累加到5了，而且又该你取了。
换句话说，x确定了，那么取了哪些数、该谁了、累加到多少了，这些都确定了，和x怎么是怎么达成的无关，也就是动态规划所谓的无后效性。

因此，我们可以用f[i]来代表如果走到了i代表的状态，那么先手会赢还是输。

代码如下：
```rust
impl Solution {
    pub fn can_i_win(max_choosable_integer: i32, desired_total: i32) -> bool {
        let can_reach = (max_choosable_integer+1)*max_choosable_integer/2;
        if can_reach < desired_total {
            return false;
        }
        if can_reach == desired_total {
            return max_choosable_integer&1 == 1;
        }
        let mut f = vec![None; 1<<(max_choosable_integer as usize)];
        Self::dfs(0, max_choosable_integer, desired_total, &mut f)
    }
    fn dfs(cur: i32, range: i32, target: i32, f: &mut Vec<Option<bool>>) -> bool {
        // cur代表current的状态，range是可以取的最大的数，target是我们累加的目标
        let ucur = cur as usize;
        if let Some(ok) = f[ucur] {
            return ok;
        }
        for i in (1..=range).rev() {
            // 枚举接下来取哪个数
            let cur_bit = 1<<(i-1);
            // 如果这个数没被取过
            if cur & cur_bit == 0 {
                // 如果直接取就能达成目标，取它就完事儿了
                // 或者，如果我取了i，然后该另一个人取数了，并且他输了，那么我就赢了
                if i >= target || !Self::dfs(cur | cur_bit, range, target-i, f) {
                    f[ucur] = Some(true);
                    return true;
                }
            }
        }
        // 怎么取都赢不了，那我就输了
        f[ucur] = Some(false);
        false
    }
}
```