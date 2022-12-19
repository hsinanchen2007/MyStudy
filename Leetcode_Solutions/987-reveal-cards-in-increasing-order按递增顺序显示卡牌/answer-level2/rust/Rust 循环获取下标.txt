0 ms; 2.1 MB

没有想到逆推... 维护一个包含所有下标的 Vector, 每隔一个取出一个.
剩余的下标再重复这一步骤. 就能得到发牌时出现的顺序.
```rs
impl Solution {
    pub fn deck_revealed_increasing(deck: Vec<i32>) -> Vec<i32> {
        let n = deck.len();
        let mut indexs: Vec<usize> = (0..n).collect();
        let mut orders = Vec::with_capacity(n);
        
        fn indexs_to_orders(indexs: &mut Vec<usize>, orders: &mut Vec<usize>, start: usize) {
            if indexs.is_empty() {
                return ();
            }
            let mut cur = start;
            while cur < indexs.len() {
                orders.push(indexs[cur]);
                indexs[cur] = usize::max_value();
                cur += 2;
            }
            let start1 = if cur-2 == indexs.len()-1 {1} else {0};
            indexs.retain(|&x| x != usize::max_value());
            indexs_to_orders(indexs, orders, start1);
        }

        indexs_to_orders(&mut indexs, &mut orders, 0);
        let mut deck = deck;
        deck.sort();
        let mut result = vec![0;n];
        let mut j = 0;
        for i in orders {
            result[i] = deck[j];
            j += 1;
        }
        result
    }
}
```