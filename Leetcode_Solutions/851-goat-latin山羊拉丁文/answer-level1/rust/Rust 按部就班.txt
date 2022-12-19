```
impl Solution {
    pub fn to_goat_latin(s: String) -> String {
        let mut s = s;
        let v = ["a", "e", "i", "o", "u", "A", "E", "I", "O", "U"];
        let mut launch = String::new();
        fn word_transform_step1(s: &mut String) {
            // move first char to end
            let tmp = s.remove(0_usize);
            s.push(tmp);
        }

        fn word_transform_step2(s: &mut String){
            // append ma
            s.push_str("ma");
        }

        fn word_transform_step3(s: &mut String, n:usize) {
            // append a
            for i in 0..n+1 {
                s.push('a');
            }
        }
        let mut vs: Vec<&str> = s.split(' ').collect();
        for (index, &word) in vs.iter().enumerate() {
            let mut word = String::from(word);
            if !v.contains(&word.get(0..1).unwrap()) {
                word_transform_step1(&mut word);
            };
            word_transform_step2(&mut word);
            word_transform_step3(&mut word, index);
            launch = launch + word.as_str();
            if index != vs.len()-1 {
                launch += " ";
            }
        }
        launch
    }
}
```
