impl Solution {
    pub fn replace_space(s: String) -> String {
        let mut ret = String::new();
        let v: Vec<&str> = s.split(' ').collect();
        ret += v[0];

        for i in 1..v.len() {
            ret += "%20";
            ret += v[i];
        }

        ret
    }
}