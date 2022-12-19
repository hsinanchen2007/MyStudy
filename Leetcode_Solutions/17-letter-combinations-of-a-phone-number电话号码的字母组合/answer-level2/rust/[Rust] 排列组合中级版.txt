0/2.1
```
impl Solution {
    pub fn letter_combinations(digits: String) -> Vec<String> {
        use std::collections::HashMap;
        let map: HashMap<char, Vec<char>> = [
            ('2', vec!['a', 'b', 'c']),
            ('3', vec!['d', 'e', 'f']),
            ('4', vec!['g', 'h', 'i']),
            ('5', vec!['j', 'k', 'l']),
            ('6', vec!['m', 'n', 'o']),
            ('7', vec!['p', 'q', 'r', 's']),
            ('8', vec!['t', 'u', 'v']),
            ('9', vec!['w', 'x', 'y', 'z']),
        ]
        .iter()
        .cloned()
        .collect();
        let digits_v: Vec<char> = digits.chars().collect();
        fn sub_combinations(mut chars: Vec<char>, map: &HashMap<char, Vec<char>>) -> Vec<String>  {
            if chars.len() == 0 {
                return vec![];
            }
            let ref char = chars.pop().unwrap();
            let sub_map = map.get(char).unwrap();
            let mut res = Vec::new();
            //println!("{:?}:{:?}", char, sub_map);
            for r#char in sub_map {
                let sub = sub_combinations(chars.clone(), &map);
                //println!("{:?},sub={:?}", r#char,sub);
                if sub.len() == 0 {
                    let mut tmp = String::new();
                    tmp.push(r#char.clone());
                    res.push(tmp);
                } else {
                    for mut sub_v in sub {
                        sub_v.push(r#char.clone());
                        res.push(sub_v);
                    }
                }
            }
            //println!("sub res={:?}",res);
            res
        }
        return sub_combinations(digits_v.clone(), &map);
    }
}
```
