换了个好几个数字，想起这个搞事的数字. 心情大好 (. y .)
```
impl Solution {
    // https://www.strchr.com/hash_functions
     fn hash_word(s: &[u8]) -> usize {
        let mut hash: usize = 0xB16B00B5;
        let m: usize = 33;
        for i in 0..s.len() {
            hash = m ^ hash * s[i] as usize;
        }
        hash
    }
    pub fn find_substring(s: String, words: Vec<String>) -> Vec<i32> {
        let mut ret = vec![];
        let len = words.len();
        if s.len() == 0 || len == 0 || s.len() < words[0].len() * len  {
            return ret;
        }
        let word_len = words[0].len();
        let mut words_hash: usize = 0;
        for word in words.into_iter() {
            words_hash += Self::hash_word(word.as_bytes());
        }
        let sb = s.as_bytes();
        for i in 0..(sb.len() - word_len * len + 1) {
            let mut tmp_hash: usize = 0;
            for j in 0..len {
                tmp_hash += Self::hash_word(&sb[(i + j * word_len)..(i + (j + 1) * word_len)]);
            }
            if tmp_hash == words_hash {
                ret.push(i as i32);
            }
        }
        ret
    }
}
```
